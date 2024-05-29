class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return; // only one element return

        int i = nums.size() - 2; // from the last second element
        while(i >= 0 && nums[i] > nums[i + 1]) i--; // find the pivot when ascending order breaks

        if (i > 0) {
            int j = nums.size() - 1; // from the last element
            while(nums[i] >= nums[j]) j--; // find the element that is larger than the pivot one
            swap(nums[j], nums[i]); // exchange
        }

        sort(nums.begin() + i + 1, nums.end()); // sort from the pivot element to the end
    }
}