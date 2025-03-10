#include <functional>
#include <iostream>
#include <vector>

const std::function<int(int)> operations[3] = {[](int x) { return x + 1; },
                                               [](int x) { return x * 2; },
                                               [](int x) { return x * 3; }};

void solution(int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}

void solution(int n) {
  std::vector<int> count(n + 1, 2 * n);
  std::vector<int> previous(n + 1, 0);

  count[1] = 0;
  for (int i = 1; i <= n; i++) {
    int current_count = count[i];

    for (int j = 0; j < 3; j++) {
      int next_index = operations[j](i);
      if (next_index > n) {
        continue;
      }

      int next_count = current_count + 1;
      if (next_count < count[next_index]) {
        previous[next_index] = i;
        count[next_index] = current_count + 1;
      }
    }
  }

  std::cout << count[n] << '\n';

  int current = n;
  while (current) {
    std::cout << current << ' ';
    current = previous[current];
  }
}
