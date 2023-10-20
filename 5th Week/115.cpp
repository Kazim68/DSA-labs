#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stack>    
using namespace std;

// question 1 

// part 1
int arith(int n){
    return (n == 1) ? 1 : n + arith(n - 1);
}

// part 2
int oddSeries(int n){
    return (n == 1) ? 1 : n + oddSeries(n - 2);
}

// part 3
int Geo2(int n){
    return (n == 0) ? 1 : pow(2,n) + Geo2(n - 1);
}

// part 4
int Geo3(int n){
    return (n == 0) ? 1 : pow(3,n) + Geo3(n - 1);
}

// part 5 
int arith3(int n){
    return (n == 1) ? 1 : n + arith3(n / 3);
}

// part 6
int arith2(int n){
    return (n == 1) ? 1 : n + arith2(n / 2);
}

// question 2

// part 1
int bin(int n){
    return (n == 1) ? 1 : bin(n / 2) * 10 + n % 2;
}

// part 2
string binStr(int n){
    return (n == 1) ? "1" : binStr(n / 2) + ((n % 2) ? "1" : "0");
}

// part 3
int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

// question 3

// part 3
int binarySearch(int arr[], int left, int right, int n){
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == n)
        return mid;
    if (arr[mid] > n)
        return binarySearch(arr, left, mid - 1, n);
    return binarySearch(arr, mid + 1, right, n);
}

// question 4
int power(int x, int y){
    return (y == 0) ? 1 : x * power(x, y - 1);
}

int powerLog(int x, int y){
    return (y == 0) ? 1 : ((y % 2) ? x : 1) * powerLog(x, y / 2) * powerLog(x, y / 2);
}

// question 5

int add(int x, int y){
    return x + y;
}

// part 1
int mul(int x, int y){
    return (y == 0) ? y : add(x, mul(x, y - 1));
}

// part 2
int mulLog2(int x, int y){
    return (y == 0) ? y : add(((y % 2) ? x : 0), add(mulLog2(x, y / 2), mulLog2(x, y / 2)));
}

// part 3
int mult(int x, int y, vector<int> temp){
    if (y==0)
        return 0;
    if (y==1)
        return x;
    if (temp[y] != 0)
        return temp[y];
    temp[y] = add(((y % 2) ? x : 0), add(mulLog2(x, y / 2), mulLog2(x, y / 2)));
    return temp[y];
}

int mulLog(int x, int y){
    vector<int> temp(y+1);
    return mult(x, y, temp);
}

// question 6
int sub(int x, int y) {
    return x - y;
}

// part 1
int d(int a, int b, int c) {
    if (a < b)
        return c;
    c++;
    return d(sub(a, b), b, c);
}
int Div(int x, int y) {
    return d(x, y, 0);
}

int Mod(int x, int y) {
    if (x < y)
        return x;
    return Mod(sub(x, y), y);
}

// part 2
int div2(int x, int y){
    return (x < y) ? 0 : 1 + div2(sub(x, y), y);
}

// question 7

// part 3
int fib(int n, vector<int> temp){
    temp[0] = 0;
    temp[1] = 1;
    for (int i = 2; i < n; i++){
        temp[i] = temp[i - 1] + temp[i - 2];
    }
    return temp[n - 1];
}

int fibonacci(int n){
    vector<int> temp(n+1);
    return fib(n, temp);
}

// question 8

// part 1
int triSum1(int n){
    if (n <= 3)
        return n;
    return triSum1(n - 1) + triSum1(n - 2) + triSum1(n - 3);
}

// part 2
int triSeq(int n){
    if (n <= 3){
        cout << n << ", ";
        return n;
    }
    int temp = triSeq(n - 1) + triSeq(n - 2) + triSeq(n - 3);
    cout << temp << ", ";
    return temp;
}

// 4
int triSum(int n, vector<int> temp){
    if (n < 3)
        return n;
    if (temp[n] != 0)
        return temp[n];
    temp[n] = triSum(n - 1, temp) + triSum(n - 2, temp) + triSum(n - 3, temp);
    return temp[n];
}

int tri(int n){
    vector<int> temp(n+1);
    return triSum(n, temp);
}

int triIte(int n){
    vector<int> temp(n + 1);
    temp[0] = 0;
    temp[1] = 1;
    temp[2] = 2;
    for (int i = 3; i <= n; i++){
        temp[i] = temp[i - 1] + temp[i - 2] + temp[i - 3];
    }
    return temp[n];
}

// challenge 1
void subArrays(vector<int> arr, int left, int right){
    if (right == arr.size())
        return;

    else if (left > right){
        subArrays(arr, 0, right+1);
    }
    else{
        if (left == right && left == 0) {
            cout << "[]" << endl;
        }
        cout << "[";
        for (int i = left; i < right; i++){
            cout << arr[i] << ", ";
        }
        cout << arr[right] << "]" << endl;

        subArrays(arr, left + 1, right);
    }
}

// challenge 2
void arrange(stack<int> &s, stack<int> &temp, int n){
    if (!s.empty() && s.top() > n) {
        temp.push(s.top());
        s.pop();
        arrange(s, temp, n);
    }
}

void putBack(stack<int> &s, stack<int> &temp){
    if (!temp.empty()){
        s.push(temp.top());
        temp.pop();
        putBack(s, temp);
    }
}

void sort(stack<int> &s){
    if (s.empty())
        return;
    
    int temp = s.top();
    s.pop();

    sort(s);

    stack<int> tempStack;

    arrange(s, tempStack, temp);

    s.push(temp);
    putBack(s, tempStack);
}


int main(){
    stack<int> test;
    test.push(30);
    test.push(-5);
    test.push(18);
    test.push(14);
    test.push(-3);
    sort(test);
    while (!test.empty()){
        cout << test.top() << " ";
        test.pop();
    }
    return 0;
}

