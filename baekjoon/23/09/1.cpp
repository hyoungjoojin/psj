#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

void solution(std::array<int, 9> &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::array<int, 9> numbers;
  for (int &number : numbers) {
    std::cin >> number;
  }

  solution(numbers);

  return 0;
}

void solution(std::array<int, 9> &input) {
  std::sort(input.begin(), input.end());

  int sum = std::reduce(input.begin(), input.end(), 0);

  int i = -1, j = -1, remainder = sum - 100;
  bool pair_found = false;
  for (i = 0; i < 9; i++) {
    for (j = i + 1; j < 9; j++) {
      if (input[i] + input[j] == remainder) {
        pair_found = true;
        break;
      }
    }

    if (pair_found) {
      break;
    }
  }

  for (int k = 0; k < 9; k++) {
    if (k == i || k == j) {
      continue;
    }

    std::cout << input[k] << '\n';
  }
}
