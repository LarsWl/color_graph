#include <vector>
#include <Graph.h>
#include <stack>

class GraphCalculator
{
    vector<stack<int>> change_history;
    vector<int> vertex_colors;
    vector<int> best_colors;
    int color_number;

    void increment_vertex_color(int vertex_number);
    int go_over_vertex_colors(int vertex_number);
    int count_colors();
public:
   GraphCalculator(Graph * i_graph);
   Graph * graph;
   
   void calculate();
};
