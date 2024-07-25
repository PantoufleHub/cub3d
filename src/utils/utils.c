#include "../../inc/cub3D.h"
double degreetoRadiant(double degree)
{
	double pi;

	pi = M_PI;
	return (degree * pi / 180);
}

double cos_degree(double degree)
{
	return  (cos(degreetoRadiant(degree)));
}

double sin_degree(double degree)
{
	return  (sin(degreetoRadiant(degree)));
}
