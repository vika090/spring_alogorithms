#include "task13.hpp"
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    double start, finish;
    std::vector<std::pair<double, double>> lessonstime;
    
    for (int i = 0; i < n; i++){
        std::cin >> start >> finish;
        lessonstime.push_back({start, finish});
    }
    
    std::vector<std::pair<int, int>> result = chooseLessons(lessonstime);
    
    std::cout << result.size() << std::endl;
    for (int i = 0; i < static_cast<int>(result.size()); i++) {
        int start_h = result[i].first / 60;
        int start_m = result[i].first % 60;
        int end_h = result[i].second / 60;
        int end_m = result[i].second % 60;
        
        if (start_m == 0) std::cout << start_h;
        else std::cout << start_h << "." << start_m;
        
        std::cout << " ";
        
        if (end_m == 0)std::cout << end_h;
        else std::cout << end_h << "." << end_m;
        std::cout << std::endl;
    }
    
    return 0;
}