#include <iostream>
#include <queue>
#include <vector>

void solution(int, int);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0, k = 0;
  std::cin >> n >> k;

  solution(n, k);

  return 0;
}

void solution(int n, int k) {
  std::queue<int> queue;
  for (int i = 1; i <= n; i++) {
    queue.push(i);
  }

  std::vector<int> result(n);
  int index = 0;

  while (!queue.empty()) {
    for (int i = 1; i < k; i++) {
      queue.push(queue.front());
      queue.pop();
    }

    result[index++] = queue.front();
    queue.pop();
  }

  std::cout << '<';
  for (int i = 0; i < n - 1; i++) {
    std::cout << result[i] << ", ";
  }
  std::cout << result[n - 1] << ">\n";
}
