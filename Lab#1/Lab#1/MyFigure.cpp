#include "MyFigure.h"



MyFigure::MyFigure()
{
	angle = 0;
	sides = nullptr;
}
MyFigure::MyFigure(int _angle)
{
	if (_angle > 2 && _angle < 6)
	{
		angle = _angle;
		sides = new int[angle];
	}
	else
	{
		angle = 0;
		sides = nullptr;
	}
}
MyFigure::MyFigure(int a, int b, int c, int d, int g)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return;

	if (d == 0 )
	{
		angle = 3;
		sides = new int[angle];
	}
	else if (d > 0 && g == 0 )
	{
		angle = 4;
		sides = new int[angle];
		sides[0] = a;
		sides[1] = b;
		sides[2] = c;
		sides[3] = d;
	}
	else if (d > 0 && g > 0 )
	{
		angle = 5;
		sides = new int[angle];
		sides[0] = a;
		sides[1] = b;
		sides[2] = c;
		sides[3] = d;
		sides[4] = g;
	}
	else
	{
		angle = 0;
		sides = nullptr;
	}
}
MyFigure::~MyFigure()
{
}
MyFigure MyFigure::operator=(MyFigure obj)
{
	angle = obj.angle;
	delete[] sides;
	sides = new int[angle];
	for (int i = 0; i < angle; i++)
	{
		*(sides + i) = obj.GetSideLengthByIndex(i);
	}
	return *this;
}
bool MyFigure::operator==(MyFigure obj)
{
	if (angle != obj.angle)
		return false;
	for (int i = 0; i < angle; i++)
		if (*(sides + i) != obj.GetSideLengthByIndex(i))
			return false;
	return true;
}
bool MyFigure::operator!=(MyFigure obj)
{
	if (angle != obj.angle)
		return true;
	for (int i = 0; i < angle; i++)
		if (sides[i] != obj.GetSideLengthByIndex(i))
			return true;
	return false;
}
int MyFigure::get_count_of_angles()
{
	return angle;
}
float MyFigure::get_perimetr()
{
	if (angle == 0)
		return 0;

	float per = 0;
	for (int i = 0; i < angle; i++)
		per += sides[i];
	return per;
}
float MyFigure::ploshad()
{
	float hp = get_perimetr() / 2;
	if (angle == 3)
	{
		return sqrt(hp * (hp - sides[0]) * (hp - sides[1]) *(hp - sides[2]));
	}
	else if (angle == 4)
	{
		return sqrt((hp - sides[0]) * (hp - sides[1]) *(hp - sides[2]) * (hp - sides[3]));
	}
	else if (angle == 5)
	{
		return sqrt((hp - sides[0]) * (hp - sides[1]) *(hp - sides[2]) * (hp - sides[3]) * (hp - sides[4]));
	}
	else
	{
		return 0;
	}
}
void MyFigure::SetLengthByIndex(int val, int num)
{
	if (num < angle && num >= 0 && val > 0)
	{
		sides[num] = val;
	}
}
int MyFigure::GetSideLengthByIndex(int num)
{
	if (num < angle && num >= 0)
		return sides[num];

	return 0;
}