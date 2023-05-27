#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_DISABLE_MATCHERS

#include <fstream>

#include "../../src/cpp/code_10.cpp"
#include "cpp_deps/catch.hpp"
#include "cpp_deps/json.hpp"

using json = nlohmann::json;

TEST_CASE() {
    ifstream test_file("test/test_json/test_10.json");
    json tests;
    test_file >> tests;

    for (json::iterator it = tests.begin(); it != tests.end(); ++it) {
        const auto& test_case = *it;
        const auto& input = test_case["input"];
        const auto& output = test_case["output"];

        // problem-specific
        Solution sol;
        string s = input["s"].get<string>();
        string p = input["p"].get<string>();
        bool expected = output.get<bool>();
        bool result = sol.isMatch(s, p);
        INFO("TEST CASE " << (it - tests.begin()));
        CHECK(result == expected);
    }
}