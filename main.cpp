#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	Graph g;
	int start;
	ifstream fin("list.txt");
	fin >> g >> start;		
	ofstream fout("out_paths.txt");
	g.out_paths(fout, g.dfs(start));
	cout << g << endl;
	return 0;
}
//через шаблоны список смежности, список ребер 
// два класса список смежности и матрица смежности.