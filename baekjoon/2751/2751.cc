#include <algorithm>
#include <iostream>
#include <vector>

void solution(std::vector<int> &);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (auto &number : numbers) {
    std::cin >> number;
  }

  solution(numbers);
  for (const auto &number : numbers) {
    std::cout << number << '\n';
  }

  return 0;
}

void solution(std::vector<int> &numbers) {
  std::sort(numbers.begin(), numbers.end());
}
