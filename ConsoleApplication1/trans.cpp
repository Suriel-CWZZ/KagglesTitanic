#include "trans.h"
#include "stdafx.h"


trans::trans() :translist(20), extranslist(20){}
trans::~trans(){}
/*void trans::transet( string& sour,  int dest)
{
	transpair temp = { sour, dest };
	//!
}*/
int trans::carrytrans(string& dest)
{
/*	for (int i = translist.size() - 1; i > 0; i--)
	{
		if (dest == translist[i][0])
		{
			dest = translist[i][1]; 
			return 0;
		}
	}*/
	return 1;
}
vector<vector<int>> trans::tranform(vector<vector<string>>state)
{
	int counter[20] = { 0 };
	for (unsigned int line = 1; line < state.size(); line++)
	{
		vector<int> tempres;
		for (unsigned int column = 0; column < state[line].size(); column++)
		{
			if (translist[column][state[line][column]] != 0)
				tempres.push_back(translist[column][state[line][column]]);
			else
			{
				const char *_Ptr = state[line][column].c_str();
				char *_Eptr;
				long double _Ans = _CSTD _STRTO_LD(_Ptr, &_Eptr);
				if (_Ptr == _Eptr)
				{
					tempres.push_back(translist[column][state[line][column]] = counter[column]);
					extranslist[column][counter[column]] = state[line][column];
					counter[column]++;
				}
				else
				{
					tempres.push_back(translist[column][state[line][column]] = stold(state[line][column]));
					extranslist[column][stold(state[line][column])] = state[line][column];
				}
			}
		}
		transres.push_back(tempres);
	}
	return transres;
}