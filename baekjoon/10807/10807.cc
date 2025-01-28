#include <iostream>
#include <vector>

int solution(const std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &number : array) {
    std::cin >> number;
  }

  int target = 0;
  std::cin >> target;

  std::cout << solution(array, target) << '\n';

  return 0;
}

int solution(const std::vector<int> &array, int target) {
  int count = 0;
  for (int number : array) {
    if (number == target) {
      count++;
    }
  }

  return count;
}
