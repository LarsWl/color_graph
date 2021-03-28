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
        vector<int> adjacent_vector_with_numbers;

        adjecency.insert({i, adjacent_vector});
        adjecency_with_vertex_numbers.insert({i, adjacent_vector_with_numbers});
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

    cout << vertices_size << " " << endl;

    for (int i = 0; i < vertices_size; i++) {
        auto vertex = Vertex(i, 0, 0, vertices_size);

        vertices.push_back(vertex);

        vector<Vertex*> adjacent_vector;
        vector<int> adjacent_vector_with_numbers;

        adjecency.insert({i, adjacent_vector});
        adjecency_with_vertex_numbers.insert({i, adjacent_vector_with_numbers});
    }

    int edge_size = 0;
    file_with_matrix >> edge_size;

    for(int i = 0; i < edge_size; i++) {
        int vertex_one, vertex_two;
        file_with_matrix >> vertex_one >> vertex_two;

        add_edge(vertex_one, vertex_two);

        cout << endl;
    }

    colors.reserve(10);
}

void Graph::add_edge (int first_vertex_number, int second_vertex_number)
{
    auto & first_vertex = get_vertex(first_vertex_number);
    auto & second_vertex = get_vertex(second_vertex_number);

    auto first_vertex_adjacent_vertices = adjecency.find(first_vertex_number);
    auto second_vertex_adjacent_vertices = adjecency.find(second_vertex_number);
    first_vertex_adjacent_vertices->second.push_back(&second_vertex);
    second_vertex_adjacent_vertices->second.push_back(&first_vertex);

    auto first_vertex_adjacent_vertice_numbers = adjecency_with_vertex_numbers.find(first_vertex_number);
    auto second_vertex_adjacent_vertice_numbers = adjecency_with_vertex_numbers.find(second_vertex_number);
    first_vertex_adjacent_vertice_numbers->second.push_back(second_vertex_number);
    second_vertex_adjacent_vertice_numbers->second.push_back(first_vertex_number);

    first_vertex.increment_degree();
    second_vertex.increment_degree();
}

map<int, vector<Vertex*>> & Graph::get_adjecency()
{
    return adjecency;
}

vector<Vertex> & Graph::get_vertices()
{
    return vertices;
}

Vertex & Graph::get_vertex(int number)
{
    for (auto & vertex : vertices) {
        if (vertex.get_number() == number) {
            return vertex;
        }
    }
}

void Graph::refresh_adjecency() 
{
    for (auto & vertex_adjecency : adjecency) {
        auto vertex_numbers = adjecency_with_vertex_numbers.find(vertex_adjecency.first)->second;
        vector<Vertex*> new_adjecency_vector;
        for (auto vertex_number : vertex_numbers) {
            auto & vertex = get_vertex(vertex_number);
            new_adjecency_vector.push_back(&vertex);
        }

        vertex_adjecency.second = new_adjecency_vector;
    }
}

void Graph::sort_vertices()
{
    sort(vertices.begin(), vertices.end());
    reverse(vertices.begin(), vertices.end());
    refresh_adjecency();
}

void Graph::sort_vertices_by_uncolor_neighbors_degree()
{
    sort(vertices.begin(), vertices.end(), [this](const Vertex& a, const Vertex& b) {
        int a_degree = compute_uncolor_neighbors_degree(a.get_number());
        int b_degree = compute_uncolor_neighbors_degree(b.get_number());

        return a_degree < b_degree; 
    });

    refresh_adjecency();
}

int Graph::compute_uncolor_neighbors_degree(int vertex_number)
{
    auto adjacent_vector = adjecency_with_vertex_numbers.find(vertex_number)->second;
    int degree = 0;

    for(auto adjacent_vertex_number : adjacent_vector) {
        auto adjacent_vertex = get_vertex(adjacent_vertex_number);

        if (adjacent_vertex.get_color() < 1) {
            degree += adjacent_vertex.get_degree();
        } 
    }

    return degree;
}

bool Graph::is_full_colorized()
{
    for(auto vertex : vertices) {
        if (vertex.get_color() < 1) return false;
    }

    return true;
}

// АЛГОРИТМЫ

void Graph::calculate_color_number_greedy()
{
    sort_vertices();

    for(auto & vertex : vertices) {
        auto adjacent_vector = adjecency.find(vertex.get_number())->second;
        set<int> adjacent_colors;

        for (auto adjacent_vertex : adjacent_vector) {
            auto vertex_color = adjacent_vertex->get_color();

            if (adjacent_colors.find(vertex_color) == adjacent_colors.end() && vertex_color >= 1) {
                adjacent_colors.insert(vertex_color);
            }
        }

        for(auto color : colors) {
            if (adjacent_colors.find(color) == adjacent_colors.end()) {
                vertex.set_color(color);
                break;
            }
        }

        if (vertex.get_color() < 1) {
            int new_color = colors.size() + 1;
            colors.push_back(new_color);
            vertex.set_color(new_color);
        }
    }
}

void Graph::calculate_color_number_greedy_by_lectures()
{
    do {
        sort_vertices();
        int color = colors.size() + 1;
        colors.push_back(color);
        
        for(auto & vertex : vertices) {
            if (vertex.get_color() >= 1) continue;

            auto adjacent_vector = adjecency.find(vertex.get_number())->second;
            set<int> adjacent_colors;
            
            for (auto adjacent_vertex : adjacent_vector) {
                auto vertex_color = adjacent_vertex->get_color();

                if (adjacent_colors.find(vertex_color) == adjacent_colors.end() && vertex_color >= 1) {
                    adjacent_colors.insert(vertex_color);
                }
            }

            if (adjacent_colors.find(color) == adjacent_colors.end()) {
                vertex.set_color(color);
                
                for (auto adjacent_vertex : adjacent_vector) {
                    adjacent_vertex->set_degree(adjacent_vertex->get_degree() - 1);
                }
            }
        }
    } while (!is_full_colorized());
}

void calculate_color_number_by_coords(vector<int> colors)
{

}

bool Graph::check_set_of_colors(vector<int> colors)
{

    for (auto vertex_adjacment : adjecency_with_vertex_numbers) {
        for (auto vertex_number : vertex_adjacment.second) {
            if (colors[vertex_adjacment.first] == colors[vertex_number]) {
                return false;
            }
        }
    }

    return true;
}

bool Graph::check_vertex_color(int vertex_number, int color)
{
    auto adjacment_vector = adjecency.find(vertex_number)->second;

    for (auto adjacment_vertex : adjacment_vector) {
        if (adjacment_vertex->get_color() == color) return false;
    }

    return true;
}

