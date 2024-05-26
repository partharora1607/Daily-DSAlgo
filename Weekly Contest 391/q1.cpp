#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int maxManhattanDistance(vector<vector<int>> &points) {
  // Sort based on x-coordinates
  sort(points.begin(), points.end());

  int maxXDiff = 0;
  for (int i = 1; i < points.size(); ++i) {
    maxXDiff = max(maxXDiff, abs(points[i][0] - points[i - 1][0]));
  }

  // Sort based on y-coordinates
  sort(points.begin(), points.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

  int maxYDiff = 0;
  for (int i = 1; i < points.size(); ++i) {
    maxYDiff = max(maxYDiff, abs(points[i][1] - points[i - 1][1]));
  }

  // Return the maximum Manhattan distance
  return maxXDiff + maxYDiff;
}

int main() {
  vector<vector<int>> points = {{3, 10}, {5, 15}, {10, 2}, {4, 4}};
  cout << "Maximum Manhattan distance: " << maxManhattanDistance(points)
       << endl;
  return 0;
}
