#include <iostream>
#include <utility>
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

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  std::cout << result.size() << std::endl;
  for (const auto& lesson : result) {
    std::cout << lesson.first << " " << lesson.second << std::endl;
  }

  return 0;
}
