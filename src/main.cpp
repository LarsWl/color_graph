#include <iostream>
#include <fstream>
#include <Graph.h>
#include <vector>
#include <set>

int main (int argc, char *argv[])
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
    

    std::ifstream file;
    file.open(argv[1]);
    Graph graph = Graph(file);
    file.close();

    std::cout << "here" << std::endl;
    
    graph.calculate_color_number_greedy_by_lectures();

    std::cout << endl;

    for(auto vertex : graph.get_vertices()) {
        std::cout<< vertex.get_number() << " color: " << vertex.get_color() <<  std::endl;
    }

    return 0;
}
