#include <iostream>
#include <vector>

#include "task13.hpp"

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<double, double>> lessonstime;
  for (int i = 0; i < n; i++) {
    double start, finish;
    std::cin >> start >> finish;
    lessonstime.push_back({start, finish});
  }

  std::vector<std::pair<int, int>> result = chooseLessons(lessonstime);

  std::cout << result.size() << std::endl;
  for (const auto& lesson : result) {
    int start_h = lesson.first / 60;
    int start_m = lesson.first % 60;
    int end_h = lesson.second / 60;
    int end_m = lesson.second % 60;

    if (start_m == 0) {
      std::cout << start_h;
    } else {
      std::cout << start_h << "." << start_m;
    }

    std::cout << " ";

    if (end_m == 0) {
      std::cout << end_h;
    } else {
      std::cout << end_h << "." << end_m;
    }
    std::cout << std::endl;
  }

  return 0;
}
