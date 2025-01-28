#include <iostream>
#include <unordered_map>
#include <vector>

int solution(const std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> array(n);
  for (int &number : array) {
    std::cin >> number;
  }

  int target = 0;
  std::cin >> target;

  std::cout << solution(array, target) << '\n';

  return 0;
}

int solution(const std::vector<int> &array, int target) {
  std::unordered_map<int, int> hashmap;

  int result = 0;
  for (auto it = array.rbegin(); it != array.rend(); it++) {
    int current = *it;
    int residual = target - current;

    auto residual_iterator = hashmap.find(residual);
    if (residual_iterator != hashmap.end()) {
      result += residual_iterator->second;
    }

    auto current_iterator = hashmap.find(current);
    if (current_iterator != hashmap.end()) {
      current_iterator->second += 1;
    } else {
      hashmap[current] = 1;
    }
  }

  return result;
}
