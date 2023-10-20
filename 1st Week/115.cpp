// problem 1 solution
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> list;
    int count = 0;

    for (int i = 0; i < nums.size(); i++){
        count = 0;
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] < nums[i]){
                count++;
            }
        }
        list.push_back(count);
    }

    return list;
}

// problem 2 
int removeElement(vector<int>& nums, int val) {
    
    for (int i = 0; i< nums.size(); i++){
        if (nums[i] == val){
            nums.erase(nums.begin()+i);
            i--;
        }
    }
    return nums.size();
}

// problem 3. Though this was not accepted as it's time limit exceeded
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int foundRow;
    int top = 0, bottom = matrix.size() - 1, mid = bottom + 1 / 2;

    int left = 0, right = matrix[0].size() - 1, center = right + 1 /2;

    while(mid != top || mid != bottom){

        if (matrix[mid][0] < target && matrix[mid+1][0] > target ){
            foundRow = mid;
            break;
        }
        else if (matrix[top][0] < target && matrix[top + 1][0] > target){
            foundRow = top;
            break;
        }
        else if (matrix[bottom][0] < target && matrix[bottom - 1][0] > target){
            foundRow = bottom;
            break;
        }
        else if (matrix[mid][0] > target){
            bottom = mid;
        }
        else if (matrix[mid][0] < target){
            top = mid;
        }

        mid = top + bottom / 2;
    }

    while(left != center || right != center){
        
        if (matrix[foundRow][center] == target){
            return true;
        }
        else if (matrix[foundRow][center] > target){
            right = center;
        }
        else if (right - left == 1 && matrix[foundRow][right] == target){
            return true;
        }
        else{
            left = center;
        }

    }

    return false;
}

// problem 3 re-try => worked this time
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix[0].size(), m = matrix.size();
    int left = 0, right = n * m - 1, mid = right + left / 2;
    int row, col;
    // =>  [[1, 2, 3, 4], [5, 6, 7, 8]]
    // =>  [1, 2, 3, 4, 5, 6, 7, 8] 
    //      l           m        r 
    while(left <= right){

        mid = (left + right) / 2;

        row = mid / n;
        col = mid % n;

        if (matrix[row][col] == target){return true;}
        else if (matrix[row][col] > target){
            right = mid - 1;
        }
        else if (matrix[row][col] < target){
            left = mid + 1;
        }
    }
    return true;
}

// problem 4
int removeDuplicates(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == nums[i-1]){
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}

// problem 5
int maxSubArray(vector<int>& nums) {
    vector<int> sums;

    int largest = -999999999, sum = 0;

    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if (sum > largest){
            largest = sum;
        }
        if (sum <0){
            sum = 0;
        }
    }
    return largest;
}

// problem 6
int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left <= right){
        int mid = left + (( right - left ) / 2);
        if (isBadVersion(mid) && !isBadVersion(mid-1)){
            return mid;
        }
        else if (isBadVersion(mid)){
            right = mid-1;
        }
        else if (!isBadVersion(mid) && isBadVersion(mid+1)){
            return mid+1;
        }
        else{
            left = mid+1;
        }
    }
    return 0;
}

// problem 7
int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int c = 1;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == c){
            c++;
        }
    }
    return c;
}