// 17. Letter Combinations of a Phone Number (Medium)

#include <string>
#include <vector>

using namespace std;

class Solution {
    const string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    /**
        Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

        A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

        @pre 0 <= digits.length <= 4
        @pre digits[i] is a digit in the range ['2', '9'].
    */
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res = {""};

        for (unsigned char d : digits) {
            vector<string> next;

            for (string r : res) {
                for (char l : letters[d - '0']) next.push_back(r + l);
            }

            res.swap(next);
        }

        return res;
    }
};