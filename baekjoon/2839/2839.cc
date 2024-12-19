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
  for (int num_fives = n / 5, remainder = n - num_fives * 5; num_fives >= 0;
       num_fives--, remainder += 5) {
    if (remainder % 3 == 0) {
      return num_fives + remainder / 3;
    }
  }

  return -1;
}
