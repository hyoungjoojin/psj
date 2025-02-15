#include <iostream>

long solution(int, int, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;

  std::cout << solution(a, b, c) << '\n';
}

long solution(int a, int b, int c) {
  if (b == 0) {
    return 1;
  }

  long subsolution = solution(a, b / 2, c);
  long result = (subsolution * subsolution) % c * (b % 2 == 1 ? a % c : 1);

  return result % c;
}
