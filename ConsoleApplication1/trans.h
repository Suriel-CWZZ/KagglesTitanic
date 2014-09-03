#pragma once 
#include <vector>
#include <string>
#include <map>

using namespace std;

class trans 
{
public:
	trans();
	~trans();
	vector<vector<int>> tranform(vector<vector<string>>);
	int carrytrans(string&);
private:
	vector < map<string,int> > translist;
	vector<map<int, string>> extranslist;
	vector<vector<int>> transres;

};