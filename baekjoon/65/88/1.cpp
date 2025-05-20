#include <iostream>
#include <vector>

const int INPUT_MAX = 1000000;

int primes_count = 0;
std::vector<int> primes(100000, 0);

void init();
void solution(int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  init();

  int input = 0;
  while (true) {
    std::cin >> input;
    if (input == 0) {
      break;
    }

    solution(input);
  }

  return 0;
}

void init() {
  std::vector<bool> is_prime(INPUT_MAX + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= INPUT_MAX; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i + i; j <= INPUT_MAX; j += i) {
      is_prime[j] = false;
    }
  }

  int count = 0;
  for (int i = 0; i <= INPUT_MAX; i++) {
    if (is_prime[i]) {
      primes[count++] = i;
    }
  }

  primes_count = count;
}

int binary_search(int target) {
  int start = 0, end = primes_count - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    int value = primes[mid];

    if (target < value) {
      end = mid - 1;
    } else if (target > value) {
      start = mid + 1;
    } else {
      return target;
    }
  }

  return -1;
}

void solution(int target) {
  int remainder = 0, result = 0;
  for (int i = 0; i < primes_count; i++) {
    remainder = target - primes[i];
    if ((result = binary_search(remainder)) != -1) {
      std::cout << target << " = " << primes[i] << " + " << result << '\n';
      return;
    }
  }

  std::cout << "Goldbach's conjecture is wrong.\n";
}
