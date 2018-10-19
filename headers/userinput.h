#ifndef H_INPUT
#define H_INPUT

/* libraries */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

string integrator;
double timestep;
double endtime;


string askIntegrator()
{
    /* ANSI escape sequences for red */
    string red = "\033[0;31m";
    string der = "\033[0m";

	cout << red + "Integrator? RK for RungeKutta or GBS for Gragg-Bulirsch-Stör." + der << endl;
	cin >> integrator;
    while(integrator != "RK" && integrator != "GBS")
    {
        cout << red + "Only the RK or GBS option are allowed." + der << endl;
        cin >> integrator;
    }
	return integrator;
}

double askTimeStep()
{	
    /* ANSI escape sequences for red */
	string red = "\033[0;31m";
    string der = "\033[0m";

	cout << red + "Timestep?" + der << endl;
	cin >> timestep;
    /* catch non numeric input */
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();                                  
        cout << red + "Timestep should be a numeric value." + der << endl;
        cin >> timestep;
    }
	return timestep;
}

double askEndTime()
{	
    /* ANSI escape sequences for red */
	string red = "\033[0;31m";
    string der = "\033[0m"; 

	cout << red + "Endtime?" + der <<endl;
	cin >> endtime;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();                                  
        cout << red + "Endtime should be a numeric value." + der << endl;
        cin >> endtime;
    }
    while (endtime < timestep)
    {
        cout << red + "Endtime should be larger than the timestep." + der << endl;
        cin >> endtime;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();                                  
            cout << red + "Endtime should be a numeric value." + der << endl;
            cin >> endtime;
        }
    }
	return endtime;
}
 
size_t askPrintSkip()
{	
    /* ANSI escape sequences for red */
    string red = "\033[0;31m";
    string der = "\033[0m";

	size_t print_skip;
	cout << red + "How many timesteps should be skipped when printing to the output file? e.g. 10 prints to file only once every 10 timesteps)." + der << endl;
	cin >> print_skip;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();                                  
        cout << red + "Print_skip should be a numeric value." + der << endl;
        cin >> print_skip;
    }
    while (print_skip > (endtime / timestep))
    {
        cout << red + "No points will be printed. Print_skip > (endtime / timestep)." + der << endl;
        cin >> print_skip;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();                                  
            cout << red + "Print_skip should be a numeric value." + der << endl;
            cin >> print_skip;
        }
    }
	return print_skip;
}


string askFilename()
{
    /* ANSI escape sequences for red */
    string red = "\033[0;31m";
    string der = "\033[0m";
    ifstream trial;

	string input_filename;
	cout << red + "Name of the input txt file in 'input/'. The output file has the same name with the integrator type and endtime appended located in 'output/'." + der << endl;
	cin >> input_filename;
    
    /* test if specified file exists */
    trial.open("input/" + input_filename);
    while(!trial.is_open())
    {
        cout << red + "The file >> " << input_filename << " << doesn't exist in 'input/'." + der << endl;
        cin >> input_filename;
        trial.open("input/" + input_filename);
    }
    trial.close();

	return input_filename;
}

#endif
