#include <iostream>

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
  if (n == 1)
    return 1;

  if (n == 2)
    return 3;

  int minus_one = 3, minus_two = 1, result = 0;
  for (int i = 2; i < n; i++) {
    result = (minus_one + minus_two + minus_two) % 10007;
    minus_two = minus_one;
    minus_one = result;
  }

  return result;
}
