#include "Graph.h"
#include <algorithm>
#include <set>

Graph::Graph (int N, vector<vector<int>> & adjencency_matrix)
{
    vertices.reserve(N);
    vertex_colors.reserve(N);

    for (int i = 0; i < N; i++) {
        vertices.push_back(i);

        vector<int> adjacent_vector;

        adjecency.insert({i, adjacent_vector});
    }

    for(int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (adjencency_matrix[i][j] == 1) {
                add_edge(i, j);
            }
        }
    }

    colors.reserve(10);
}

Graph::Graph (ifstream & file_with_matrix)
{
    int vertices_size;
    file_with_matrix >> vertices_size;

    vertices.reserve(vertices_size);
    vertex_colors.reserve(vertices_size);
    vertex_degrees.reserve(vertices_size);

    cout << vertices_size << " " << endl;

    for (int i = 0; i < vertices_size; i++) {
        vertex_colors.push_back(0);
        vertex_degrees.push_back(0);
        vertices.push_back(i);

        vector<int> adjacent_vector;

        adjecency.insert({i, adjacent_vector});
    }

    int edge_size = 0;
    file_with_matrix >> edge_size;

    for(int i = 0; i < edge_size; i++) {
        int vertex_one, vertex_two;
        file_with_matrix >> vertex_one >> vertex_two;

        add_edge(vertex_one, vertex_two);
    }

    colors.reserve(10);
}

vector<int> & Graph::get_vertices() {
    return vertices;
}



// Добавляем сразу в вектор адресов смежных вершин и в вектор номеров смежных вершин.
void Graph::add_edge (int first_vertex_number, int second_vertex_number)
{
    auto first_vertex_adjacent_verticies = adjecency.find(first_vertex_number);
    auto second_vertex_adjacent_verticies = adjecency.find(second_vertex_number);

    first_vertex_adjacent_verticies->second.push_back(second_vertex_number);
    second_vertex_adjacent_verticies->second.push_back(first_vertex_number);

    vertex_degrees[first_vertex_number]++;
    vertex_degrees[second_vertex_number]++;
}

bool Graph::is_full_colorized()
{
    for(auto color : vertex_colors) {
        if (color < 1) return false;
    }

    return true;
}

// АЛГОРИТМЫ

// Жадный алгоритм по лекциям
void Graph::calculate_color_number_greedy_by_lectures()
{
    do {
        sort(vertices.begin(), vertices.end(), [this](const int a, const int b) {
            return vertex_degrees[a] > vertex_degrees[b];
        });

        int color = colors.size() + 1;
        colors.push_back(color);

        cout << "color: " << color << endl;
        
        for(auto & vertex : vertices) {
            if (vertex_colors[vertex] >= 1) continue;

            auto adjacent_verticies = adjecency.find(vertex)->second;

            bool can_set_color = true;

            for(auto adjacent_vertex : adjacent_verticies) {
                if (vertex_colors[adjacent_vertex] == color) {
                    can_set_color = false;
                    break;
                }
            }

            // Если текущего нет, то красим
            if (can_set_color) {
                vertex_colors[vertex] = color;
                
                // Уменьшаем степени смежных вершин так как текущую можно уже не считать
                for (auto adjacent_vertex : adjacent_verticies) {
                    vertex_degrees[adjacent_vertex]--;
                }
            }
        }
    } while (!is_full_colorized());
}

// Проверка на пригодность цвета вершины
bool Graph::check_vertex_color(int vertex_number, int color)
{
    auto adjacment_vector = adjecency.find(vertex_number)->second;

    for (auto adjacment_vertex : adjacment_vector) {
        if (vertex_colors[adjacment_vertex] == color) return false;
    }

    return true;
}

