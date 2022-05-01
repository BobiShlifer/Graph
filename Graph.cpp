#include "Graph.h"
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

Graph::Graph() {};

istream& operator >> (std::istream& in, Graph& g)
{
	int size;
	int tmp;
	int index;
	int length;
	int i, j;
	in >> size;
	g.vertex.clear();
	for (i = 0; i < size; ++i) {
		in >> index >> length;
		set <int> row;
		for (j = 0; j < length; ++j) {
			in >> tmp;
			row.insert(tmp); // добавляем в строку вершину
		  	}
		g.vertex[index] = row; // добавляем строку в список смежности
	}			
	return in;
}

ostream& operator << (ostream& out, const Graph& g) {
	size_t i, j;
	for (auto i = g.vertex.begin(); i != g.vertex.end(); ++i) {
		out << i->first << ": "; // выводим вершину
		for (auto j = i->second.begin(); j != i->second.end(); ++j) {
			out << *j << ",";
		}
		out << endl;
	}
	return out;
}

void Graph::_dfs(int start, map <int, vector<int>> &paths, vector<int> &current_path, set<int> &current_path_set) {
	if (current_path_set.find(start) != current_path_set.end())
		return; // против цикла
	current_path.push_back(start);
	current_path_set.insert(start);
	if (paths.find(start) == paths.end()) // если вершину не нашли в списке путей
		paths[start] = current_path;
	for (auto i = vertex[start].begin(); i != vertex[start].end(); ++i)
		_dfs(*i, paths, current_path, current_path_set);
	current_path.pop_back();
	auto p = current_path_set.find(start);
			current_path_set.erase(p);
}

map <int, vector <int>> Graph::dfs(int start) {
	map <int, vector <int>> paths;
	vector<int> current_path;
	set<int> current_path_set;
	if (vertex.find(start) != vertex.end())
		_dfs(start, paths, current_path, current_path_set);
	return paths;
}

void Graph::out_paths(ostream& out, map <int, vector <int>> paths) {
	for (size_t i = 0; i < vertex.size(); ++i) {
		out << i << ": ";
		if (paths.find(i) == paths.end()) // если пути нет
			out << "Not available" << endl;
		else {			
			for (size_t k = 0; k < paths[i].size(); ++k) {
				out << paths[i][k];
				if(k != paths[i].size() - 1)
					out << " -> ";
			}
			out << endl;
		}
	}
}