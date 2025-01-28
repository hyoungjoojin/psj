#include <array>
#include <cstdlib>
#include <iostream>

const unsigned int NUM_ALPHABETS = 'z' - 'a' + 1;

int solution(const std::string &, const std::string &);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string first_word, second_word;
  std::cin >> first_word >> second_word;

  std::cout << solution(first_word, second_word) << '\n';

  return 0;
}

int solution(const std::string &source, const std::string &target) {
  std::array<int, NUM_ALPHABETS> alphabet_count = {0};
  for (char ch : source) {
    alphabet_count[ch - 'a']++;
  }

  for (char ch : target) {
    alphabet_count[ch - 'a']--;
  }

  int result = 0;
  for (int count : alphabet_count) {
    result += std::abs(count);
  }

  return result;
}
