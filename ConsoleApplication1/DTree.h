#pragma once
#define MaxSize 11
#include "DNode.h"
#include <string>
#include <vector>


class Gain
{
public:
	Gain();
	double gaincal(int column, int cla)
	{
		if (cla)
			return gaincalI(column);
		else
			return gaincalL(column);
	}
	~Gain();
private:
	double gaincalI(int);
	double gaincalL(int);
	double Entropy(int, int);
	double gain;
	int type;
	vector<vector<string>> state;
	int tablet;
	double division;
};

