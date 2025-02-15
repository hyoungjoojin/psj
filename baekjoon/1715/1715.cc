#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int solution(const std::vector<int> &);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<int> cards(n);
  for (int &card : cards) {
    std::cin >> card;
  }

  std::cout << solution(cards) << '\n';
}

int solution(const std::vector<int> &cards) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  for (int card : cards) {
    pq.push(card);
  }

  int result = 0;
  while (pq.size() > 1) {
    int sum = pq.top();
    pq.pop();

    sum += pq.top();
    pq.pop();

    pq.push(sum);
    result += sum;
  }

  return result;
}
