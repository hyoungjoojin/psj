#include <algorithm>
#include <iostream>
#include <vector>

bool solution(const std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int &number : numbers) {
    std::cin >> number;
  }

  std::sort(numbers.begin(), numbers.end());

  int m = 0, target = 0;
  std::cin >> m;

  while (m--) {
    std::cin >> target;
    std::cout << solution(numbers, target) << '\n';
  }
}

bool solution(const std::vector<int> &numbers, int target) {
  return std::binary_search(numbers.begin(), numbers.end(), target);
}
