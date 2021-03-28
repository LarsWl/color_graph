#include <iostream>
#include <vector>
#include <map>
#include "Vertex.h"
#include <fstream>

using namespace std;

class Graph
{
    vector<Vertex> vertices;
    map<int, vector<Vertex*>> adjecency; // Смежные вершины
    vector<int> colors;

    map<int, vector<int>> adjecency_with_vertex_numbers; // Смежные вершины, но через номера. Так как адреса могут путаться и меняться
    
public:
    Graph (int N, vector<vector<int>> & adjencency_matrix);
    Graph (ifstream & file_with_matrix);

    bool is_connected (int first_vertex_number, int second_vertex_number);
    void add_edge (int first_vertex_number, int second_vertex_number);
    void refresh_adjecency();
    bool is_full_colorized();

    void calculate_color_number_greedy();
    void calculate_color_number_greedy_by_lectures();

    vector<Vertex> & get_vertices();
    Vertex & get_vertex(int number);
    map<int, vector<Vertex*>> & get_adjecency();

    vector<Vertex&> get_adjence_vertex(int vertex_number);
    void sort_vertices();
    void sort_vertices_by_uncolor_neighbors_degree();
    bool compare_uncolor_neighbors_degree(const Vertex& a, const Vertex& b);
    int compute_uncolor_neighbors_degree(int vertex_number);
};
