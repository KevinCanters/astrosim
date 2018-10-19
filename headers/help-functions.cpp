/* libraries */
#include <valarray>
#include <array>

/* custom headers */
#include "star.h"
#include "vec.h"

using namespace std;

/* returns the distance between two Stars */
double calcDistance(const Star& a, const Star& b)
{
	return (a.position() - b.position()).norm();
}

/* returns the smallest distance between two Stars for a vector of Stars */
double calcMinDistance(const valarray<Star>& stars)
{
	double result = calcDistance(stars[0], stars[1]);
    size_t size = stars.size();

	for(size_t i = 0; i != size; ++i)
    {
		for(size_t j = i + 1; j != size; ++j)
        {
			result = min(result, calcDistance(stars[i], stars[j]));
		}
	}
	return result;
}

/* returns the total energy (kinetic + potential) of a vector of Stars */
double calcEnergy(const valarray<Star>& stars)
{
	double Ekin = 0.;
	double Epot = 0.;
    size_t size = stars.size();

	for(size_t i = 0; i != size; ++i)
    {
		Ekin += stars[i].kineticEnergy();
		
        for(size_t j = i + 1; j != size; ++j)
        {
			Epot += stars[i].mass() * stars[j].mass() / calcDistance(stars[i], stars[j]);
		}
	}
	return Ekin - Epot;
}

/* returns the largest value off all the stars for the convergence criterium */
double calcConvergence(const array<valarray<Star>, 8>& row, const size_t k, const size_t k_plus)
{
    double largest = 0;
    size_t size = row[0].size();

    for(size_t i = 0; i < size; ++i)
    {
        double position_difference = (row[k][i].position() - row[k_plus][i].position()).norm();
        double velocity_difference = (row[k][i].velocity() - row[k_plus][i].velocity()).norm();

        if (largest < position_difference)
        {
            largest = position_difference;
        }
        else if (largest < velocity_difference)
        {
            largest = velocity_difference;
        }
    }
   
   return largest; 
}
