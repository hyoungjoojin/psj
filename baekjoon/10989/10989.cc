#include <iostream>
#include <vector>

const int MAXIMUM_INPUT_SIZE = 10000;

void solution(int);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n = 0;
  std::cin >> n;

  solution(n);

  return 0;
}

void solution(int n) {
  std::vector<unsigned short> bins(MAXIMUM_INPUT_SIZE + 1, 0);

  int input = 0;
  while (n--) {
    std::cin >> input;
    bins[input]++;
  }

  for (int i = 1; i <= MAXIMUM_INPUT_SIZE; i++) {
    for (unsigned short j = 0; j < bins[i]; j++) {
      std::cout << i << '\n';
    }
  }
}
