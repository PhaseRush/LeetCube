#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_DISABLE_MATCHERS

#include <fstream>

#include "../../src/cpp/code_9.cpp"
#include "cpp_deps/catch.hpp"
#include "cpp_deps/json.hpp"

using json = nlohmann::json;

using namespace std;

TEST_CASE() {
    ifstream test_file("test/test_json/test_9.json");
    json tests;
    test_file >> tests;

    for (json::iterator it = tests.begin(); it != tests.end(); ++it) {
        const auto& test_case = *it;
        const auto& input = test_case["input"];
        const auto& output = test_case["output"];

        // problem-specific
        Solution sol;
        int x = input["x"].get<int>();
        bool expected = output.get<bool>();
        bool result = sol.isPalindrome(x);
        INFO("TEST CASE " << (it - tests.begin()));
        CHECK(result == expected);
    }
}