#include <iostream> 
#include <queue>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// priority queue

void playingWithPQ(){
    priority_queue<int> pq;

    pq.push(100);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(90);

    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

// merge sort
template <typename T>
void mergeSort(vector<T> &v, int l, int r){
    if (l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);

    int lsize = mid - l + 1, rsize = r - mid;

    T left[lsize], right[rsize];

    for (int x = 0; x < lsize; x++){
        left[x] = v[x + l];
    }

    for (int x = 0; x < rsize; x++){
        right[x] = v[x + mid + 1];
    }

    int i = 0, j = 0, k = l;

    while (i < lsize && j < rsize){
        if (left[i] <= right[j]){
            v[k++] = left[i++];
        }
        else{
            v[k++] = right[j++];
        }
    }

    while (i < lsize){
        v[k++] = left[i++];
    }
    
    while (j < rsize){
        v[k++] = right[j++];
    }
}

// quick sort
template <typename T>
void quickSort(vector<T> &v, int l, int r){
    if (l >= r) return;

    T pivot = v[r];
    int i = l - 1;

    for (int j = l; j < r; j++){
        if (v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[r]);

    quickSort(v, l, i);
    quickSort(v, i + 2, r);
}

// heap sort
template <typename T>
void heapSort(vector<T> &arr, int n){
    priority_queue<int, vector<T>, greater<T>> pq;

    for (int i = 0; i < n; i++){
        pq.push(arr[i]);
    }

    for (int i = 0; i < n; i++){
        arr[i] = pq.top();
        pq.pop();
    }
}

// bubble sort
template <typename T>
void bubbleSort(vector<T> &v){
    int n = v.size();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// selection sort
template <typename T>
void selectionSort(vector<T> &v){
    int n = v.size();

    for (int i = 0; i < n; i++){
        int minIndex = i;

        for (int j = i + 1; j < n; j++){
            if (v[j] < v[minIndex]){
                minIndex = j;
            }
        }

        swap(v[i], v[minIndex]);
    }
}

// generating random data in the vector
template <typename T>
void generateRandomData(vector<T> &v, int n){
    for (int i = 0; i < n; i++){
        v.push_back(rand() % 100);
    }
}

// printing vector
template <typename T>
void printVector(vector<T> &v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

// creating a file of random data
void createFile(int n){
    ofstream fout("data.txt");

    for (int i = 0; i < n; i++){
        fout << rand() % 100 << " ";
    }

    fout.close();
}

// reading data from file
template <typename T>
void readDataFromFile(vector<T> &v){
    ifstream fin("data.txt");

    int x;

    while (fin >> x){
        v.push_back(x);
    }

    fin.close();
}

int main(){

    //createFile(5000);

    vector<int> v;

    readDataFromFile(v);

    auto start = high_resolution_clock::now();
    selectionSort(v);  
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;



    return 0;
}