class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // find the potential position or position in the vector, still use the binary search, note that
        // we only need to validate the value that is not less than or less than
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            const auto mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
