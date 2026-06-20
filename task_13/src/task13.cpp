#include "task13.hpp"

#include <algorithm>
#include <cmath>

int hourstominutes(double time) {
  int hours = static_cast<int>(time);
  int minutes = static_cast<int>(std::round((time - hours) * 60));
  if (minutes == 60) {
    hours++;
    minutes = 0;
  }
  return hours * 60 + minutes;
}

std::vector<std::pair<int, int>> chooseLessons(
    const std::vector<std::pair<double, double>>& lessonstime) {
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
            [](const auto& a, const auto& b) {
              if (a.second != b.second) return a.second < b.second;
              return a.first < b.first;
            });

  std::vector<std::pair<int, int>> schedule;
  schedule.push_back(lessons[0]);

  for (int i = 1; i < n; i++) {
    if (schedule.back().second <= lessons[i].first) {
      schedule.push_back(lessons[i]);
    }
  }

  return schedule;
}
