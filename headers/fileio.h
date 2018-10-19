#ifndef H_INPUTREAD
#define H_INPUTREAD

/* libraries */
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <valarray>

/* custom headers */
#include "star.h"

valarray<Star> readInitConditions(const string&);
void printInformation(ofstream&, const string&, const double, const size_t, const string&);
void printHeader(ofstream&, const valarray<Star>&, const int);
void printToFile(ofstream&, const double, const double, const valarray<Star>&, const int);

#endif
