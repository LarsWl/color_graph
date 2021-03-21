#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <Vertex.h>
#include <Graph.h>

using namespace std;

class Compare
{
    public:

    bool operator() (Graph G, Vertex a, Vertex b);
};


class Algorithm
{
public:
    int algorithm(Graph &G);
};
