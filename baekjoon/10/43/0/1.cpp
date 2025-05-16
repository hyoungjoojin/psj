#include <iostream>

void solution(int, int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;

  solution(a, b, c);

  return 0;
}

void solution(int a, int b, int c) {
  std::cout << (a + b) % c << '\n';
  std::cout << ((a % c) + (b % c)) % c << '\n';
  std::cout << (a * b) % c << '\n';
  std::cout << ((a % c) * (b % c)) % c << '\n';
}
