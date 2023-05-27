// 15. 3Sum (Medium)

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

        Notice that the solution set must not contain duplicate triplets.

        @pre 3 <= nums.length <= 3000
        @pre -10^5 <= nums[i] <= 10^5
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (size_t first = 0; first < nums.size() - 2 && nums[first] <= 0; ++first) {
            if (first && nums[first - 1] == nums[first]) continue;

            size_t second = first + 1;
            size_t third = nums.size() - 1;

            while (second < third) {
                int s = nums[first] + nums[second] + nums[third];

                if (s < 0) ++second;
                else if (s > 0) --third;
                else {
                    res.push_back({nums[first], nums[second], nums[third]});

                    while (second < third && nums[second] == res.back()[1]) ++second;

                    while (second < third && nums[third] == res.back()[2]) --third;
                }
            }
        }

        return res;
    }
};