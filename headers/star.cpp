/* headers */
#include <valarray>

/* custom libraries */
#include "star.h"

/* returns an array with the positions from each Star in an array of Stars */
valarray<Vec> getPositions(const valarray<Star>& stars)
{
    size_t size = stars.size();
    valarray<Vec> positions(size);

    for(size_t i = 0; i < size; ++i)
    {
        positions[i] = stars[i].position();
    }

    return positions;
}

/* returns an array with the positions from each Star in an array of Stars */
valarray<Vec> getVelocities(const valarray<Star>& stars)
{
    size_t size = stars.size();
    valarray<Vec> velocities(size);

    for(size_t i = 0; i < size; ++i)
    {
        velocities[i] = stars[i].velocity();
    }

    return velocities;
}

/* returns an array with the masses from each Star in an array of Stars */
valarray<double> getMasses(const valarray<Star>& stars)
{
    size_t size = stars.size();
	valarray<double> masses(size);

    for(size_t i = 0; i < size; ++i)
    {
        masses[i] = stars[i].mass();
    }

    return masses;
}

/* updates the positions and velocities of each Star in an arrays of Stars */
void updateStars(valarray<Star>& stars, const valarray<Vec>& positions, const valarray<Vec>& velocities)
{
    size_t size = stars.size();

    for(size_t i = 0; i < size; ++i)
    {
        stars[i].setPosition(positions[i]);
        stars[i].setVelocity(velocities[i]);
    }
}
