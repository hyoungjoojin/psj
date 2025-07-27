#include <array>
#include <iostream>

int solution(int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::cout << solution(n, k) << '\n';

  return 0;
}

int solution(int n, int k) {
  int result = 0;

  std::array<int, 12> people = {0};

  int sex, grade;
  while (n--) {
    std::cin >> sex >> grade;

    int index = sex * 6 + grade - 1;

    people[index]++;
    if (people[index] == k) {
      people[index] = 0;
      result++;
    }
  }

  for (int p : people) {
    if (p > 0) {
      result++;
    }
  }
  return result;
}
