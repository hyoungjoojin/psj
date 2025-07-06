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

  std::vector<int> array(n);
  for (int &i : array) {
    std::cin >> i;
  }

  solution(array);

  return 0;
}

void solution(std::vector<int> &array) {
  std::stack<int> stack;

  for (auto it = array.rbegin(); it != array.rend(); it++) {
    while (!stack.empty() && stack.top() <= *it) {
      stack.pop();
    }

    int result = stack.empty() ? -1 : stack.top();

    stack.push(*it);
    *it = result;
  }

  for (const int &i : array) {
    std::cout << i << ' ';
  }
}
