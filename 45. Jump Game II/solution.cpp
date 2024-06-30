class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            int i = 0;
            int result = 0;

            while (i <= n - 1)
            {
                if(i + nums[i] >= n - 1) { // if the step equal or larger than the length
                    result++; // jump to the next
                    break; // next loop
                }

                int maxValue = 0;
                int maxIndex = i + 1;
                for(int j = i + 1; j < i + 1 + nums[i]; j++) {
                    if(nums[j] + j > maxValue) {
                        maxValue = nums[j] + j;
                        maxIndex = j;
                    }
                }
                i = maxIndex; // set the currentStep
                result++; // jump to the next
            }
            return result;
        }
};