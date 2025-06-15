#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &, int);

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

int solution(std::vector<int> &numbers, int target) {
  std::sort(numbers.begin(), numbers.end());

  int count = 0, left_index = 0, right_index = numbers.size() - 1;
  while (left_index < right_index) {
    int left = numbers[left_index], right = numbers[right_index];
    int sum = left + right;

    if (sum < target) {
      left_index++;
      continue;
    }

    if (sum > target) {
      right_index--;
      continue;
    }

    for (; numbers[right_index] == right; right_index--) {
      count++;
    }

    left_index++;
  }

  return count;
}
