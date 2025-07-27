#include <iostream>
#include <stack>

int solution(int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k = 0;
  std::cin >> k;

  std::cout << solution(k) << '\n';

  return 0;
}

int solution(int k) {
  std::stack<int> stack;

  int input = 0;
  while (k--) {
    std::cin >> input;

    if (input != 0) {
      stack.push(input);
      continue;
    }

    if (!stack.empty()) {
      stack.pop();
    }
  }

  int sum = 0;
  while (!stack.empty()) {
    sum += stack.top();
    stack.pop();
  }

  return sum;
}
