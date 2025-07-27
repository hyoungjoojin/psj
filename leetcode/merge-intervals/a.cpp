#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &i1, const vector<int> &i2) {
           return i1[0] == i2[0] ? i1[1] < i2[1] : i1[0] < i2[0];
         });

    vector<vector<int>> result;

    vector<int> current(2, -1);
    for (vector<int> &interval : intervals) {
      if (interval[0] > current[1]) {
        if (current[1] != -1) {
          result.push_back(current);
        }

        current[0] = interval[0];
        current[1] = interval[1];
      } else {
        current[1] = max(current[1], interval[1]);
      }
    }

    if (current[1] != -1) {
      result.push_back(current);
    }

    return result;
  }
};
