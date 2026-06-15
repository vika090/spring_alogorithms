#include <iostream>
#include <vector>

std::vector<int> sortUntilK(const std::vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size()) return arr;
    
    std::vector<int> result = arr;
    
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    
    return result;
}

int cnt_static(int N, int K, int* arr){
    return sortUntilK(std::vector<int> &arr, int K)[K];
    
}

int main(){}