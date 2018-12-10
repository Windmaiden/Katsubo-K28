#pragma once
#include "MyFigure.h"
class MyTriangle : public MyFigure
{
public:
	MyTriangle();
	~MyTriangle();

	bool IsRavnostoronniy();
	bool ISRavnoBedrenniy();
	bool IsPryamougolniu();
};

