#include <array>
#include <functional>
#include <iostream>
#include <vector>

void solution(const std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k = 0;
  while (true) {
    std::cin >> k;
    if (k == 0) {
      break;
    }

    std::vector<int> numbers(k);
    for (int &number : numbers) {
      std::cin >> number;
    }

    solution(numbers, k);
    std::cout << '\n';
  }

  return 0;
}

void solution(const std::vector<int> &numbers, int k) {
  std::array<int, 6> target = {-1};

  auto print_ = [&target]() {
    for (const int &number : target) {
      std::cout << number << ' ';
    }

    std::cout << '\n';
  };

  std::function<void(int, int)> solution_ = [&](int numbers_index,
                                                int target_index) {
    if (target_index == 6) {
      print_();
      return;
    }

    if (numbers_index == k) {
      return;
    }

    target[target_index] = numbers[numbers_index];
    solution_(numbers_index + 1, target_index + 1);
    target[target_index] = -1;

    solution_(numbers_index + 1, target_index);
  };

  solution_(0, 0);
}
