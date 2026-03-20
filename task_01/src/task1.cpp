#include "task1.hpp"

#include <utility>
#include <vector>

using namespace std;

pair<int, int> func(const vector<int>& arr, int S) {
  if (arr.size() < 2) {
    return {-1, -1};
  }

  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == S) {
      return {arr[left], arr[right]};
    } else if (sum < S) {
      left++;
    } else {
      right--;
    }
  }

  return {-1, -1};
}