#include "task13.hpp"
#include <gtest/gtest.h>

TEST(LessonScheduleTest, FirstExample) {
    std::vector<std::pair<double, double>> lessons = {
        {9, 10},
        {9.3, 10.3},
        {10, 11},
        {10.3, 11.3},
        {11, 12}
    };
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0].first, 540);
    EXPECT_EQ(result[0].second, 600);
    EXPECT_EQ(result[1].first, 600);
    EXPECT_EQ(result[1].second, 660);
    EXPECT_EQ(result[2].first, 660);
    EXPECT_EQ(result[2].second, 720);
}

TEST(LessonScheduleTest, TwoLessons) {
    std::vector<std::pair<double, double>> lessons = {
        {9, 11},
        {10, 12},
        {11, 13}
    };
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, 540);
    EXPECT_EQ(result[0].second, 660);
    EXPECT_EQ(result[1].first, 660);
    EXPECT_EQ(result[1].second, 780);
}

TEST(LessonScheduleTest, OneLesson) {
    std::vector<std::pair<double, double>> lessons = {
        {9.5, 10.5}
    };
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].first, 570);
    EXPECT_EQ(result[0].second, 630);
}

TEST(LessonScheduleTest, BackToBack) {
    std::vector<std::pair<double, double>> lessons = {
        {9, 9.5},
        {9.5, 10},
        {10, 10.5},
        {10.5, 11}
    };
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result[0].first, 540);
    EXPECT_EQ(result[0].second, 570);
    EXPECT_EQ(result[1].first, 570);
    EXPECT_EQ(result[1].second, 600);
    EXPECT_EQ(result[2].first, 600);
    EXPECT_EQ(result[2].second, 630);
    EXPECT_EQ(result[3].first, 630);
    EXPECT_EQ(result[3].second, 660);
}

TEST(LessonScheduleTest, EmptyInput) {
    std::vector<std::pair<double, double>> lessons;
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 0);
}

TEST(LessonScheduleTest, UnsortedInput) {
    std::vector<std::pair<double, double>> lessons = {
        {11, 12},
        {9, 10},
        {10, 11},
        {9.3, 10.3},
        {10.3, 11.3}
    };
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 3);
}

TEST(LessonScheduleTest, OverlappingLessons) {
    std::vector<std::pair<double, double>> lessons = {
        {9, 12},
        {9.5, 10.5},
        {10, 11},
        {11, 12}
    };
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessons);
    
    EXPECT_EQ(result.size(), 2);
}

TEST(HoursToMinutesTest, NineThree) {
    EXPECT_EQ(hourstominutes(9.3), 570);
}

TEST(HoursToMinutesTest, Ten) {
    EXPECT_EQ(hourstominutes(10), 600);
}

TEST(HoursToMinutesTest, TenFifteen) {
    EXPECT_EQ(hourstominutes(10.15), 615);
}

TEST(HoursToMinutesTest, ElevenFortyFive) {
    EXPECT_EQ(hourstominutes(11.45), 705);
}

