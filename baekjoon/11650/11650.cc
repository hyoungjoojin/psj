#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
  int x;
  int y;
};

std::vector<Point> &solution(std::vector<Point> &);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;

  std::vector<Point> points(n);
  for (Point &point : points) {
    std::cin >> point.x >> point.y;
  }

  for (const auto &[x, y] : solution(points)) {
    std::cout << x << ' ' << y << '\n';
  }
}

std::vector<Point> &solution(std::vector<Point> &points) {
  std::sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
    if (p1.x == p2.x) {
      return p1.y < p2.y;
    }

    return p1.x < p2.x;
  });

  return points;
}
