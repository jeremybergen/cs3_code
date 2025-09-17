#pragma once
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph
{
    private:
        // vector<vector<int>> _adjMatrix;
        vector<list<int>> _adjList;
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
    // _adjMatrix = vector<vector<int>>(n, vector<int>(n, 0));
    _adjList = vector<list<int>>(n);
    _visited = vector<bool>(n, false);
}

void Graph::addEdge(int u, int v)
{
    // _adjMatrix.at(u).at(v) = 1;
    // _adjMatrix.at(v).at(u) = 1;
    _adjList.at(u).push_back(v);
    _adjList.at(v).push_back(u);
}

void Graph::print()
{
    // for(size_t i = 0; i < _adjMatrix.size(); i++)
    // for(size_t i = 0; i < _adjList.size(); i++)
    // {
    //     for(size_t j = 0; j < _adjList.size(); j++)
    //     {
    //         cout << _adjList.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    for(size_t i = 0; i < _adjList.size(); i++)
    {
        for(auto it = _adjList.at(i).begin(); it != _adjList.at(i).end(); it++)
        {
            cout << *it << " ";
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
    _visited = vector<bool>(_adjList.size(), false);

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

    for(auto it = _adjList.at(v).begin(); it != _adjList.at(v).end(); it++)
    {
        if(!_visited.at(*it))
        {
            explore(*it);
        }
    }
    // for(size_t i = 0; i < _adjMatrix.size(); i++)
    // for(size_t i = 0; i < _adjList.size(); i++)
    // {

    //     // if(!_visited.at(i) && _adjList[v][i] == 1)
    //     // {
    //     //     explore(i);
    //     // }
    // }
}