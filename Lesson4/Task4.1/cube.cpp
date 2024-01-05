#include "cube.h"

Cube::Cube(const int& _x1, const int& _y1, const int& _z1,
	const int& _x2, const int& _y2, const int& _z2,
	const int& _x3, const int& _y3, const int& _z3,
	const int& _x4, const int& _y4, const int& _z4,
	const int& _x5, const int& _y5, const int& _z5,
	const int& _x6, const int& _y6, const int& _z6,
	const int& _x7, const int& _y7, const int& _z7,
	const int& _x8, const int& _y8, const int& _z8)
{
	type = static_cast<int>(figures::cube);
	x1 = _x1; y1 = _y1; z1 = _z1;
	x2 = _x2; y2 = _y2; z2 = _z2;
	x3 = _x3; y3 = _y3; z3 = _z3;
	x4 = _x4; y4 = _y4; z4 = _z4;
	x5 = _x5; y5 = _y5; z5 = _z5;
	x6 = _x6; y6 = _y6; z6 = _z6;
	x7 = _x7; y7 = _y7; z7 = _z7;
	x8 = _x8; y8 = _y8; z8 = _z8;
	a = abs(x1 - x2);
	b = abs(y1 - y2);
	c = abs(z1 - z2);
	calculateSquare(a, b, c);
	calculateVolume(a, b, c);
}

void Cube::calculateSquare(const int& a, const int& b, const int& c)
{
	square = 2 * a * b + 2 * a * c + 2 * b * c;
}

void Cube::calculateVolume(const int& a, const int& b, const int& c)
{
	volume = a * b * c;
}

void Cube::shift(int m, int n, int k)
{
	x1 += m; y1 += n; z1 += k;
	x2 += m; y2 += n; z2 += k;
	x3 += m; y3 += n; z3 += k;
	x4 += m; y4 += n; z4 += k;
	x5 += m; y5 += n; z5 += k;
	x6 += m; y6 += n; z6 += k;
	x7 += m; y7 += n; z7 += k;
	x8 += m; y8 += n; z8 += k;
}
void Cube::scaleX(int _a)
{
	x1 *= _a;
	x2 *= _a;
	x3 *= _a;
	x4 *= _a;
	x5 *= _a;
	x6 *= _a;
	x7 *= _a;
	x8 *= _a;
}
void Cube::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
	y5 *= d;
	y6 *= d;
	y7 *= d;
	y8 *= d;
}
void Cube::scaleZ(int e)
{
	z1 *= e;
	z2 *= e;
	z3 *= e;
	z4 *= e;
	z5 *= e;
	z6 *= e;
	z7 *= e;
	z8 *= e;
}
void Cube::scale(int s)
{
	x1 /= s; y1 /= s; z1 /= s;
	x2 /= s; y2 /= s; z2 /= s;
	x3 /= s; y3 /= s; z3 /= s;
	x4 /= s; y4 /= s; z4 /= s;
	x5 /= s; y5 /= s; z5 /= s;
	x6 /= s; y6 /= s; z6 /= s;
	x7 /= s; y7 /= s; z7 /= s;
	x8 /= s; y8 /= s; z8 /= s;
}