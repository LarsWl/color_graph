#include "Graph.h"
#include <algorithm>

Graph::Graph (int N, vector<vector<int>> & adjencency_matrix)
{
    vertices.reserve(N);

    for (int i = 0; i < N; i++) {
        auto vertex = Vertex(i, -1, 0);

        vertices.push_back(vertex);
    }

    adjecency.reserve(N * 2);

    for(int i = 0; i < N; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (adjencency_matrix[i][j] == 1) {
                add_edge(i, j);
            }
        }
    }

    color_number = 0;
}

bool Graph::is_connected (int first_vertex_number, int second_vertex_number) const
{
    auto need_pair = find(adjecency.begin(), adjecency.end(), pair<int, int>(first_vertex_number, second_vertex_number));

    return need_pair != adjecency.end();
}

void Graph::add_edge (int first_vertex_number, int second_vertex_number)
{
   adjecency.push_back(pair<int, int>(first_vertex_number, second_vertex_number));
   adjecency.push_back(pair<int, int>(second_vertex_number, first_vertex_number));
   get_vertex(first_vertex_number).increment_degree();
   get_vertex(second_vertex_number).increment_degree();

   std::cout<< first_vertex_number << ": " << get_vertex(first_vertex_number).get_degree() <<  std::endl;
   std::cout<< second_vertex_number << ": " << get_vertex(second_vertex_number).get_degree() <<  std::endl;

   std::cout << std::endl;
}

Vertex & Graph::get_vertex(int number) const
{
    std::cout << "get vertex " << number << std::endl;

    for (auto vertex : vertices) {
        std::cout << vertex.get_number() << " : " << number << std::endl;
        if (vertex.get_number() == number) {
            return vertex;
        }
    }
}


// АЛГОРИТМЫ

// void calculate_color_number_greedy()
// {
//     int a=1;
//     myVector.sort(myGraph.begin(), myGraph.end(), Compare());
//         /*
//         for (int i=0; i<G.get_length(); i++)
//         {
//             q.push(myGraph[i]);
//         }
//         */
//     i=0;
//     while (!myGraph.empty())
//     {
//         map <int, int> color_a;
//         if (myGraph[i].get_color()==0)
//         {
//             myGraph[i].set_color(a);
//             color_a.insert(i, 1);
//         }
//         i++;
//         for (int j=i; j<myGraph.size(); j++)
//         {
//             if (myGraph[j].get_color()==0 && color_a.find(j)==color_a.end())
//             {
//                 myGraph[j].set_color(a);
//                 color_a.insert(j, 1);
//             }
//         }
//         a++;
//    }
// }

