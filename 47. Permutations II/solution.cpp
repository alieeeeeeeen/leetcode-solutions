class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> count_map;

        for (auto i : nums) {
            if(count_map.find(i) == count_map.end()) {
                count_map[i] = 1;
            } else {
                count_map[i]++;
            }
        }

        vector<vector<int>> ans;
        n = nums.size();
        vector<int> path;
        permute(count_map, path, ans);

        return ans;

    }

private:
    size_t n;
    void permute(unordered_map<int, int> &count_map, vector<int> path,  vector<vector<int>> &ans) {
        if(n == path.size()) {
            ans.push_back(path);
        }

        for (auto i = count_map.begin(); i!= count_map.end(); ++i) {
            if (i->second) {
                path.push_back(i->first);
                i->second--;
                permute(count_map, path, ans);
                path.pop_back();
                i->second++;
            }
        }
    }
};