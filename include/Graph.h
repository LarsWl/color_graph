#include <iostream>
#include <vector>
#include <map>
#include "Vertex.h"
#include <fstream>

using namespace std;

class Graph
{
    vector<int> vertices;
    vector<int> vertex_colors;
    vector<int> vertex_degrees;
    map<int, vector<int>> adjecency; // Смежные цвета. Ключ - номер вершины. Значение вектор номеров вершин
    vector<int> colors;
    
public:
    Graph (int N, vector<vector<int>> & adjencency_matrix);
    Graph (ifstream & file_with_matrix);

    void add_edge (int first_vertex_number, int second_vertex_number);
    bool is_full_colorized();

    void calculate_color_number_greedy_by_lectures();

    vector<int> & get_vertices();
    vector<Vertex&> get_adjence_vertex(int vertex_number);
    
    bool check_vertex_color(int vertex_number, int color);
};
