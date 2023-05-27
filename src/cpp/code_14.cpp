// 14. Longest Common Prefix (Easy)

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    /**
        Write a function to find the longest common prefix string amongst an array of strings.

        If there is no common prefix, return an empty string "".

        @pre 1 <= strs.length <= 200
        @pre 0 <= strs[i].length <= 200
        @pre strs[i] consists of only lowercase English letters.
    */
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        string res;
        size_t min_len = strs[0].length();

        if (!min_len) return "";

        for (size_t i = 0; i < min_len; ++i) {
            char common = strs[0][i];

            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != common) return res;
            }

            res += common;
        }

        return res;
    }
};