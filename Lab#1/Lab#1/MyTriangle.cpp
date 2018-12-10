#include "MyTriangle.h"



MyTriangle::MyTriangle()
{
}


MyTriangle::~MyTriangle()
{
}

bool MyTriangle::IsRavnostoronniy()
{
	return sides[0]==sides[1] && sides[1]==sides[2];
}

bool MyTriangle::ISRavnoBedrenniy()
{
	return sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2];
}

bool MyTriangle::IsPryamougolniu()
{
	int A = sides[0] * sides[0];
	int B = sides[1] * sides[1];
	int C = sides[2] * sides[2];
	return A + B == C || A + C == B || B + C == A;
}
