/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
const int CHAR_NUM = 256;
#include <vector>
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.length() < 1) {
                return 0;
            }
            int result = 0;
            int start = 0;
            int end = 0;

            std::vector<int> label(CHAR_NUM, -1);

            while (end < s.length()) {
                // There is one character repeated
                if (label[s[end] != -1]) {
                    for (;start < label[s[end]] + 1; ++start) {
                        label[s[start]] = -1;
                    }
                }
                label[s[end]] = end;
                if (end - start + 1 > result) {
                    result = end - start + 1;
                }
                ++end;
            }
            return result;
        }
};

/*
Runtime : 12ms