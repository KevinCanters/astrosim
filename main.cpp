/* libraries */
#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <string>
#include <cmath>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <fstream>


/* custom headers */
#include "headers/drivers.h"
#include "headers/integrators.h"
#include "headers/vec.h"
#include "headers/star.h"
#include "headers/fileio.h"
#include "headers/stl-operators.h"
#include "headers/userinput.h"

using namespace std;

int main(int argc, char* argv[])
{
    /*** fancy output with ANSI escape sequences for red ***/
    string red = "\033[0;31m";
    string der = "\033[0m";
    
    string integrator;
    double timestep;
    double endtime;
    size_t print_skip;
    string filename;
    string output_filename;
    
    if(argc==1)
    {
	    /*** The user has the choice between giving a text file with the integration variables, or to give them in by hand. ***/
	    integrator = askIntegrator();
	    timestep = askTimeStep();
	    endtime = askEndTime();
	    print_skip = askPrintSkip();
	    filename= askFilename();
        string input_filename = "input/" + filename;
        string output_filename = "output/" + integrator + "_" + to_string((int) endtime) + "_" + filename;
        chrono::time_point<chrono::system_clock> start, end;
        valarray<Star> stars = readInitConditions(input_filename);
        double elapsed_time;

        cout << red + integrator + " integration of " + input_filename + der << endl;
        cout << red + "Progress" + der << endl;
        start = chrono::system_clock::now();    
        if (integrator == "RK")
        {
            rungeKutta(stars, gravity, endtime,timestep, input_filename, output_filename, print_skip);
        }

        if (integrator == "GBS")
        {
            graggBulirschStoer(stars, gravity, endtime, timestep, input_filename, output_filename, print_skip, 1e-13);
        }
        end = chrono::system_clock::now();
        elapsed_time = chrono::duration<double>(end-start).count();
        cout << red + "Integration finished in:" + der << endl << elapsed_time << "s" << endl;

        tellEvaluations(endtime);
    }

    else
    {	
        /* store character array in string */ 
    	string textfile;
    	for (size_t i = 1; i < argc; ++i)
    	{
    		textfile += argv[i];
    	}
    	ifstream infile(textfile);

    	while (true)
	    {
		    infile >> integrator >> endtime >> timestep >> print_skip >> filename >> output_filename;
            string input_filename = "input/" + filename;
            /* string output_filename = "output/" + integrator + "_" + to_string((int) endtime) + "_" + filename; */
            chrono::time_point<chrono::system_clock> start, end;
            valarray<Star> stars = readInitConditions(input_filename);
            double elapsed_time;
            
            cout << red + integrator + " integration of " + input_filename + der << endl;
            cout << red + "Progress" + der << endl;
            start = chrono::system_clock::now();    
            if(integrator == "RK")
            {
                rungeKutta(stars, gravity, endtime,timestep, input_filename, output_filename, print_skip);
            }
            
            if(integrator == "GBS")
            {
                graggBulirschStoer(stars, gravity, endtime, timestep, input_filename, output_filename, print_skip, 1e-13);
            }
            end = chrono::system_clock::now();
            elapsed_time = chrono::duration<double>(end-start).count();
            cout << red + "Integration finished in:" + der << endl << elapsed_time << "s" << endl;

            tellEvaluations(endtime);

		    if(!infile.good()) 
            {
                break;
            }
	    }
	    infile.close();
    }
    /* valarray<Vec> r = {Vec(0.0,0.0), Vec(2.0,2.0)}; */
    /* valarray<double> d = {1,1}; */
    /* valarray<Vec> h = harmonicOscillator(r,d); */
    /* for (size_t i = 0; i != h.size(); ++i) */
    /* { */
    /*     cout << h[i] << endl; */
    /* } */
}

