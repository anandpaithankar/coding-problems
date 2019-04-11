#include "algo.h"
using namespace std;
void checkSumPossibleRecur(std::vector<long long int> arr, int index, long long int k) {
    if (k == 0) {
        return ;
    }
    
    // todo: come back to this
    if (index == 0 && k != 0) {
        return ;
    }
    
    checkSumPossibleRecur(arr, index-1, k);
    k -= arr[index-1];
    checkSumPossibleRecur(arr,index-1, k);
}

bool check_if_sum_possible(vector <long long int> arr, long long int k) {
    if (k == 0) {
        return true;
    }

    checkSumPossibleRecur(arr, arr.size()-1, k);
    
}

int main()
{
    std::vector<long long int> arr{1,5,7,3};
    long long int k = 10;

    std::cout << check_if_sum_possible(arr, k);
    
}