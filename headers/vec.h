#ifndef H_VEC 
#define H_VEC

#include <cmath>
#include <iostream>

using namespace std;

class Vec
{
private:
	double _x;
	double _y;
public:
	Vec() : _x(0), _y(0) {} 
	Vec(double x, double y) : _x(x), _y(y) {}
    Vec(const Vec& a) : _x(a.x()), _y(a.y()) {}

	double x() const {return _x;}
	double y() const {return _y;}
    double norm() const {return sqrt(_x * _x + _y * _y);}
    double norm2() const {return _x * _x + _y * _y;}
	double norm3() const {return this->norm() * this->norm() * this->norm();}

    Vec& operator = (const Vec& v)
    {
        _x = v.x();
        _y = v.y();
        return *this;
    }

    Vec& operator += (const Vec& v)
    {
	    _x += v.x();
	    _y += v.y();
	    return *this;
    }

    Vec& operator -= (const Vec& v)
    {
    	_x -= v.x();
	    _y -= v.y();
    	return *this;
    }

    Vec& operator *= (double s)
    {
    	_x *= s;
	    _y *= s;
    	return *this;
    }

    Vec& operator /= (double s)
    {
        _x /= s;
        _y /= s;
        return *this;
    }
    
    friend ostream& operator << (ostream &output, const Vec& a)
    {
        output << "[" << a.x() << ", " << a.y() << "]";
        return output;
    } 
};

inline Vec operator + (Vec a, const Vec& b)
    {
	    return a += b;
    }

inline Vec operator - (Vec a, const Vec& b)
    {
	    return a -= b;
    }

inline Vec operator * (Vec a, const double s)
    {
        return a *= s;
	}

inline Vec operator * (const double s, Vec a)
    {
        return a * s;
    }

inline Vec operator / (Vec a, const double s)
    {
        return a /= s;
    }

inline Vec operator / (const double s, Vec a)
    {
        return a / s;
    }

#endif
