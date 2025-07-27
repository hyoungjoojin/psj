#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(const std::vector<std::vector<bool>> &, int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int rows = 0, cols = 0;
  std::cin >> rows >> cols;

  std::vector<std::vector<bool>> grid(rows, std::vector<bool>(cols));

  std::string line = "";
  for (int r = 0; r < rows; r++) {
    std::cin >> line;

    for (int c = 0; c < cols; c++) {
      grid[r][c] = (line[c] == '1');
    }
  }

  std::cout << solution(grid, rows, cols) << '\n';

  return 0;
}

int solution(const std::vector<std::vector<bool>> &grid, int rows, int cols) {
  std::pair<int, int> d[] = {
      {1, 0},
      {0, 1},
      {-1, 0},
      {0, -1},
  };

  std::queue<std::pair<int, int>> queue;
  std::vector<std::vector<int>> distances(rows, std::vector<int>(cols, -1));

  queue.push({0, 0});
  distances[0][0] = 1;

  while (!queue.empty()) {
    const auto [r, c] = queue.front();
    const int distance = distances[r][c];

    queue.pop();

    for (auto [dr, dc] : d) {
      int r_next = r + dr, c_next = c + dc;
      if (r_next < 0 || r_next >= rows || c_next < 0 || c_next >= cols) {
        continue;
      }

      if (!grid[r_next][c_next] || distances[r_next][c_next] != -1) {
        continue;
      }

      distances[r_next][c_next] = distance + 1;
      queue.push({r_next, c_next});
    }
  }

  return distances[rows - 1][cols - 1];
}
