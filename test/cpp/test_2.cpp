#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_DISABLE_MATCHERS

#include <fstream>
#include <vector>

#include "../../src/cpp/code_2.cpp"
#include "cpp_deps/catch.hpp"
#include "cpp_deps/json.hpp"

using json = nlohmann::json;

using namespace std;

void clear(ListNode*& head) {
    if (!head) return;

    clear(head->next);
    delete head;
    head = nullptr;
}

bool is_equal(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return true;
    if (!l1 || !l2) return false;

    return l1->val == l2->val && is_equal(l1->next, l2->next);
}

ListNode* from_array(const vector<int>& arr, size_t idx) {
    if (idx >= arr.size()) return nullptr;

    return new ListNode(arr[idx], from_array(arr, idx + 1));
}

TEST_CASE() {
    ifstream test_file("test/test_json/test_2.json");
    json tests;
    test_file >> tests;

    for (json::iterator it = tests.begin(); it != tests.end(); ++it) {
        const auto& test_case = *it;
        const auto& input = test_case["input"];
        const auto& output = test_case["output"];

        // problem-specific
        Solution sol;
        ListNode* l1 = from_array(input["l1"].get<vector<int>>(), 0);
        ListNode* l2 = from_array(input["l2"].get<vector<int>>(), 0);
        ListNode* expected = from_array(output.get<vector<int>>(), 0);
        ListNode* result = sol.addTwoNumbers(l1, l2);
        INFO("TEST CASE " << (it - tests.begin()));
        CHECK(is_equal(expected, result));
        clear(l1);
        clear(l2);
        clear(expected);
        clear(result);
    }
}