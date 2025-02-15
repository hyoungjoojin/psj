#include <iostream>
#include <unordered_map>

long long solution(long long, long long, long long);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  long long n = 0, p = 0, q = 0;
  std::cin >> n >> p >> q;

  std::cout << solution(n, p, q) << '\n';
}

long long solution_recursive(std::unordered_map<long long, long long> &hashmap,
                             long long n, long long p, long long q) {
  if (n == 0) {
    return 1;
  }

  long long result = 0;

  long long index = n / p;
  result += (hashmap.find(index) != hashmap.end())
                ? hashmap[index]
                : solution_recursive(hashmap, index, p, q);

  index = n / q;
  result += (hashmap.find(index) != hashmap.end())
                ? hashmap[index]
                : solution_recursive(hashmap, index, p, q);

  hashmap[n] = result;
  return result;
}

long long solution(long long n, long long p, long long q) {
  std::unordered_map<long long, long long> hashmap;
  return solution_recursive(hashmap, n, p, q);
}
