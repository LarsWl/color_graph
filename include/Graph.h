#include <iostream>
#include <vector>
#include <map>
#include "Vertex.h"
#include <fstream>

using namespace std;

class Graph
{
    vector<Vertex> vertices;
    vector<int> vertex_colors;
    map<int, vector<int>> adjecency; // Смежные цвета. Ключ - номер вершины. Значение вектор номеров вершин
    vector<int> colors;
    
public:
    Graph (int N, vector<vector<int>> & adjencency_matrix);
    Graph (ifstream & file_with_matrix);

    bool is_connected (int first_vertex_number, int second_vertex_number);
    void add_edge (int first_vertex_number, int second_vertex_number);
    void refresh_adjecency();
    bool is_full_colorized();

    void calculate_color_number_greedy();
    void calculate_color_number_greedy_by_lectures();
    void calculate_color_number_by_coords();

    vector<Vertex> & get_vertices();
    Vertex & get_vertex(int number);
    map<int, vector<Vertex*>> & get_adjecency();

    vector<Vertex&> get_adjence_vertex(int vertex_number);
    void sort_vertices();
    void sort_vertices_by_uncolor_neighbors_degree();
    bool compare_uncolor_neighbors_degree(const Vertex& a, const Vertex& b);
    int compute_uncolor_neighbors_degree(int vertex_number);
    bool check_set_of_colors(vector<int> colors);
    bool check_vertex_color(int vertex_number, int color);
};
