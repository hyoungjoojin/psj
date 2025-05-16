#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> divisors(n);
  for (int &divisor : divisors) {
    std::cin >> divisor;
  }

  std::cout << solution(divisors) << '\n';

  return 0;
}

int solution(std::vector<int> &divisors) {
  std::sort(divisors.begin(), divisors.end());
  return divisors[0] * divisors[divisors.size() - 1];
}
