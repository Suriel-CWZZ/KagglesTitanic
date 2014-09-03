
#include "stdafx.h"
#include "readin.h"



void frein(vector <vector<string>>& state, const char* dest, int a , int b )
{
	
	ifstream file(dest);
	writein(state, file);
	file.close();

}

void writein(vector <vector<string>>& state, ifstream& file)
{
	vector <string> A(MAXLEN);
	string s;
	while (file.good()){
		getline(file, s, ',');
		if (s == "")
		{
			break;
		}
		for (int i = 1; i < MAXLEN - 1; i++){
			getline(file, A[i], ',');
		}
		getline(file, A[MAXLEN - 1], '\n');
		state.push_back(A);//注意首行信息也输入进去，即属性
	}
}

