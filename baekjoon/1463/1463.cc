#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int solution(int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}

int solution(int n) {
  std::vector<int> num_operations(n + 1, std::numeric_limits<int>::max());
  num_operations[1] = 0;

  for (int i = 1, double_i = 2, triple_i = 3; i < n;
       i++, double_i = (i + i), triple_i = (i + double_i)) {
    if (double_i <= n) {
      num_operations[double_i] =
          std::min(num_operations[double_i], num_operations[i] + 1);
    }

    if (triple_i <= n) {
      num_operations[triple_i] =
          std::min(num_operations[triple_i], num_operations[i] + 1);
    }

    num_operations[i + 1] =
        std::min(num_operations[i + 1], num_operations[i] + 1);
  }

  return num_operations[n];
}
