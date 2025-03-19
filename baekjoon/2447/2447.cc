#include <iostream>
#include <string>
#include <vector>

void solution(int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}

void solution_recursive_(std::vector<std::string> &lines, int n, int start,
                         int end) {
  if (n == 3) {
    lines[start] += "***";
    lines[start + 1] += "* *";
    lines[start + 2] += "***";
    return;
  }

  int next_n = n / 3;

  std::string spaces = "";
  for (int i = 0; i < next_n; i++) {
    spaces += ' ';
  }

  // First line
  for (int i = 0; i < 3; i++) {
    solution_recursive_(lines, next_n, start, start + next_n - 1);
  }

  // Second line
  start += next_n;
  solution_recursive_(lines, next_n, start, start + next_n - 1);
  for (int i = start; i < start + next_n; i++) {
    lines[i] += spaces;
  }
  solution_recursive_(lines, next_n, start, start + next_n - 1);

  // Third line
  start += next_n;
  for (int i = 0; i < 3; i++) {
    solution_recursive_(lines, next_n, start, start + next_n - 1);
  }
}

void solution(int n) {
  std::vector<std::string> lines(n, "");
  solution_recursive_(lines, n, 0, n - 1);

  for (const std::string &line : lines) {
    std::cout << line << '\n';
  }
}
