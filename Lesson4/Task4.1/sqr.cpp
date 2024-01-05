#include "sqr.h"

Sqr::Sqr(const int& _x1, const int& _y1, const int& _x2, const int& _y2,
	const int& _x3, const int& _y3, const int& _x4, const int& _y4)
{
	type = static_cast<int>(figures::sqr);
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	x3 = _x3; y3 = _y3;
	x4 = _x4; y4 = _y4;
}

void Sqr::calculateSquare(const int& a, const int& b, const int& c)
{
	square = a * b;
}

void Sqr::calculateVolume(const int& a, const int& b, const int& c)
{
	volume = 0;
}

void Sqr::shift(int m, int n, int k)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	x3 += m; y3 += n;
	x4 += m; y4 += n;
}
void Sqr::scaleX(int _a)
{
	x1 *= _a;
	x2 *= _a;
	x3 *= _a;
	x4 *= _a;
}
void Sqr::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
}
void Sqr::scaleZ(int e)
{
	z1 *= e;
	z2 *= e;
	z3 *= e;
	z4 *= e;
}
void Sqr::scale(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
	x3 /= s; y3 /= s;
	x4 /= s; y4 /= s;
}