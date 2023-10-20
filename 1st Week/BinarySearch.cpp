#include <iostream>
using namespace std;


// without recursion
int binarySearch(int arr[], int size, int target)
{

    int left = 0, right = size;
    int mid = (right - left) / 2;
    // left         mid         right

    while (mid != left || mid != right)
    {

        mid = left + ((right - left) / 2);
        // l => 5       r=> 10      mid=> 2.5 

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid;
        }
        else if (right - left == 1 && arr[right] == target)
        {
            return right;
        }
        else
        {
            right = mid;
        }
    }
}

int main()
{
    int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarySearch(arr, sizeof(arr), 10);
    return 0;
}