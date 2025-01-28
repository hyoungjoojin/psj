#include <array>
#include <iostream>

const unsigned int NUM_ALPHABETS = 'z' - 'a' + 1;

bool solution(const std::string &, const std::string &);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_testcases = 0;
  std::cin >> num_testcases;

  std::string source, target;
  while (num_testcases--) {
    std::cin >> source >> target;
    std::cout << (solution(source, target) ? "Possible\n" : "Impossible\n");
  }

  return 0;
}

bool solution(const std::string &source, const std::string &target) {
  std::array<int, NUM_ALPHABETS> alphabet_count = {0};
  for (char ch : source) {
    alphabet_count[ch - 'a']++;
  }

  for (char ch : target) {
    alphabet_count[ch - 'a']--;
  }

  for (int count : alphabet_count) {
    if (count != 0) {
      return false;
    }
  }

  return true;
}
