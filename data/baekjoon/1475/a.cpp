#include <algorithm>
#include <array>
#include <iostream>

int solution(int);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::cout << solution(n) << '\n';

  return 0;
}

int solution(int n) {
  std::array<int, 10> counts = {0};
  while (n) {
    counts[n % 10]++;
    n /= 10;
  }

  counts[6] += counts[9];
  counts[6] = (counts[6] / 2) + (counts[6] % 2);
  counts[9] = 0;

  return *std::max_element(counts.cbegin(), counts.cend());
}
