#include <iostream>

long long solution(int);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';
}

long long solution(int n) {
  if (n < 2) {
    return n;
  }

  long long left = 0, right = 1, temp = 0;
  for (int i = 2; i < n; i++) {
    temp = right;
    right = left + right;
    left = temp;
  }

  return left + right;
}
