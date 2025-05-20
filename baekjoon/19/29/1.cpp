#include <iostream>
#include <vector>

const int INPUT_MAX = 1000000;

void solution(int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  solution(n, m);

  return 0;
}

void solution(int n, int m) {
  std::vector<bool> is_prime(INPUT_MAX + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= m; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i + i; j <= m; j += i) {
      is_prime[j] = false;
    }
  }

  for (int i = n; i <= m; i++) {
    if (is_prime[i]) {
      std::cout << i << '\n';
    }
  }
}
