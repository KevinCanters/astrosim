/* libraries */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <array>

/* custom headers */
#include "integrators.h"
#include "stl-operators.h"
#include "drivers.h"
#include "help-functions.h"
#include "fileio.h"

/* 4th order Runge-Kutta integrator */
void rungeKutta(valarray<Star> stars, valarray<Vec> (*driver)(const valarray<Vec>&, const valarray<double>&), const double endtime, const double timestep, const string& input_filename, const string& output_filename, const size_t print_skip) 
{ 
    valarray<double> masses = getMasses(stars);
    ofstream filestream;
    size_t print_index = 0;
    size_t progress_indicator = 0;
    size_t size = stars.size();
    double var_timestep;
    double init_energy = calcEnergy(stars);
    valarray<Vec> kx1(size), kx2(size), kx3(size), kx4(size);
    valarray<Vec> kv1(size), kv2(size), kv3(size), kv4(size);
    valarray<Vec> positions(size), velocities(size);

    filestream.open(output_filename, ios::out); 
    filestream << setprecision(12); 
    printInformation(filestream, input_filename, timestep, print_skip, "RK");
    printHeader(filestream, stars, 20);
    printToFile(filestream, 0.0, 0.0, stars, 20);  
    
    for (double t = timestep; t <= endtime; t += var_timestep) 
    {
     	var_timestep = timestep * min(1., calcMinDistance(stars));
        /* var_timestep = timestep; */
        positions = getPositions(stars);
        velocities = getVelocities(stars);
        kx1 = velocities; 
        kv1 = driver(positions, masses); 
        kx2 = velocities + 0.5 * var_timestep * kv1;
        kv2 = driver(positions + 0.5 * var_timestep * kx1, masses); 
        kx3 = velocities + 0.5 * var_timestep * kv2;
        kv3 = driver(positions + 0.5 * var_timestep * kx2, masses); 
        kx4 = velocities + var_timestep * kv3; 
        kv4 = driver(positions + var_timestep * kx3, masses);
        updateStars(stars, positions + (var_timestep / 6.) * (kx1 + 2. * kx2 + 2. * kx3 + kx4), velocities + (var_timestep / 6.) * (kv1 + 2. * kv2 + 2. * kv3 + kv4));

        /* print every print_skip'th iteration */
        print_index++;
        if (print_index % print_skip == 0)
        {
            double final_energy = calcEnergy(stars);
            printToFile(filestream, t, abs((init_energy - final_energy) / init_energy), stars, 20);
        }
        
        /* progress indicator every 10% */
        if (ceil((t / endtime) * 100) >= progress_indicator * 10)
        {
            cout << left << setw(4) << progress_indicator * 10 << "%\r";
            if (progress_indicator != 10)
            {
                cout.flush();
            }
            else
            {
                cout << endl;
            }
            progress_indicator++;
        }
    }
    filestream.close(); 
}

/* modified midpoint integrator for Gragg-Bulirsch-Stoer integrator */
valarray<Star> modifiedMidpoint(valarray<Star> stars, valarray<Vec> (*driver)(const valarray<Vec>&, const valarray<double>&), const double timestep, const size_t n)
{
    valarray<double> masses = getMasses(stars);
    double h = timestep / n;

    valarray<Vec> xi, xi_min, xi_plus;
    valarray<Vec> vi, vi_min, vi_plus;

    xi_min = getPositions(stars);
    vi_min = getVelocities(stars);
    xi = xi_min + h * vi_min;
    vi = vi_min + h * driver(xi_min, masses);

    for(size_t i = 0; i < n - 1; ++i) // loops n - 1 times, the first step is set above
    {
        xi_plus = xi_min + 2 * h * vi; 
        vi_plus = vi_min + 2 * h * driver(xi, masses);
        xi_min = xi;
        vi_min = vi;
        xi = xi_plus;
        vi = vi_plus;
    }

    updateStars(stars, 0.5 * (xi + xi_min + h * vi), 0.5 * (vi + vi_min + h * driver(xi, masses)));
    
    return stars;
}

void graggBulirschStoer(valarray<Star> stars, valarray<Vec> (*driver)(const valarray<Vec>&, const valarray<double>&), const double endtime, const double timestep, const string& input_filename, const string& output_filename, const size_t print_skip, const double criterium)
{
    ofstream filestream;
    double t = timestep * min(1., calcMinDistance(stars));
    double correction_factor = 1.0;
    double init_energy = calcEnergy(stars);
    size_t print_index = 0;
    size_t progress_indicator = 0;

    /* two rows of the T triangle */
    array<valarray<Star>, 8> lastrow;    
    array<valarray<Star>, 8> row;

    /* ANSI escape sequences for red */
    string red = "\033[0;31m";
    string der = "\033[0m";

    filestream.open(output_filename, ios::out);
    filestream << setprecision(12);
    printInformation(filestream, input_filename, timestep, print_skip, "GBS");
    printHeader(filestream, stars, 20);
    printToFile(filestream, 0.0, 0.0, stars, 20);
	
    while(t < endtime)
    {
        size_t j = 0;
        double convergence = 1;
     	/* double var_timestep = timestep * min(1., calcMinDistance(stars)) * correction_factor; */
        double var_timestep = timestep;

        /* check convergence and correct if necessary */
     	if(correction_factor < 1e-8)
     	{
     		cout << red + "Gragg-Bulirsch-Stör integration failed: correction_factor became too small: " + der << endl << correction_factor << endl;
     		break;
     	}

        /* integration */
        lastrow[0] = modifiedMidpoint(stars, driver, var_timestep, 2); // the first element of the T triangle or k = 0

        for(size_t k = 1; k < 8 && convergence > criterium; ++k)
        {
            row[0] = modifiedMidpoint(stars, driver, var_timestep, 2 * (k + 1));

			for(j = 0; j < k; ++j) 
            {
				row[j + 1] = row[j] + (row[j] - lastrow[j]) / (pow(double(k + 1) / double(k - j), 2) - 1);
			}
			convergence = calcConvergence(row, j - 1, j); // j has the same value as k after the loop because ++j is evaluated after the last iteration
			lastrow = row; // copy array
		}

        /* check convergence and correct if necessary */
	    if(convergence < criterium)
	    {	
        	updateStars(stars, getPositions(row[j]), getVelocities(row[j]));
        	t += var_timestep;
       		correction_factor = 1.0;
            /* print every print_skip'th iteration */
       		print_index++;
        	if (print_index % print_skip == 0)
        	{
                double final_energy = calcEnergy(stars);
                printToFile(filestream, t, abs((init_energy - final_energy) / init_energy), stars, 20); 
        	}
            /* progress indicator every 10% */
            if (ceil((t / endtime) * 100) >= progress_indicator * 10)
            {
                cout << left << setw(4) << progress_indicator * 10 << "%\r";
                if (progress_indicator != 10)
                {
                    cout.flush();
                }
                else
                {
                    cout << endl;
                }
                progress_indicator++;
            }
	    }

    	else
	    {
    		correction_factor /= 2.0;
	    }
    }
}
