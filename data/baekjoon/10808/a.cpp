#include <array>
#include <iostream>
#include <string>

void solution(const std::string &);

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string word = "";
  std::cin >> word;

  solution(word);

  return 0;
}

void solution(const std::string &word) {
  std::array<size_t, 'z' - 'a' + 1> counts = {0};
  for (char ch : word) {
    if (ch < 'a' || ch > 'z') {
      continue;
    }

    counts[ch - 'a']++;
  }

  for (size_t count : counts) {
    std::cout << count << ' ';
  }
}
