#pragma once
#include "shape.h"

class Sqr : public Shape1
{
public:
	Sqr(const int& _x1, const int& _y1, const int& _x2, const int& _y2,
		const int& _x3, const int& _y3, const int& _x4, const int& _y4);
	void shift(int m, int n, int k) override;
	void scaleX(int _a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;

protected:
	void calculateSquare(const int& a, const int& b, const int& c) override;
	void calculateVolume(const int& a, const int& b, const int& c) override;
};