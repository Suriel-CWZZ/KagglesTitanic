#pragma once
#include <string>
#include <vector>
class DNode
{
public:
	DNode(vector<vector<string>> initstate);
/*	int gaincal(int column, int cla)
	{
		if (cla)
			return gaincalI(column);
		else
			return gaincalL(column);
	}
	*/
	void divnode(int,double);
	void classify(vector<string> );
	void setpar(DNode*);
	bool judge(vector<string>);
	~DNode();
private:
//	double gaincalI(int);
//	double gaincalL(int);
//	double Entropy(int , int );
	DNode *ychl, *nchl, *pnod;
	string y, n;
	int pointer,Jcolumn;
	vector<vector<string>> state;
};

