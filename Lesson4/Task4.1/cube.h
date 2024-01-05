#pragma once
#include "shape.h"

class Cube : public Shape1
{
public:
	Cube(const int& _x1, const int& _y1, const int& _z1,
		const int& _x2, const int& _y2, const int& _z2,
		const int& _x3, const int& _y3, const int& _z3,
		const int& _x4, const int& _y4, const int& _z4,
		const int& _x5, const int& _y5, const int& _z5,
		const int& _x6, const int& _y6, const int& _z6,
		const int& _x7, const int& _y7, const int& _z7,
		const int& _x8, const int& _y8, const int& _z8);
	void shift(int m, int n, int k) override;
	void scaleX(int _a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;
protected:
	void calculateSquare(const int& a, const int& b, const int& c) override;
	void calculateVolume(const int& a, const int& b, const int& c) override;
};
