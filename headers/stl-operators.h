#ifndef H_STL_OPERATORS 
#define H_STL_OPERATORS

/* libraries */
#include <array>
#include <valarray>
#include <iostream>

/* custom headers */
#include "vec.h"
#include "star.h"

/* operator overloading for array<T, n> */
/* array addition */
template<class T, size_t N> 
inline array<T, N> operator + (const array<T, N>& left, const array<T, N>& right)
{
    array<T, N> output;
    for (size_t i = 0; i < N; ++i)
    {
        output[i] = left[i] + right[i];
    }
    return output;
}

/* array substraction */
template<class T, size_t N> 
inline array<T, N> operator - (const array<T, N>& left, const array<T, N>& right)
{
    array<T, N> output;
    for (size_t i = 0; i < N; ++i)
    {
        output[i] = left[i] - right[i];
    }
    return output;
}

/* (left) scalar multiplication */
template<class T, size_t N>
inline array<T, N> operator * (double s, const array<T, N>& right)
{
    array<T, N> output;
    for (size_t i = 0; i < N; i++)
    {
        output[i] = s * right[i];
    }
    return output;
}

/* (right) scalar division (for graggBulirschStoer) */
template<class T, size_t N>
inline array<T, N> operator / (const array<T, N>& left, double s)
{
    array<T, N> output;
	for(size_t i = 0; i < N; ++i)
    {
        output[i] = left[i] / s;
	}
	return output;
}

/* cout */
template<class T, size_t N>
inline ostream& operator << (ostream& output, const array<T, N>& v)
{
    for(size_t i = 0; i != N; ++i)
    {
        output << v[i] << endl;
    }
    return output;
}

/* valarray operator overlading */
/* scalar multiplication */
template <class T> 
inline valarray<T> operator * (double s, const valarray<T>& right)
{
    size_t size = right.size();
    valarray<T> output(size);

    for(size_t i = 0; i != size; ++i)
    {
        output[i] = right[i] * s;
    }

    return output;
}

template <class T> 
inline valarray<T> operator * (const valarray<T>& left, double s)
{
    size_t size = left.size();
    valarray<T> output(size);

    for(size_t i = 0; i != size; ++i)
    {
        output[i] = left[i] * s;
    }

    return output;
}

template <class T> 
inline valarray<T> operator / (double s, const valarray<T>& right)
{
    size_t size = right.size();
    valarray<T> output(size);

    for(size_t i = 0; i != size; ++i)
    {
        output[i] = right[i] / s;
    }

    return output;
}

inline valarray<Vec> operator * (double s, const valarray<Vec>& right)
{
    size_t size = right.size();
    valarray<Vec> output(size);

    for(size_t i = 0; i != size; ++i)
    {
        output[i] = right[i] * s;
    }

    return output;
}

/* scalar division */
template <class T> 
inline valarray<T> operator / (const valarray<T>& left, double s)
{
    size_t size = left.size();
    valarray<T> output(size);

    for(size_t i = 0; i != size; ++i)
    {
        output[i] = left[i] / s;
    }

    return output;
}

inline valarray<Star> operator / (const valarray<Star>& left, double s)
{
    size_t size = left.size();
    valarray<Star> output(size);

    for(size_t i = 0; i != size; ++i)
    {
        output[i] = left[i] / s;
    }

    return output;
}

#endif
