/* libraries */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <valarray>
#include <vector>
#include <string>

/* custom headers */
#include "fileio.h"
#include "star.h"

using namespace std;

/* reads the initial conditions from a text file and puts them in a valarray of Stars */
valarray<Star> readInitConditions(const string& input)
{
	vector<Star> read_conditions;
	ifstream infile(input);

    /* make sure the file is opened */
    if(!infile.is_open())
    {
        cout << "Couldn't open file." << endl;
    }

    else
    {
        /* read initial conditions in a dynamically sized vector */
        while(true)
        {
	        double m, x, y, vx, vy;
            infile >> m >> x >> y >> vx >> vy;
            if(!infile.good())
            {
                break;
            }
            Vec r = Vec(x, y);
            Vec v = Vec(vx, vy);
            read_conditions.push_back(Star(m, r, v));
        }
	infile.close();
    }

    /* transfer read conditions to a fixed size valarray */
    valarray<Star> initial_conditions(read_conditions.size());

    for (size_t i = 0; i != read_conditions.size(); ++i)
    {
        initial_conditions[i] = read_conditions[i];
    }
   
	return initial_conditions;
}

void printInformation(ofstream& filestream, const string& filename, const double timestep, const size_t print_skip, const string& integrator)
{
    if (integrator == "RK")
    {
        filestream << left << "# integrated " << filename << " with Runge-Kutta 4 with an initial timestep " << timestep << " printing the data every " << print_skip << "th iteration" << "\n";
    }
    else
    {
        filestream << left << "# integrated " << filename << " with Gragg-Bulirsch-Stoer with an initial timestep " << timestep << " printing the data every " << print_skip << "th iteration" << "\n";
    }
}

/* print a header (t x1 x2 ... ) to a file */
void printHeader(ofstream& filestream, const valarray<Star>& stars, const int width)
{
    size_t size = stars.size();

    filestream << setw(width) << left << "# t";
    for (size_t i = 0; i < size; ++i)
    {
        filestream << setw(width) << left << "x" + to_string(i + 1) << setw(width) << left << "y" + to_string(i + 1); 
    }
    filestream << setw(width) << left << "delta E" << "\n";
}

/* print the coordinates of a vector of Stars and the timestep to a text file */
void printToFile(ofstream& filestream, const double time, const double energy_difference, const valarray<Star>& stars, const int width)
{
    size_t size = stars.size();

	filestream << setw(width) << left << time;
    valarray<Vec> positions = getPositions(stars);
	for (size_t i = 0; i < size; ++i) 
    {
        filestream << setw(width) << left << positions[i].x() << setw(width) << left << positions[i].y(); 
    }
    /* filestream << calcEnergy(stars); */
    filestream << energy_difference;
    filestream << "\n";
}

