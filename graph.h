#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Graph
{
    private:
        vector<vector<int>> _adjMatrix;
        vector<bool> _visited;
    public:
        Graph(int n);
        void addEdge(int u, int v);
        void print();
        void printVisited();

        void dfs(int v);
        void explore(int v);
};

Graph::Graph(int n)
{
    _adjMatrix = vector<vector<int>>(n, vector<int>(n, 0));
    _visited = vector<bool>(n, false);
}

void Graph::addEdge(int u, int v)
{
    _adjMatrix.at(u).at(v) = 1;
    _adjMatrix.at(v).at(u) = 1;
}

void Graph::print()
{
    for(size_t i = 0; i < _adjMatrix.size(); i++)
    {
        for(size_t j = 0; j < _adjMatrix.size(); j++)
        {
            cout << _adjMatrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

void Graph::printVisited()
{
    for(auto elem : _visited)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void Graph::dfs(int v)
{
    _visited.clear();
    _visited = vector<bool>(_adjMatrix.size(), false);

    explore(v);
    for(size_t i = 0; i < _visited.size(); i++)
    {
        if(!_visited.at(i))
        {
            explore(i);
        }
    }
    cout << endl;
}

void Graph::explore(int v)
{
    _visited.at(v) = true;
    cout << v << " ";

    for(size_t i = 0; i < _adjMatrix.size(); i++)
    {
        if(!_visited.at(i) && _adjMatrix[v][i] == 1)
        {
            explore(i);
        }
    }
}