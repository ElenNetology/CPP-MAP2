#include "line.h"

Line::Line(const int& _x1, const int& _y1, const int& _x2, const int& _y2)
{
	type = static_cast<int>(figures::line);
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;

}


void Line::calculateSquare(const int& a, const int& b, const int& c)
{
	square = 0;
}

void Line::calculateVolume(const int& a, const int& b, const int& c)
{
	volume = 0;
}

void Line::shift(int m, int n, int k)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
}
void Line::scaleX(int _a)
{
	x1 *= _a;
	x2 *= _a;
}
void Line::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
}
void Line::scaleZ(int e)
{
	z1 *= e;
	z2 *= e;
}
void Line::scale(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
}
