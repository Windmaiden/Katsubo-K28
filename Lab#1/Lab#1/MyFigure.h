#include <math.h>

#pragma once

class MyFigure
{
private:
	int angle;
protected:
	int* sides;
public:
	MyFigure();
	MyFigure(int _angle);
	MyFigure(int a, int b, int c, int d = 0, int g = 0);
	~MyFigure();
	MyFigure operator=(MyFigure obj);
	bool operator ==(MyFigure obj);
	bool operator !=(MyFigure obj);
	int get_count_of_angles();
	float get_perimetr();
	float ploshad();
	void SetLengthByIndex(int val, int num);
	int GetSideLengthByIndex(int num);

};
