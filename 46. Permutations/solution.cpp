class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; // store the result that remember the past
        int n = nums.size() - 1; 
        per(0, n, nums, res);
        return res;
    }

    void per(int i, int n, vector<int>& nums, vector<vector<int>>& res) {
        if(i == n) { // if reaches to the end, then return the result
            res.push_back(nums);
            return;
        }

        for(int j = i; j <= n; j++) { // bottom-up from the base case
            swap(nums[i], nums[j]); // swap
            per(i + 1, n, nums, res); // recursive for the next element
            swap(nums[i], nums[j]); // backtracking
        }
    }
};