#include <iostream>

using namespace std;

int arr[5] = {1, 2, 3, 4, 5};


int binarySearch(int arr[], int size, int n){
    int start = 0, end = size, mid = (start + end) / 2;
    while (start != end){
        mid = start + (end - start) / 2;
        if (n == arr[mid])
            return mid;
        else if (arr[mid] > n)
            end = mid;
        else{
            start = mid;
        }
    }
}
