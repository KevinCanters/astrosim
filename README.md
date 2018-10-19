# C++ project astrophysical simulations

Runge-Kutta 4 and Gragg-Bulirsch-Stoer integrators with a variable timestep. 

Compiling (installing)
----------------------

The included Makefile assumes the presence of the g++ compiler. If not available, any of the C++ compilers that support C++11 should work.
Compiling the source code can be done by running `make`. Removing the binary and the object files can be done with `make clean`. Finally, if so desired the debug flag can be passed as well with `make debug`.

Usage
-----

One compiled, the program is called simulation and the user has the choice between giving a text file containing the integration variables or giving them by hand.

### Integration with arguments in a text file
Use the program as follows `./simulation example_list.txt`.
The text file passed as argument has to be structured as follows:

Integrator, RK or GBS, endtime timestep print_skip filename. The print_skip variable determines after howmany timesteps the coordinates should be printed to a file. Print_skip can be set to 1, but this will create very large files. Filename should be one of the text files found in `input/`. The output will be placed in `output/` and it's name will be the used integration, endtime and the provided input file stringed together. For example

`RK 70 8e-5 1000 burrau.txt` is stored in a file called `int.txt` and running `./simulation int.txt`  will produce a file called RK_70_burrau.txt in output/.

The text file can also contain multiple of these lines, which will then be integrated one after the other.

### Integration with arguments passed by hands
You can run './simulation' without providing an argument. The program will ask you the integration variables.

### Input files
Some input files are included but more can be added. The input file should be structured as follows:

m1 x1 y1 vx1 vy2

m2 x2 y2 vx2 vy2
...

### Output file
The output file only contains t, x, y (for all particles) and the relative energy error. 

### Group members
* Kevin Canters
* Kwinten De Backer
* Tammas Gommers
* Johannes Weytjens
