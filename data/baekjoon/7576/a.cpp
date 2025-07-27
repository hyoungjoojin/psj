#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int solution(const std::vector<std::vector<int>> &, int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int rows = 0, cols = 0;
  std::cin >> cols >> rows;

  std::vector<std::vector<int>> grid(rows, std::vector<int>(cols));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      std::cin >> grid[r][c];
    }
  }

  std::cout << solution(grid, rows, cols) << '\n';

  return 0;
}

int solution(const std::vector<std::vector<int>> &grid, int rows, int cols) {
  std::queue<std::pair<int, int>> queue;
  std::vector<std::vector<int>> days(rows, std::vector<int>(cols, -1));

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == 1) {
        queue.push({r, c});
        days[r][c] = 0;
      } else if (grid[r][c] == -1) {
        days[r][c] = 0;
      }
    }
  }

  std::pair<int, int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!queue.empty()) {
    auto [r, c] = queue.front();
    queue.pop();

    int current_day = days[r][c];

    for (const auto &[dr, dc] : d) {
      int r_next = r + dr, c_next = c + dc;

      if (r_next < 0 || r_next >= rows || c_next < 0 || c_next >= cols) {
        continue;
      }

      if (grid[r_next][c_next] != 0 || days[r_next][c_next] != -1) {
        continue;
      }

      queue.push({r_next, c_next});
      days[r_next][c_next] = current_day + 1;
    }
  }

  int count = 0, max = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (days[r][c] != -1) {
        count++;
        max = std::max(max, days[r][c]);
      }
    }
  }

  return count == rows * cols ? max : -1;
}
