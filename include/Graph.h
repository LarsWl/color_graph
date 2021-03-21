#include <iostream>
#include <vector>
#include <map>
#include "Vertex.h"

using namespace std;

class Graph
{
    vector<Vertex> vertices;
    vector<pair<int, int> > adjecency;
    int color_number;
    
public:
    Graph (int N, vector<vector<int>> & adjencency_matrix);
    bool is_connected (int first_vertex_number, int second_vertex_number) const;
    void add_edge (int V1, int V2);

    void calculate_color_number_greedy();

    Vertex & get_vertex(int number) const;
};
