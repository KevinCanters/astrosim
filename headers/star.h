#ifndef H_STAR 
#define H_STAR

/* libraries */
#include <iostream>
#include <valarray>

/* custom headers */
#include "vec.h"

using namespace std;

/* Star class which contains a star's mass, position and velocity */
class Star
{
private:
	double _mass;
	Vec _position;
	Vec _velocity;
public:
    Star() : _mass(1), _position(), _velocity() {}
	Star(double mass, Vec pos, Vec vel) : _mass(mass), _position(pos), _velocity(vel) {}
	
	Vec position() const {return _position;}
    Vec velocity() const {return _velocity;}
    void setPosition(Vec position) {_position = position;}
    void setVelocity(Vec velocity) {_velocity = velocity;}
    double mass() const {return _mass;}
    double kineticEnergy() const {return 0.5 * _mass * _velocity.norm2();}

    friend ostream& operator << (ostream &output, const Star& s)
    {
        output << "mass: " << s.mass() << " ";
        output << "position: " << s.position() << " ";
        output << "velocity: " << s.velocity();
        return output;
    }
};

valarray<Vec> getPositions(const valarray<Star>&);
valarray<Vec> getVelocities(const valarray<Star>&);
valarray<double> getMasses(const valarray<Star>&);
void updateStars(valarray<Star>&, const valarray<Vec>&, const valarray<Vec>&);

/* operator overloading for Star */
/* Star addition (assuming you add the same Star to itself) */
inline Star operator + (const Star& left, const Star& right)
{
    Star output(left.mass(), left.position() + right.position(), left.velocity() + right.velocity());
    return output;
}

/* Star substraction (assuming you substract the same Star from itself) */
inline Star operator - (const Star& left, const Star& right)
{
    Star output(left.mass(), left.position() - right.position(), left.velocity() - right.velocity());
    return output;
}

/* (right) scalar division (for graggBulirschStoer) */
inline Star operator / (const Star& left, double s)
{
    Star output(left.mass(), left.position() / s, left.velocity() / s);
    return output; 
}

#endif
