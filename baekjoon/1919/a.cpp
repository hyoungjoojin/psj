#include <array>
#include <iostream>

int solution(const std::string &, const std::string &);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::cout << solution(s1, s2) << '\n';

  return 0;
}

int solution(const std::string &s1, const std::string &s2) {
  std::array<int, 'z' - 'a' + 1> counts = {0};

  for (const char ch : s1) {
    counts[ch - 'a']++;
  }

  for (const char ch : s2) {
    counts[ch - 'a']--;
  }

  int result = 0;
  for (int count : counts) {
    if (count != 0) {
      result += (count > 0 ? count : -count);
    }
  }

  return result;
}
