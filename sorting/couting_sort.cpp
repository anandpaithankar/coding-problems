#include <iostream>
#include <vector>

#define RANGE 10

void countingSort(std::vector<int> &arr) {
    std::vector<int> count(RANGE,0);

    for (auto n : arr) {
        count[n]++;
    }

    for (int i = 1; i <= RANGE; i++) {
        count[i] += count[i-1];
    }
    
    std::vector<int> output(arr.size());
    for(int i = arr.size()-1; i >= 0; i--) 
    {  
         output[ count[arr[i]] -1 ] = arr[i];  
              count[arr[i]]--;  
    } 
    arr = output;
}

int main()
{
    std::vector<int> arr{5,6,2,0,8,6,1,2};
    countingSort(arr);
    for (auto n : arr) {
        std::cout << n << " ";
    }

}
