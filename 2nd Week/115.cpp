#include <stack>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// problem 1
class Solution {
public:

    char open[3] = {'(', '[', '{'};
    char close[3] = {')', ']', '}'};

    bool isValid(string s) {

        stack<char> brackets;
        int idx = 0;

        for (int i = 0; i < s.length(); i++){
            idx = 0;
            if (isOpen(s[i])){
                brackets.push(s[i]);
            }
            else{
                if (brackets.empty()) return false;

                idx = getOpen(s[i]);
                if (brackets.top() != open[idx]){
                    return false;
                }
                brackets.pop();
            }
        }
        if (brackets.empty())
        return true;
        return false;
    }

    bool isOpen(char c){
        for (int i = 0; i < 3; i++){
            if (open[i] == c) return true;
        }
        return false;
    }

    int getOpen(char c){
        for (int i = 0; i < 3; i++){
            if (close[i] == c) return i;
        }
        return -1;
    }
};

// problem 2
class MinStack {
public:
    vector<int> min;
    vector<int> stack;
    MinStack() {
        min.push_back(INT_MAX);
    }
    
    void push(int val) {
        stack.push_back(val);
        if (val <= min.back()){
            min.push_back(val);
        }
    }
    
    void pop() {
        if (stack.back() == min.back()){
            min.pop_back();
        }
        stack.pop_back();
        
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
};

// problem 3
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 1, right = height.size()-2, total = 0;
        int lh = height[0], rh = height[height.size()-1];
        if (height.size() <= 2) return 0;

        while (left <= right){
            if (lh < rh){
                lh < height[left] ? lh = height[left] : total += lh - height[left];
                left++;
            }
            else{
                rh < height[right] ? rh = height[right] : total += rh - height[right];
                right--;
            }
        }
        return total;
    }
};

// problem 4
class Solution {
public:
    string decodeString(string s) {
        stack<char> code;
        string temp = "", tempTimes = "", decode = "";
        int times = 0;

        for (int i =0; i < s.length(); i++){

            if (s[i] != ']'){
                code.push(s[i]);
            }
            else{

                while (code.top() != '['){
                    temp = code.top() + temp;
                    code.pop();
                }
                code.pop();

                while(!code.empty() && isdigit(code.top())){
                    tempTimes = code.top() + tempTimes;
                    code.pop();
                }
                times = stoi(tempTimes);
                tempTimes = "";

                while(times--){
                    for (int j = 0; j < temp.length(); j++){
                        code.push(temp[j]);
                    }
                }
                temp = "";
            }
        }

        while (!code.empty()){
            decode = code.top() + decode;
            code.pop();
        }
        return decode;
    }
};

// problem 5
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -1, large = 0, area = 0;

        while (left != right){
            area = (right - left) * min(height[left], height[right]);
            large = max(large, area);
            height[left] >= height[right] ? right-- : left++; 
        }
        return large;
    }
};

// problem 6
class MyStack {
public:
    queue<int> qstack;
    MyStack() {}
    
    void push(int x) {
        qstack.push(x);
        for (int i = 0; i < qstack.size()-1; i++){
            qstack.push(qstack.front());
            qstack.pop();
        }
    }
    
    int pop() {
        int ans = qstack.front();
        qstack.pop();
        return ans;
    }
    
    int top() {
        return qstack.front();
    }
    
    bool empty() {
        return qstack.empty();
    }
};

// problem 7
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> st, sw;

        for (int i = 0, j = 0; i < students.size(), j < sandwiches.size(); i++, j++){
            st.push(students[i]);
            sw.push(sandwiches[i]);
        }

        int counter = 0;
        while (!sw.empty()){
            if (st.front() != sw.front()){
                st.push(st.front());
                st.pop();
                counter++;
            }
            else{
                st.pop();
                sw.pop();
                counter = 0;
            }
            if (counter >= st.size()){
                break;
            }
        }

        return sw.size();
    }
};

// problem 8
class FrontMiddleBackQueue {
public:
    vector<int> que;
    int middle = 0, end = 0;
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        if (que.empty()) que.push_back(val);
        else que.insert(que.begin(), val);
    }
    
    void pushMiddle(int val) {
        middle = que.size() / 2;
        que.insert(que.begin() + middle, val);
        // stack<int> temp;

        // if (!que.empty()){
        //     for (int i = middle; i <= que.size(); i++){
        //         temp.push(que.back());
        //         que.pop_back();
        //     }
        //     que.push_back(val);
        //     for (int i = 0; i <= temp.size(); i++){
        //         que.push_back(temp.top());
        //         temp.pop();
        //     }
        //     end = que.size() - 1;
        // }
        // else{
        //     que.push_back(val);
        // }
    }
    
    void pushBack(int val) {
        que.push_back(val);
    }
    
    int popFront() {

        if (que.empty()){
            return -1;
        }
        int temp = que[0];
        que.erase(que.begin());
        return temp;
    }
    
    int popMiddle() {
        if (que.empty()){
            return -1;
        }
        middle = (que.size()-1)/ 2;
        int temp = que[middle];
        que.erase(que.begin() + middle);
        return temp;
    }
    
    int popBack() {
        if (que.empty()){
            return -1;
        }
        int temp = que.back();
        que.pop_back();
        return temp;
    }
};


// problem 9
// 100/111 test cases passed
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int large = INT_MIN, sum =0, i =-1, n = nums.size(), j = 0, prev = 0;
        while (i < 2 * n)  {
            sum += nums[(i+1)%n];
            prev = large;
            large = max(sum, large);
            j++;
            if (j > n){
                j = 0;
                sum = 0;
                large = prev;
                i-=2;
            }
            if (sum <= 0){
                sum = 0;
                j = 0;
            }
            i++;
        }
        return large;
    }
};

// problem 10
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> orbit;
        int val = 0;
        for (int i =0; i < asteroids.size(); i++){
            while(!orbit.empty() && asteroids[i] < 0 && orbit.top() > 0){
                int sign = orbit.top() + asteroids[i];
                if (sign > 0) asteroids[i] = 0;
                else if (sign < 0) orbit.pop();
                else {
                    orbit.pop();
                    asteroids[i] = 0;
                }
            }
            if (asteroids[i]) orbit.push(asteroids[i]);
        }

        vector<int> result;
        while (!orbit.empty()){
            result.insert(result.begin(), orbit.top());
            orbit.pop();
        }
        return result;
    }
};
