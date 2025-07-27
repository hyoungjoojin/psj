#include <array>
#include <iostream>

void solution(int a, int b, int c);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;

  solution(a, b, c);

  return 0;
}

void solution(int a, int b, int c) {
  long long product = a * b * c;

  std::array<size_t, 10> counts = {0};
  while (product) {
    counts[product % 10]++;
    product /= 10;
  }

  for (size_t count : counts) {
    std::cout << count << '\n';
  }
}
