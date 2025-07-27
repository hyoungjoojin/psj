#include <iostream>
#include <stack>
#include <utility>
#include <vector>

long solution(const std::vector<int> &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> heights(n);
  for (int &height : heights) {
    std::cin >> height;
  }

  std::cout << solution(heights) << '\n';

  return 0;
}

long solution(const std::vector<int> &heights) {
  std::stack<std::pair<int, int>> stack;

  long total = 0;
  for (int height : heights) {
    long pairs = 0, duplicates = 1;

    while (!stack.empty()) {
      if (stack.top().first < height) {
        pairs += stack.top().second;
        stack.pop();
        continue;
      }

      if (stack.top().first == height) {
        duplicates += stack.top().second;
        pairs += stack.top().second;
        stack.pop();
        continue;
      }

      break;
    }

    if (!stack.empty()) {
      pairs++;
    }
    stack.push({height, duplicates});

    total += pairs;
  }

  return total;
}
