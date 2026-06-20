#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "task13.hpp"

TEST(LessonScheduleTest, FirstExample) {
  std::vector<std::pair<double, double>> lessonstime = {
      {9, 10}, {9.3, 10.3}, {10, 11}, {10.3, 11.3}, {11, 12}};

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 3);
  EXPECT_DOUBLE_EQ(result[0].first, 9);
  EXPECT_DOUBLE_EQ(result[0].second, 10);
  EXPECT_DOUBLE_EQ(result[1].first, 10);
  EXPECT_DOUBLE_EQ(result[1].second, 11);
  EXPECT_DOUBLE_EQ(result[2].first, 11);
  EXPECT_DOUBLE_EQ(result[2].second, 12);
}

TEST(LessonScheduleTest, TwoLessons) {
  std::vector<std::pair<double, double>> lessonstime = {
      {9, 11}, {10, 12}, {11, 13}};

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 2);
  EXPECT_DOUBLE_EQ(result[0].first, 9);
  EXPECT_DOUBLE_EQ(result[0].second, 11);
  EXPECT_DOUBLE_EQ(result[1].first, 11);
  EXPECT_DOUBLE_EQ(result[1].second, 13);
}

TEST(LessonScheduleTest, OneLesson) {
  std::vector<std::pair<double, double>> lessonstime = {{9.5, 10.5}};

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 1);
  EXPECT_DOUBLE_EQ(result[0].first, 9.5);
  EXPECT_DOUBLE_EQ(result[0].second, 10.5);
}

TEST(LessonScheduleTest, BackToBack) {
  std::vector<std::pair<double, double>> lessonstime = {
      {9, 9.5}, {9.5, 10}, {10, 10.5}, {10.5, 11}};

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 4);
  EXPECT_DOUBLE_EQ(result[0].first, 9);
  EXPECT_DOUBLE_EQ(result[0].second, 9.5);
  EXPECT_DOUBLE_EQ(result[1].first, 9.5);
  EXPECT_DOUBLE_EQ(result[1].second, 10);
  EXPECT_DOUBLE_EQ(result[2].first, 10);
  EXPECT_DOUBLE_EQ(result[2].second, 10.5);
  EXPECT_DOUBLE_EQ(result[3].first, 10.5);
  EXPECT_DOUBLE_EQ(result[3].second, 11);
}

TEST(LessonScheduleTest, EmptyInput) {
  std::vector<std::pair<double, double>> lessonstime;

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 0);
}

TEST(LessonScheduleTest, UnsortedInput) {
  std::vector<std::pair<double, double>> lessonstime = {
      {11, 12}, {9, 10}, {10, 11}, {9.3, 10.3}, {10.3, 11.3}};

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 3);
  EXPECT_DOUBLE_EQ(result[0].first, 9);
  EXPECT_DOUBLE_EQ(result[0].second, 10);
  EXPECT_DOUBLE_EQ(result[1].first, 10);
  EXPECT_DOUBLE_EQ(result[1].second, 11);
  EXPECT_DOUBLE_EQ(result[2].first, 11);
  EXPECT_DOUBLE_EQ(result[2].second, 12);
}

TEST(LessonScheduleTest, OverlappingLessons) {
  std::vector<std::pair<double, double>> lessonstime = {
      {9, 12}, {9.5, 10.5}, {10, 11}, {11, 12}};

  std::vector<std::pair<double, double>> result = chooseLessons(lessonstime);

  EXPECT_EQ(result.size(), 1);
  EXPECT_DOUBLE_EQ(result[0].first, 9);
  EXPECT_DOUBLE_EQ(result[0].second, 12);
}
