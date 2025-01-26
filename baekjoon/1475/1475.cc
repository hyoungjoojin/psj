#include <algorithm>
#include <array>
#include <iostream>

unsigned short solution(int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}

unsigned short solution(int n) {
  std::array<unsigned short, 10> count = {0};
  while (n) {
    count[n % 10]++;
    n /= 10;
  }

  count[6] += count[9];
  count[6] = count[6] / 2 + count[6] % 2;
  count[9] = 0;

  return *std::max_element(count.begin(), count.end());
}
