#include <array>
#include <iostream>
#include <string>

const unsigned short ALPHABET_COUNT = 'z' - 'a' + 1;

using CharacterCount = std::array<unsigned short, ALPHABET_COUNT>;

CharacterCount solution(const std::string &);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string word;
  std::cin >> word;

  for (unsigned short count : solution(word)) {
    std::cout << count << ' ';
  }

  return 0;
}

CharacterCount solution(const std::string &word) {
  CharacterCount character_count = {0};

  for (char c : word) {
    int index = c - 'a';
    if (index < 0 || index >= ALPHABET_COUNT) {
      continue;
    }

    character_count[index]++;
  }

  return character_count;
}
