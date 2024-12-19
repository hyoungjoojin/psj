#include <iostream>
#include <vector>

enum class Player { SK, CY };

Player solution(int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;

  switch (solution(n)) {
  case Player::SK:
    std::cout << "SK\n";
    break;

  case Player::CY:
    std::cout << "CY\n";
    break;
  }

  return 0;
}

Player solution(int n) {
  std::vector<Player> result(n + 1);

  result[1] = Player::SK;
  result[2] = Player::CY;
  result[3] = Player::SK;

  for (int i = 4; i <= n; i++) {
    result[i] = result[i - 1] == Player::CY || result[i - 3] == Player::CY
                    ? Player::SK
                    : Player::CY;
  }

  return result[n];
}
