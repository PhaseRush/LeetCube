#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_DISABLE_MATCHERS

#include <fstream>

#include "../../src/cpp/code_1.cpp"
#include "cpp_deps/catch.hpp"
#include "cpp_deps/json.hpp"

using json = nlohmann::json;

TEST_CASE() {
    ifstream test_file("../test_json/test_1.json");
    json tests;
    test_file >> tests;

    for (json::iterator it = tests.begin(); it != tests.end(); ++it) {
        const auto& test_case = *it;
        const auto& input = test_case["input"];
        const auto& output = test_case["output"];

        // problem-specific
        Solution sol;
        vector<int> nums = input["nums"].get<vector<int>>();
        int target = input["target"];
        vector<int> expected = output.get<vector<int>>();
        vector<int> result = sol.twoSum(nums, target);
        sort(result.begin(), result.end());
        INFO("TEST CASE " << (it - tests.begin()));
        CHECK(result == expected);
    }
}