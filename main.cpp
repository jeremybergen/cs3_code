#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.print();
    cout << endl;

    g.dfs(5);
    cout << endl;
    g.printVisited();
    return 0;
}