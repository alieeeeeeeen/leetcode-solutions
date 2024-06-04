class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lowerBound(nums, target); // find the lowerBound
        int end = upperBound(nums, target); // find the upperBound`
        if (begin < nums.size() && nums[begin] == target) { // if begin not reach the end of vector and begin equals to the target
            return {begin, end - 1}; // return from the begin to the end - 1
        }
        return {-1, -1}; // return {-1, -1};
    }


private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) { // binary search
            const auto mid = left + (right - left) / 2; // find the mid
            if (nums[mid] >= target) { // mid not less than the target
                right = mid - 1; // move right to the mid - 1
            } else { 
                left = mid + 1; // move left to the mid + 1
            }
        }
        return left;
    }
private:
    int upperBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) { // mid large than the target
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};