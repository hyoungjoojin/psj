#include <iostream>
#include <vector>

int solution(const std::vector<int> &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> numbers(n);
  for (int &number : numbers) {
    std::cin >> number;
  }

  std::cout << solution(numbers) << '\n';

  return 0;
}

bool is_prime(int n) {
  bool is_prime = true;

  if (n == 1) {
    is_prime = false;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}

int solution(const std::vector<int> &numbers) {
  int count = 0;

  for (const int &number : numbers) {
    if (is_prime(number)) {
      count++;
    }
  }

  return count;
}
