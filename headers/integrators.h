#ifndef H_INTEGRATORS
#define H_INTEGRATORS

/* libraries */
#include <valarray>
#include <string>

/* custom headers */
#include "star.h"
#include "vec.h"

void rungeKutta(valarray<Star>, valarray<Vec> (*driver)(const valarray<Vec>&, const valarray<double>&), const double, const double, const string&, const string&, const size_t); 
valarray<Star> modifiedMidpoint(valarray<Star>, valarray<Vec> (*driver)(const valarray<Vec>&, const valarray<double>&), const double, const size_t);
void graggBulirschStoer(valarray<Star>, valarray<Vec> (*driver)(const valarray<Vec>&, const valarray<double>&), const double, const double, const string&, const string&, const size_t, const double);

#endif
