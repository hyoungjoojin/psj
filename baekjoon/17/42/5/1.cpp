#include <climits>
#include <iostream>
#include <vector>

const int INPUT_MAX = 1000000;

void init();
std::vector<long long> solution(INPUT_MAX + 1, 0);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  init();

  int t = 0;
  std::cin >> t;

  int n = 0;
  while (t--) {
    std::cin >> n;
    std::cout << solution[n] << '\n';
  }

  return 0;
}

void init() {
  for (int i = 1; i <= INPUT_MAX; i++) {
    for (int j = i; j <= INPUT_MAX; j += i) {
      solution[j] += i;
    }
  }

  for (int i = 1; i <= INPUT_MAX; i++) {
    solution[i] += solution[i - 1];
  }
}
