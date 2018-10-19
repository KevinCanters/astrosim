#ifndef H_DRIVERS
#define H_DRIVERS

/* libraries */
#include <vector>
#include <valarray>

/* custom headers */
#include "vec.h"
#include "stl-operators.h"

valarray<Vec> harmonicOscillator(const valarray<Vec>&, const valarray<double>&);
valarray<Vec> gravity(const valarray<Vec>&, const valarray<double>&);
size_t getEvaluations();
void resetEvaluations();
void tellEvaluations(double time);

#endif
