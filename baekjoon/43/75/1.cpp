#include <iostream>

int solution(int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  while (std::cin >> n) {
    std::cout << solution(n) << '\n';
  }

  return 0;
}

int solution(int n) {
  int ones_count = 0, target = 0;
  while (target < n) {
    ones_count++;
    target = target * 10 + 1;
  }

  int remainder = target % n;
  while (remainder != 0) {
    ones_count++;
    remainder = (remainder * 10 + 1) % n;
  }

  return ones_count;
}
