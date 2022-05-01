#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;
class Graph
{
private:
	map <int, set<int>> vertex;
	void _dfs(int start, map <int, vector<int>>& paths, vector<int> &current_path, set<int> &current_path_set); 
public: 
	Graph();
	friend istream& operator >> (istream& in, Graph& g); // чтение 
	friend ostream& operator << (ostream& out, const Graph& g); // запись 
	map <int, vector <int>> dfs(int start);
	void out_paths(ostream& out, map <int, vector <int>> paths);
};

#endif GRAPH_H