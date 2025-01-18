#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> solution(const std::vector<int> &);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (auto &number : numbers) {
    std::cin >> number;
  }

  for (const auto &number : solution(numbers)) {
    std::cout << number << '\n';
  }

  return 0;
}

std::vector<int> solution(const std::vector<int> &numbers) {
  std::vector<int> sorted_numbers(numbers);
  std::sort(sorted_numbers.begin(), sorted_numbers.end());

  return sorted_numbers;
}
