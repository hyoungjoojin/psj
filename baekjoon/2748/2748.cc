#include <iostream>
#include <vector>

long long solution(unsigned int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned int input = 0;
  std::cin >> input;

  std::cout << solution(input) << '\n';
}

long long solution(unsigned int n) {
  if (n < 2) {
    return n;
  }

  std::vector<long long> fibonacci_array(n + 1, -1);
  fibonacci_array[0] = 0;
  fibonacci_array[1] = 1;

  for (unsigned int i = 2; i <= n; i++) {
    fibonacci_array[i] = fibonacci_array[i - 1] + fibonacci_array[i - 2];
  }

  return fibonacci_array[n];
}
