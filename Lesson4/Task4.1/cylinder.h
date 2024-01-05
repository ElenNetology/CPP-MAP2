#pragma once
#include "shape.h"

class Cylinder : public Shape2
{
public:
	Cylinder(const int& _x1, const int& _y1,
		const double& R, const double& H);
protected:
	void calculateSquare(const double& R, const double& H) override;
	void calculateVolume(const double& R, const double& H) override;
};