#include "circle.h"

Circle::Circle(const int& _x1, const int& _y1,
	const double& R)
{
	type = static_cast<int>(figures::circle);
	x1 = _x1; y1 = _y1;
	radius = R;
	calculateSquare(R, 0);
	calculateVolume(R, 0);
}

void Circle::calculateSquare(const double& R, const double& H)
{
	square = M_PI * R * R;
}

void Circle::calculateVolume(const double& R, const double& H)
{
	volume = 0;
}