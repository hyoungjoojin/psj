#include <iostream>

int gcd(int, int);
int lcm(int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0;
  std::cin >> a >> b;

  std::cout << gcd(a, b) << '\n' << lcm(a, b) << '\n';

  return 0;
}

int gcd(int a, int b) {
  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }

  return a;
}

int lcm(int a, int b) { return a * (b / gcd(a, b)); }
