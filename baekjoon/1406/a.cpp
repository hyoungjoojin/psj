#include <deque>
#include <iostream>
#include <string>

std::string solution(const std::string &, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string initial = "";
  std::cin >> initial;

  int commands_count = 0;
  std::cin >> commands_count;

  std::cout << solution(initial, commands_count) << '\n';

  return 0;
}

std::string solution(const std::string &initial, int commands_count) {
  std::deque<char> left, right;
  for (const char ch : initial) {
    left.push_back(ch);
  }

  unsigned long length = initial.length();

  char command, value;
  while (commands_count--) {
    std::cin >> command;

    if (command == 'P') {
      std::cin >> value;
      left.push_back(value);
      length++;
      continue;
    }

    if (command == 'D') {
      if (!right.empty()) {
        left.push_back(right.front());
        right.pop_front();
      }

      continue;
    }

    if (!left.empty()) {
      if (command == 'L') {
        right.push_front(left.back());
        left.pop_back();

        continue;
      }

      if (command == 'B') {
        left.pop_back();
        length--;
      }
    }
  }

  std::string output;
  output.reserve(length);

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
