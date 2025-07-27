#include <iostream>
#include <stack>
#include <vector>

void solution(std::vector<int> &);

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

  solution(heights);

  return 0;
}

void solution(std::vector<int> &heights) {
  std::stack<int> stack;

  std::vector<int> result(heights.size());
  for (int i = 0; i < heights.size(); i++) {
    while (!stack.empty() && heights[stack.top()] < heights[i]) {
      stack.pop();
    }

    int top = stack.empty() ? -1 : stack.top();
    result[i] = top + 1;
    stack.push(i);
  }

  for (int r : result) {
    std::cout << r << ' ';
  }
}
