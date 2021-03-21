#include <iostream>
#include <Graph.h>
#include <vector>

int main ()
{
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}};

    Graph graph = Graph(4, matrix);

    std::cout << "here" << std::endl;

    std::cout<< "0: " << graph.get_vertex(0).get_degree() <<  std::endl;
    std::cout<< "2: " << graph.get_vertex(2).get_degree() <<  std::endl;

    if (graph.get_vertex(0) < graph.get_vertex(2)) {
        std::cout << "Its correct" <<std::endl;
    } else {
        std::cout << "Its incorrect" <<std::endl;
    }

    for (auto vertex : graph.get_adjeceny().find(0)->second) {
        std::cout<< graph.get_adjeceny().find(0)->second.size() <<  std::endl;
        std::cout<< vertex->get_number() << ": " << vertex->get_degree() <<  std::endl;
    }

    return 0;
}
