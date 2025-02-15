#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
  Graph(int, int);

  int solution() const;

private:
  int num_vertices_;
  int num_edges_;
  std::vector<std::vector<int>> edges_;
};

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_vertices = 0, num_edges = 0;
  std::cin >> num_vertices >> num_edges;

  Graph graph(num_vertices, num_edges);
  std::cout << graph.solution() << '\n';
}

Graph::Graph(int num_vertices, int num_edges)
    : num_vertices_(num_vertices), num_edges_(num_edges),
      edges_(num_vertices_ + 1, std::vector<int>()) {
  int u = 0, v = 0;
  while (num_edges--) {
    std::cin >> u >> v;
    edges_[u].push_back(v);
    edges_[v].push_back(u);
  }
}

int Graph::solution() const {
  std::vector<bool> visited(num_vertices_ + 1, false);
  std::queue<int> queue;

  int num_components = 0;
  for (int i = 1; i <= num_vertices_; i++) {
    if (visited[i]) {
      continue;
    }

    queue.push(i);
    visited[i] = true;

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int adjacent : edges_[front]) {
        if (visited[adjacent]) {
          continue;
        }

        queue.push(adjacent);
        visited[adjacent] = true;
      }
    }

    num_components++;
  }

  return num_components;
}
