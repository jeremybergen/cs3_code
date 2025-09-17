#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Graph
{
    private:
        vector<vector<int>> _adjMatrix;
    public:
        Graph(int n);
        void addEdge(int u, int v);
        void print();
};

Graph::Graph(int n)
{
    _adjMatrix = vector<vector<int>>(n, vector<int>(n, 0));
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