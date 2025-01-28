#include <array>
#include <iostream>
#include <utility>
#include <vector>

enum class Gender { Male, Female };

int solution(const std::vector<std::pair<Gender, int>> &, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<std::pair<Gender, int>> students(n);
  int input = 0;
  for (auto &[gender, grade] : students) {
    std::cin >> input;
    gender = (input ? Gender::Male : Gender::Female);

    std::cin >> grade;
  }

  std::cout << solution(students, k) << '\n';

  return 0;
}

int solution(const std::vector<std::pair<Gender, int>> &students, int k) {
  std::array<int, 12> rooms = {0};

  for (const auto &[gender, grade] : students) {
    int index = (grade - 1) + (gender == Gender::Female ? 0 : 6);
    rooms[index]++;
  }

  int result = 0;
  for (int people : rooms) {
    result += (people / k) + ((people % k) != 0);
  }

  return result;
}
