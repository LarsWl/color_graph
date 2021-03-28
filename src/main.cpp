#include <iostream>
#include <Graph.h>
#include <vector>
#include <set>

int main ()
{
    vector<vector<int>> matrix = {
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 0}
        };

    Graph graph = Graph(10, matrix);

    std::cout << "here" << std::endl;
    
    graph.calculate_color_number_greedy_by_lectures();

    std::cout << endl;

    for(auto vertex : graph.get_vertices()) {
        std::cout<< vertex.get_number() << " color: " << vertex.get_color() <<  std::endl;
    }

    return 0;
}
