#include <deque>
#include <iostream>

std::string solution(const std::string &input);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::string input;
  while (t--) {
    std::cin >> input;
    std::cout << solution(input) << '\n';
  }

  return 0;
}

std::string solution(const std::string &input) {
  std::deque<char> left, right;

  for (const char ch : input) {
    if (ch == '<') {
      if (!left.empty()) {
        right.push_front(left.back());
        left.pop_back();
      }

      continue;
    }

    if (ch == '>') {
      if (!right.empty()) {
        left.push_back(right.front());
        right.pop_front();
      }

      continue;
    }

    if (ch == '-') {
      if (!left.empty()) {
        left.pop_back();
      }

      continue;
    }

    left.push_back(ch);
  }

  std::string output = "";
  while (!left.empty()) {
    output += left.front();
    left.pop_front();
  }

  while (!right.empty()) {
    output += right.front();
    right.pop_front();
  }

  return output;
}
