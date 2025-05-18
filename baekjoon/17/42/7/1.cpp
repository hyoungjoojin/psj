#include <iostream>

long long solution(int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}

long long solution(int n) {
  long long result = 0;
  for (int i = 1; i <= n; i++) {
    result += (i * (n / i));
  }

  return result;
}
