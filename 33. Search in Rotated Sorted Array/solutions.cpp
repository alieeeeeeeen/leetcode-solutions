class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // get the left and right element

        while(left < right) { // binary search base condition
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if (nums[left] < nums[mid] && target >= nums[left] && target < nums[mid] || (
                nums[left] > nums[mid] && (target > nums[left] || target > nums[right]) 
            )) { // if left element is less than mid element, which is simple or
                 // the left element is larger than the mid which means the mid is one of the element
                 // from the left subset array
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};