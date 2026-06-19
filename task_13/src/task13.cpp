#include "task13.hpp"

#include <algorithm>

int hourstominutes(double time) {
  int hours = static_cast<int>(time);
  // Берем дробную часть и умножаем на 100, чтобы получить минуты
  // Например: 9.3 -> 30 минут (0.3 * 100 = 30)
  int minutes = static_cast<int>((time - hours) * 100);
  return hours * 60 + minutes;
}

std::vector<std::pair<int, int>> chooseLessons(
    std::vector<std::pair<double, double>> lessonstime) {
  int n = lessonstime.size();

  if (n == 0) {
    return {};
  }

  std::vector<std::pair<int, int>> lessons;
  for (int i = 0; i < n; i++) {
    int start = hourstominutes(lessonstime[i].first);
    int end = hourstominutes(lessonstime[i].second);
    lessons.push_back({start, end});
  }

  std::sort(lessons.begin(), lessons.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });

  std::vector<std::pair<int, int>> schedule;
  schedule.push_back(lessons[0]);

  for (int i = 1; i < n; i++) {
    if (schedule.back().second <= lessons[i].first) {
      schedule.push_back(lessons[i]);
    }
  }

  return schedule;
}