#include <iostream>
#include <vector>
#include <map>
#include "Vertex.h"

using namespace std;

class Graph
{
    vector<Vertex> vertices;
    map<int, vector<Vertex*>> adjecency; // Смежные вершины
    vector<int> colors;
    
public:
    Graph (int N, vector<vector<int>> & adjencency_matrix);
    bool is_connected (int first_vertex_number, int second_vertex_number);
    void add_edge (int first_vertex_number, int second_vertex_number);

    void calculate_color_number_greedy();

    vector<Vertex> & get_vertices();
    Vertex & get_vertex(int number);
    map<int, vector<Vertex*>> & get_adjecency();

    vector<Vertex&> get_adjence_vertex(int vertex_number);
    void sort_vertices();
};
