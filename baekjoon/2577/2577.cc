#include <array>
#include <iostream>

std::array<unsigned short, 10> solution(int, int, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;

  for (int count : solution(a, b, c)) {
    std::cout << count << '\n';
  }

  return 0;
}

std::array<unsigned short, 10> solution(int a, int b, int c) {
  std::array<unsigned short, 10> result = {0};

  int product = a * b * c;
  while (product) {
    result[product % 10]++;
    product /= 10;
  }

  return result;
}
