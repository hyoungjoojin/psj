#include <iostream>

void solution(int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}

void solution_recursive(int n, int start, int end) {
  if (n == 1) {
    std::cout << start << ' ' << end << '\n';
    return;
  }

  solution_recursive(n - 1, start, 6 - start - end);
  solution_recursive(1, start, end);
  solution_recursive(n - 1, 6 - start - end, end);
}

void solution(int n) {
  std::cout << (1 << n) - 1 << '\n';

  solution_recursive(n, 1, 3);
}
