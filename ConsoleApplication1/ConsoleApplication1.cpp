// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

vector <vector<string>> state;

int _tmain(int argc, _TCHAR* argv[])
{
	frein(state,"train.csv");//get data in
	trans translator;
	vector<vector<int>> nstate=translator.tranform(state);
	for (int i = 0; i <= 10; i++)
	{
		for(int j=0;j<=10;j++)
			cout << nstate[i][j] << " ";
		cout << endl;
	}
	//datatrans(state);//translate to simple form
//	calcurela;
//	DTree t1;
//	pickmostregul;in Pclass\Sex\Embark
//	relate word:SibSp\Parch
	return 0;
}