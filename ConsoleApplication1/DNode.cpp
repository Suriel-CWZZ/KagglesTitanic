#include "stdafx.h"
#include "DNode.h"
#include <cmath>

DNode::DNode(vector<vector<string>> initstate)
{
	state = initstate;
}

void DNode::setpar(DNode* p)
{
	pnod = p;
}

/*double DNode::gaincalI(int column)
{
	int Ssitu[MaxSize] = { 0 }, Tsitu[MaxSize] = { 0 }, total=0,surv=0;
	double entropy[MaxSize],gain=0;
	for (int i = 1; i <= state.size() - 1; i++)
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
	
	gain += Entropy(surv, total);
	for (int i = 0; i <= MaxSize - 1; i++)
	{
		if (!Tsitu[i])
		{
			gain -= (double)Tsitu[i]/(double)total*Entropy(Ssitu[i], Tsitu[i]);
		}
	}
	return gain;
}*/
/*
double DNode::gaincalL(int column)
{
	vector<vector<string>> tempstate(state);
	int min = stoi(tempstate[1][column],0,10), max = stoi(tempstate[1][column],0,10),res;
	double maxgain = 0;
	for (int i = 2; i <= tempstate.size() - 1;i++)
	{
		if (stoi(tempstate[i][column], 0, 10) > max)
			max = stoi(tempstate[i][column], 0, 10);
		if (stoi(tempstate[i][column], 0, 10) < min)
			min = stoi(tempstate[i][column], 0, 10);
	}
	for (int k = min + 1; k < max; k++)
	{
		for (int i  = 1; i <= tempstate.size() - 1; i++)
		{
			if (stoi(tempstate[i][column], 0, 10) > k)
				tempstate[i][column] = "1";
			else
				tempstate[i][column] = "0";
		}
		int Ssitu[MaxSize] = { 0 }, Tsitu[MaxSize] = { 0 }, total = 0, surv = 0;
		double entropy[MaxSize], gain = 0;
		for (int i = 1; i <= tempstate.size() - 1; i++)
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
			for (int i = 0; i <= MaxSize - 1; i++)
		{
		if (!Tsitu[i])
		{
		total += Tsitu[i];
		surv += Ssitu[i];
		entropy[i] = Entropy(Ssitu[i], Tsitu[i]);
		}
		}
		
		gain += Entropy(surv, total);
/*		for (int i = 0; i <= MaxSize - 1; i++)
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
	return maxgain+res;
}
*/
void DNode::divnode(int column, double div)
{
	vector<vector<string>> ystate,nstate;
	for (int i = 1; i < 10; i++)//!
	{
		stoi(state[i][column]) - div>=0;
	}
	/*
	int *Again=new int[n],k;
	double maxg = 0;
	for (int i = 0; i < n; i++)
	{
		int cla = 1;
		if (A[i] == 5 || A[i] == 9)//这里极不稳定，设定第5、9列为线性数据列,使用线性gain分析
			cla = 0;
		double gain = gaincal(A[i], cla);
		int l = gain;
		if (gain-l - maxg > 0)
		{
			maxg = gain;
			k = i;
		}
	}
	for (int i = k+1; i < n;i++)
	{
		A[i - 1] = A[i];
	}*/
	ychl = new DNode(state);
	nchl = new DNode(state);
	ychl->setpar(this);
	nchl->setpar(this);
}



DNode::~DNode()
{
}
