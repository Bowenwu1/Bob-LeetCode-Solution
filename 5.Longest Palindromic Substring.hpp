/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

*/

class Solution {
private:
    int l, r;
public:
    Solution() {
        l = 0;
        r = 0;
    }
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        for (int i = 0; i < s.length(); ++i) {
            this->findLongest(s, i, i);
            this->findLongest(s, i, i + 1);
        }
        return s.substr(l, r - l + 1);
    }

    void findLongest(string & s, int left, int right) {
        if (s[left] != s[right])
            return;
        while (left > 0 && right < s.length() - 1) {
            --left;
            ++right;
            if (s[left] != s[right]) {
                ++left;
                --right;
                break;
            }
        }
        if (right - left > r - l)  {
            r = right;
            l = left;
        }
    }
};