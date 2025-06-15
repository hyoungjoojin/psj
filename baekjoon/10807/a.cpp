#include <iostream>
#include <vector>

int solution(const std::vector<int> &, int);

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int &number : numbers) {
    std::cin >> number;
  }

  int target = 0;
  std::cin >> target;

  std::cout << solution(numbers, target) << '\n';

  return 0;
}

int solution(const std::vector<int> &numbers, int target) {
  int count = 0;
  for (int number : numbers) {
    if (number == target) {
      count++;
    }
  }

  return count;
}
