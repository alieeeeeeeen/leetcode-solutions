class Solution {
public:
    vector<vector<int>> res; vector<int> currComb;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currComb; // initiate the current combination
        vector<vector<int>> res;
        combination(candidates, target, 0, 0, currComb, res); // add reference to directly change the result
        return res; // return the result
    }

private:
    void combination(vector<int>& candidates, int target, int currIndex, int currSum) {
        if(currSum > target) return; // go back to the previous combination
        if(currSum == target) {
            res.push_back(currComb); // guarantee that the current combination is the result, add to the vector
            return;
        }

        for(int i = currIndex; i < candidates.size(); i++) {
            currComb.push_back(candidates[i]); // first add to the combination
            currSum += candidates[i]; // add the current element to the sum
            combination(candidates, target, i, currSum); // recursive the current element, since the same number may be chosen
            currComb.pop_back(); // the element does not match, so pop up the element from the vector
            currSum -= candidates[i]; // subtract the element from the sum
        }
    }

};