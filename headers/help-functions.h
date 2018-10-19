#ifndef H_HELP_FUNCTIONS
#define H_HELP_FUNCTIONS

/* libraries */
/* #include <vector> */
/* #include <array> */

/* custom headers */
/* #include "vec.h" */
/* #include "star.h" */

double calcDistance(const Star&, const Star&);
double calcMinDistance(const valarray<Star>&);
double calcEnergy(const valarray<Star>&);
double calcConvergence(const array<valarray<Star>, 8>&, const size_t, const size_t);

#endif
