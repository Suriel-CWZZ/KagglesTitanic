#include "stdafx.h"
#include "DTree.h"


Gain::Gain()
{
}

double Gain::gaincalI(int column)
{
	int Ssitu[MaxSize] = { 0 }, Tsitu[MaxSize] = { 0 }, total = 0, surv = 0;
	double entropy[MaxSize], gain = 0;
	for (unsigned int i = 1; i <= state.size() - 1; i++)
	{
		if (!state[i][column].empty())
		{
			if (stoi(state[i][0], 0, 10))
			{
				Ssitu[stoi(state[i][column], 0, 10)]++;
				Tsitu[stoi(state[i][column], 0, 10)]++;
				surv++;
				total++;
			}
			else
			{
				Tsitu[stoi(state[i][column], 0, 10)]++;
				total++;
			}
		}
	}
	/*	for (int i = 0; i <= MaxSize - 1; i++)
	{
	if (!Tsitu[i])
	{
	total += Tsitu[i];
	surv += Ssitu[i];
	entropy[i] = Entropy(Ssitu[i], Tsitu[i]);
	}
	}
	*/
	gain += Entropy(surv, total);
	for (int i = 0; i <= MaxSize - 1; i++)
	{
		if (!Tsitu[i])
		{
			gain -= (double)Tsitu[i] / (double)total*Entropy(Ssitu[i], Tsitu[i]);
		}
	}
	return gain;
}

double Gain::gaincalL(int column)
{
	vector<vector<string>> tempstate(state);
	int min = stoi(tempstate[1][column], 0, 10), max = stoi(tempstate[1][column], 0, 10), res;
	double maxgain = 0;
	for (unsigned int i = 2; i <= tempstate.size() - 1; i++)
	{
		if (stoi(tempstate[i][column], 0, 10) > max)
			max = stoi(tempstate[i][column], 0, 10);
		if (stoi(tempstate[i][column], 0, 10) < min)
			min = stoi(tempstate[i][column], 0, 10);
	}
	for (int k = min + 1; k < max; k++)
	{
		for (unsigned int i = 1; i <= tempstate.size() - 1; i++)
		{
			if (stoi(tempstate[i][column], 0, 10) > k)
				tempstate[i][column] = "1";
			else
				tempstate[i][column] = "0";
		}
		int Ssitu[MaxSize] = { 0 }, Tsitu[MaxSize] = { 0 }, total = 0, surv = 0;
		double entropy[MaxSize], gain = 0;
		for (unsigned int i = 1; i <= tempstate.size() - 1; i++)
		{
			if (!tempstate[i][column].empty())
			{
				if (stoi(tempstate[i][0], 0, 10))
				{
					Ssitu[stoi(tempstate[i][column], 0, 10)]++;
					Tsitu[stoi(tempstate[i][column], 0, 10)]++;
					surv++;
					total++;
				}
				else
				{
					Tsitu[stoi(tempstate[i][column], 0, 10)]++;
					total++;
				}
			}
		}
		/*	for (int i = 0; i <= MaxSize - 1; i++)
		{
		if (!Tsitu[i])
		{
		total += Tsitu[i];
		surv += Ssitu[i];
		entropy[i] = Entropy(Ssitu[i], Tsitu[i]);
		}
		}
		*/
		gain += Entropy(surv, total);
		for (int i = 0; i <= MaxSize - 1; i++)
		{
			if (!Tsitu[i])
			{
				gain -= (double)Tsitu[i] / (double)total*Entropy(Ssitu[i], Tsitu[i]);
			}
		}
		if (maxgain < gain)
		{
			maxgain = gain;
			res = k;
		}
	}
	return maxgain + res;
}
double Gain::Entropy(int surv, int total)
{
	double x1 = (double)surv / (double)total;
	return -x1 * log2(x1) - (1 - x1)*log2(1 - x1);
}
Gain::~Gain()
{
}
