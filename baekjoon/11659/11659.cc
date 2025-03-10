#include <iostream>
#include <vector>

long solution(const std::vector<long> &, int, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<long> cumsum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> cumsum[i];
    cumsum[i] += cumsum[i - 1];
  }

  int i = 0, j = 0;
  while (m--) {
    std::cin >> i >> j;
    std::cout << solution(cumsum, i, j) << '\n';
  }

  return 0;
}

long solution(const std::vector<long> &cumsum, int i, int j) {
  return cumsum[j] - cumsum[i - 1];
}
