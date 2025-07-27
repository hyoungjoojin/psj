#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

long long solution(std::vector<int> &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> heights(n);
  for (int &h : heights) {
    std::cin >> h;
  }

  std::cout << solution(heights) << '\n';

  return 0;
}

long long solution(std::vector<int> &heights) {
  std::stack<int> stack;

  std::vector<long long> counts(heights.size(), 0);
  long long result = 0;

  for (int i = heights.size() - 1; i >= 0; i--) {
    long long count = 0;
    while (!stack.empty() && heights[i] > heights[stack.top()]) {
      count += counts[stack.top()] + 1;
      stack.pop();
    }

    counts[i] = count;
    result += counts[i];
    stack.push(i);
  }

  return result;
}
