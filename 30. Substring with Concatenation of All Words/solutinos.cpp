class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            int n = words[0].length(); // get one word length
            int slen = s.length(); // get the string length
            int len = slen - n * words.size(); // get the remaining length
            unordered_map<string, int> mp; // store all the words into map
            vector<int> ans; // to store the index

            for (int i = 0; i < words.size(); i++) ++mp[words[i]]; // get all the words and store them


            for (int i = 0; i < len; i++) { // for loop till the length is less than the remaining

                string st = s.substr(i, n); // get the substring of the string
                if(mp.find(st) != mp.end()) { // find the substring in the map
                    unordered_map<string, int> smp; // create new map
                    ++smp[st]; // record the word once
                    int flag = 1; // flag

                    for (int j = i + n, k = 1; k < words.size() && j + n <= slen; k++, j = j + n) { // from the position to the position + word's size, find other words
                        string t = s.substr(j, n); // get the substring
                        if(mp.find(t) != mp.end()) ++smp[t]; // find in the new created map
                        else {  // did not find
                            flag = 0;  // flag
                            break; // discontinue the for loop
                        }
                    }
                    if(flag && smp == mp) ans.push_back(i); // store the index in the vector
                }
            }
           return ans;
        }
};