/* libraries */
#include <valarray>
#include <string>
#include <iostream>

/* custom headers */
#include "drivers.h"

using namespace std;

size_t evaluations = 0;

/* driver function for a harmonic oscillator for testing purposes */
valarray<Vec> harmonicOscillator(const valarray<Vec>& r, const valarray<double>& masses)
{
    double w = 5.0;
    valarray<Vec> a(r.size());
    a = -w * w * r;
    ++evaluations;
    return a;
}

/* driver function for the gravitational interaction */
valarray<Vec> gravity(const valarray<Vec>& r, const valarray<double>& masses)
{
    size_t size = r.size();
	valarray<Vec> a(size);

	for(size_t i = 0; i != size; ++i)
	{
		for(size_t j = i + 1; j != size; ++j) // N * (N - 1) / 2 evaluations instead of N * N
		{
			a[i] -= masses[j] / (r[i] - r[j]).norm3() * (r[i] - r[j]);
            a[j] -= masses[i] / masses[j] * a[i];
		}
	}

    ++evaluations;
	return a;
}

size_t getEvaluations()
{
    return evaluations;
}
void resetEvaluations()
{
    evaluations = 0;
}

/* prints the number of driver evaluations per unit time and reset them to 0 */
void tellEvaluations(double time)
{
    /* ANSI escape sequences for red */
    string red = "\033[0;31m";
    string der = "\033[0m";

    cout << red + "Average number of driver-evaluations per unit time: " + der << endl << getEvaluations() / time << endl;
    resetEvaluations();
}
