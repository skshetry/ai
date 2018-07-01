#include <iostream>
#include "graph.h"

int main() {
  Graph<int> graph(9);

  Node<int>* node = new Node<int>;

  graph.add_edge(node);
  graph.add_edge(node, graph.head);

  Node<int>* node1 = new Node<int>(3);
  Node<int>* node2 = new Node<int>(4);

  graph.add_edge(node, node2);
  graph.add_edge(node, node1);
  graph.add_edge(graph.head, node2);

  Node<int>* node3 = new Node<int>(11);

  graph.add_edge(node2, node3);

  Node<int>* node4 = new Node<int>(100);

  graph.add_edge(node3, node4);
  graph.add_edge(node4, graph.head);
  graph.add_edge(graph.head, node4);

  graph.bfs(node);
  graph.dfs(node);

  return 0;
}
