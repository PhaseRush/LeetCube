// 16. 3Sum Closest (Medium)

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

        Return the sum of the three integers.

        You may assume that each input would have exactly one solution.

        @pre 3 <= nums.length <= 500
        @pre -1000 <= nums[i] <= 1000
        @pre -10^4 <= target <= 10^4
    */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (size_t first = 0; first < nums.size() - 2; ++first) {
            size_t second = first + 1;
            size_t third = nums.size() - 1;

            while (second < third) {
                int curr = nums[first] + nums[second] + nums[third];

                if (curr == target) return target;
                else if (abs(curr - target) < abs(closest - target)) closest = curr;

                if (curr < target) ++second;
                else --third;
            }
        }

        return closest;
    }
};