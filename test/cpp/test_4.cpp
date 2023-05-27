#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_DISABLE_MATCHERS

#include <fstream>

#include "../../src/cpp/code_4.cpp"
#include "cpp_deps/catch.hpp"
#include "cpp_deps/json.hpp"

using json = nlohmann::json;

TEST_CASE() {
    ifstream test_file("test/test_json/test_4.json");
    json tests;
    test_file >> tests;

    for (json::iterator it = tests.begin(); it != tests.end(); ++it) {
        const auto& test_case = *it;
        const auto& input = test_case["input"];
        const auto& output = test_case["output"];

        // problem-specific
        Solution sol;
        vector<int> nums1 = input["nums1"].get<vector<int>>();
        vector<int> nums2 = input["nums2"].get<vector<int>>();
        double expected = output.get<double>();
        double result = sol.findMedianSortedArrays(nums1, nums2);
        INFO("TEST CASE " << (it - tests.begin()));
        CHECK(result == expected);
    }
}