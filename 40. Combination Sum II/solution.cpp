class Solution {
public:
    vector<vector<int>> res; vector<int> comb;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // first sort from begin to end, since each number in candidates may only be used once in the combination
        f(candidates, target, 0);
        return res;
    }

    void f(vector<int>& candidates, int target, int i) {
        if(target == 0) {
            res.push_back(comb);
            return;
        }

        if(i > candidates.size() - 1) return;

        if (candidates[i] <= target) {
            comb.push_back(candidates[i]); // push the current element to the result
            f(candidates, target - candidates[i], i+1); // recursive from the next one
            comb.pop_back(); // if return pop up the element
            while(i < candidates.size() - 1 && candidates[i] == candidates[i+1]) i++; // if the next element is equal to the current one, skip
            f(candidates, target, i+1);
        }
        else
            f(candidates, target, i+1);
    }
};