class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            int n = words[0].length(); // get one word length
            int slen = s.length(); // get the string length
            int len = slen - n * words.size(); // get the remaining length
            unordered_map<string, int> mp; // store all the words into map
            vector<int> ans; // store the index into the vector

            for (int i = 0; i < words.size(); i++) ++mp[words[i]]; // get all the words and store them


            for (int i = 0; i < len; i++) { // for loop till the length is less than the remaining

                string st = s.substr(i, n);
                if(mp.find(st) != mp.end()) {
                    unordered_map<string, int> smp;
                    ++smp[st];
                    int flag = 1;

                    for (int j = i + n, k = 1; k < words.size() && j + n <= slen; k++, j = j + n) {
                        string t = s.substr(j, n);
                        if(mp.find(t) != mp.end()) ++smp[t];
                        else {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag && smp == mp) ans.push_back(i);
                }
            }
           return ans;
        }
};