#include <iostream>
using namespace std;

int run = 4;

void insertionSort(int arr[], int left, int right){
    for (int i = left + 1; i <= right; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right){
    int len1 = mid - left + 1, len2 = right - mid;

    int l[len1], r[len2];

    for (int i = 0; i < len1; i++){
        l[i] = arr[left + i];
    }

    for (int i = 0; i < len2; i++){
        r[i] = arr[mid + 1 + i];
    }

    int i =0, j = 0, k = left;

    while (i < len1 && j < len2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < len1){
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < len2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void TimSort(int arr[], int n){
    // using insertion sort
    for (int i = 0; i < n; i+= run){
        insertionSort(arr, i, min((i + run - 1), (n - 1)));
    }

    // merge using merge sort
    for (int size = run; size < n; size *= 2){
        for (int left = 0; left < n; left += 2*size){
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right){
                merge(arr, left, mid, right);
            }
        }
    }
}

void print(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {10, 55, -5, 34, 7, 22, 19, 27, -87, 12, 9, 41, -67, -32, 92, 17, 23, 45, -22, 29};

    TimSort(arr, 20);

    print(arr, 20);

    return 0;
}
