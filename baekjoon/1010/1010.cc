#include <iostream>
#include <vector>

int solution(int, int);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int num_testcases = 0;
  std::cin >> num_testcases;

  int n = 0, m = 0;
  while (num_testcases--) {
    std::cin >> n >> m;
    std::cout << solution(n, m) << '\n';
  }
}

int solution(int n, int m) {
  std::vector<int> combination(m + 1, -1);
  combination[0] = 1;

  for (int i = 0; i <= m; i++) {
    combination[i] = 1;

    for (int j = i - 1; j > 0; j--) {
      combination[j] = combination[j] + combination[j - 1];
    }
  }

  return combination[n];
}
