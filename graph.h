#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

template <typename T>
struct Node {
  std::vector<Node<T> *> adjacents;
  T value;

  Node(T val = {}) : adjacents{}, value(val) {
    std::cout << "Node created with value " << val << " located on: " << this
              << '\n';
  };
};

template <typename T>
struct Graph {
  Node<T> *head;

  Graph(T val) : head(new Node<T>(val)){};

  void add_edge(Node<T> *node1, Node<T> *node2 = nullptr) {
    if (node2 == nullptr) {
      this->head->adjacents.push_back(node1);

      std::cout << "Node with val: " << this->head->value
                << " connected with node having value " << node1->value << '\n';

    } else {
      node1->adjacents.push_back(node2);

      std::cout << "Node with val: " << node1->value
                << " connected with node having value " << node2->value << '\n';
    }
  };

  void bfs(Node<T> *node) {
    std::queue<Node<T> *> n_queue;
    std::vector<Node<T> *> list;

    n_queue.push(node);

    std::cout << "\nBFS: ";

    while (!n_queue.empty()) {
      Node<T> *front = n_queue.front();

      std::cout << front->value << '\t';

      list.push_back(front);

      for (const auto n : front->adjacents) {
        if (std::find(list.begin(), list.end(), n) == list.end()) {
          n_queue.push(n);
        }
      }

      n_queue.pop();
    }
  };

  void dfs(Node<T> *node) {
    std::stack<Node<T> *> n_stack;
    std::vector<Node<T> *> list;

    n_stack.push(node);

    std::cout << "\nDFS: ";

    while (!n_stack.empty()) {
      Node<T> *back = n_stack.top();

      std::cout << back->value << '\t';

      list.push_back(back);

      n_stack.pop();

      for (const auto n : back->adjacents) {
        if (std::find(list.begin(), list.end(), n) == list.end()) {
          n_stack.push(n);
        }
      }
    }
  };
};
