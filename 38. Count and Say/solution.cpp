class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        else {
            string res = ""; // initiate the result
            string tmp = countAndSay(n - 1); // get the digit string
            int count = 1, curr = tmp[0], i = 1; // set the count = 1
            while (i < tmp.length()) { // loop from 1 to tha last second one
                if (tmp[i] == curr) { // if equal
                    count++;
                } else {
                    res += to_string(count); // first add count
                    res += curr; // then add current number
                    count = 1; // reset count
                    curr = tmp[i]; // move forward the curr
                }
                i++;
            }
            res += to_string(count);
            res += curr; // add the last element
            return res;
        }
    }
};