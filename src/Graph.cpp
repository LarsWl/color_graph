#include "Graph.h"
#include <algorithm>
#include <set>

Graph::Graph (int N, vector<vector<int>> & adjencency_matrix)
{
    vertices.reserve(N);

    for (int i = 0; i < N; i++) {
        auto vertex = Vertex(i, 0, 0, N);

        vertices.push_back(vertex);

        vector<Vertex*> adjacent_vector;

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
    colors.push_back(1);
}

// bool Graph::is_connected (int first_vertex_number, int second_vertex_number)
// {
//     auto first_vertex_adjacent_vertices = get_vertex(first_vertex_number).get_adjacent_vertices();
//     auto search_number_iterator = find(first_vertex_adjacent_vertices.begin(), 
//                                        first_vertex_adjacent_vertices.end(), second_vertex_number);

//     return search_number_iterator != first_vertex_adjacent_vertices.end();
// }

void Graph::add_edge (int first_vertex_number, int second_vertex_number)
{
    auto & first_vertex = get_vertex(first_vertex_number);
    auto & second_vertex = get_vertex(second_vertex_number);

    auto first_vertex_adjacent_vertices = adjecency.find(first_vertex_number);
    auto second_vertex_adjacent_vertices = adjecency.find(second_vertex_number);

    first_vertex_adjacent_vertices->second.push_back(&second_vertex);
    second_vertex_adjacent_vertices->second.push_back(&first_vertex);

    first_vertex.increment_degree();
    second_vertex.increment_degree();
}

map<int, vector<Vertex*>> & Graph::get_adjeceny()
{
    return adjecency;
}

Vertex & Graph::get_vertex(int number)
{
    for (auto & vertex : vertices) {
        if (vertex.get_number() == number) {
            return vertex;
        }
    }
}



// АЛГОРИТМЫ

void Graph::calculate_color_number_greedy()
{
    vertices.sort(vertices.begin(), vertices.end());

    for(auto & vertix : vertices) {
        auto adjacent_vector = adjecency.find(vertix.get_number())->second;
        set<int> adjacent_colors;

        for (auto vertex : adjacent_vector) {
            auto vertex_color = vertex->get_color();

            if (adjacent_colors.find(vertex_color) != adjacent_colors.end()) {
                adjacent_colors.insert(vertex_color);
            }
        }
        for(auto color : colors) {
            if (adjacent_colors.find(color) != adjacent_colors.end()) {
                vertix.set_color(color);
                break;
            }
        }

        if (vertix.get_color() < 1) {
            int new_color = colors.size() + 1;
            colors.push_back(new_color);
            vertix.set_color(new_color);
        }

    }
}

