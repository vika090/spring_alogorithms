
#include "task13.hpp"

#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

int hourstominutes(double time) {
  int hours = static_cast<int>(time);
  int minutes = static_cast<int>(std::round((time - hours) * 60));
  if (minutes == 60) {
    hours++;
    minutes = 0;
  }
  return hours * 60 + minutes;
}

std::vector<std::pair<double, double>> chooseLessons(
    const std::vector<std::pair<double, double>>& lessonstime) {
  if (lessonstime.empty()) {
    return {};
  }

  std::vector<std::pair<int, int>> lessons;
  for (const auto& lesson : lessonstime) {
    lessons.push_back(
        {hourstominutes(lesson.first), hourstominutes(lesson.second)});
  }

  std::sort(lessons.begin(), lessons.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
              if (a.second != b.second) {
                return a.second < b.second;
              }
              return a.first < b.first;
            });

  std::vector<std::pair<int, int>> selected_minutes;
  int last_end_time = -1;

  for (const auto& lesson : lessons) {
    if (lesson.first >= last_end_time) {
      selected_minutes.push_back(lesson);
      last_end_time = lesson.second;
    }
  }

  std::vector<std::pair<double, double>> selected;
  for (const auto& lesson : selected_minutes) {
    double start = lesson.first / 60.0;
    double end = lesson.second / 60.0;
    selected.push_back({start, end});
  }

  return selected;
}
