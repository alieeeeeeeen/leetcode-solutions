class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(i);
        }

        vector<vector<string>> ans;

        for (auto it:mp) {
            vector<string> mapped;
            for(auto each:it.second) {
                mapped.push_back(strs[each]);
            }
            ans.push_back(mapped);
        }
        return ans;
    }
};