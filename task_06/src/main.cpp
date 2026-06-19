#include <iostream>
#include <vector>
#include "task6.hpp"

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    std::cout << func(N, K, arr) << std::endl;
    
    return 0;
}