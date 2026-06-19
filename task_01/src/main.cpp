#include <iostream>
#include <vector>
#include "task1.hpp"

int main() {
    int n, Summa;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    std::cin >> Summa;
    
    std::pair<int, int> result = func(arr, Summa);
    
    std::cout << result.first << " " << result.second << std::endl;
    
    return 0;
}