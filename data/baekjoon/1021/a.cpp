#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int solution(int, std::vector<int> &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, m = 0;
  std::cin >> n >> m;

  std::vector<int> target(m);
  for (int &i : target) {
    std::cin >> i;
  }

  std::cout << solution(n, target) << '\n';

  return 0;
}

int solution(int n, std::vector<int> &target) {
  std::deque<int> deque;
  for (int i = 1; i <= n; i++) {
    deque.push_back(i);
  }

  int result = 0;
  unsigned long ops = 0;

  for (int t : target) {
    while (true) {
      if (!deque.empty() && t == deque.front()) {
        deque.pop_front();

        result += std::min(deque.size() - ops + 1, ops);
        ops = 0;
        break;
      }

      deque.push_back(deque.front());
      deque.pop_front();
      ops++;
    }
  }

  return result;
}
