#include "GraphCalculator.h"
#include "set"

GraphCalculator::GraphCalculator(Graph * i_graph)
{
  graph = i_graph;
  color_number = graph->get_vertices().size();
  change_history.reserve(graph->get_vertices().size());

  for (int i = 0; i < graph->get_vertices().size(); i++) {
    change_history.push_back(stack<int>());
    vertex_colors.push_back(1);
  }
}

void GraphCalculator::calculate()
{
  go_over_vertex_colors(0);

  for (int i = 0; i < graph->get_vertices().size(); i++) {
    graph->get_vertex(i).set_color(best_colors[i]);
  }
}

int GraphCalculator::go_over_vertex_colors(int vertex_number)
{
  if (vertex_number >= graph->get_vertices().size()) {
    return -1;
  }

  for (int i = 0; i < graph->get_vertices().size(); i++) {
    increment_vertex_color(vertex_number);
    go_over_vertex_colors(vertex_number + 1);
  }

  vertex_colors[vertex_number] = 1;
}


void GraphCalculator::increment_vertex_color(int vertex_number)
{
  auto old_color = vertex_colors[vertex_number];
  
  change_history[vertex_number].push(old_color);

  vertex_colors[vertex_number]++;
  
  if (graph->check_set_of_colors(vertex_colors)) {
    int used_colors_count = count_colors();

    if (used_colors_count < color_number) {
      color_number = used_colors_count;
      best_colors = vertex_colors;
    }
  }
}

int GraphCalculator::count_colors()
{
  set<int> used_colors;

  for (auto color : vertex_colors) {
    used_colors.insert(color);
  }

  return used_colors.size();
}