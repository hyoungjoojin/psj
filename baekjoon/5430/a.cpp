#include <deque>
#include <iostream>
#include <string>
#include <vector>

int solution(std::vector<int> &array, std::string &function) {
  std::deque<int> deque;
  for (int i : array) {
    deque.push_back(i);
  }

  bool reversed = false;
  for (char ch : function) {
    if (ch == 'R') {
      reversed = !reversed;
      continue;
    }

    if (ch == 'D') {
      if (deque.empty()) {
        return -1;
      }

      if (reversed) {
        deque.pop_back();
      } else {
        deque.pop_front();
      }
    }
  }

  if (reversed) {
    for (int i = 0; i < deque.size(); i++) {
      array[deque.size() - i - 1] = deque[i];
    }
  } else {
    for (int i = 0; i < deque.size(); i++) {
      array[i] = deque[i];
    }
  }

  return deque.size();
}

void parse_input(std::vector<int> &array, std::string input, int size) {
  array.resize(size);

  if (size == 0) {
    return;
  }

  std::string number = "";

  int i = 0;
  for (char ch : input) {
    if (ch == '[') {
      continue;
    }

    if (ch == ',' || ch == ']') {
      array[i++] = std::stoi(number);
      number = "";
      continue;
    }

    number += ch;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  std::string function = "", input = "";
  std::vector<int> array;

  while (t--) {
    std::cin >> function;

    int n = 0;
    std::cin >> n;

    std::cin >> input;
    parse_input(array, input, n);

    int res = solution(array, function);

    if (res == -1) {
      std::cout << "error\n";
    } else if (res == 0) {
      std::cout << "[]\n";
    } else {
      std::cout << '[';
      for (int i = 0; i < res - 1; i++) {
        std::cout << array[i] << ',';
      }
      std::cout << array[res - 1] << "]\n";
    }
  }

  return 0;
}
