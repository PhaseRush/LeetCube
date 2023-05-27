# Formatting

## General

Please format your code with a formatter before upload.

### C++ Formatting:

`blank` uses the following formatting style, in conjunction with VSCode's formatter that ships with the C++ extension by default (add the following to the `C_Cpp: Clang_format_fallback Style` and `C_Cpp: Clang_format_style` settings in VSCode):

```js
{ BasedOnStyle: Google, UseTab: Never, IndentWidth: 4, AllowShortIfStatementsOnASingleLine: AllIfsAndElse, ColumnLimit: 150, DerivePointerAlignment: false, PointerAlignment: Left, AllowShortBlocksOnASingleLine: Always, AllowShortFunctionsOnASingleLine: All, AllowShortLoopsOnASingleLine: true, FixNamespaceComments: false, AccessModifierOffset: -4}
```

## Test cases
### JSON

Upload to the `test/test_json` directory. Format:

```
[
    {
        "contributor": ...,
        "input": {
            "input1": ...,
            ...
        },
        "output": ...
    },
    ...
]
```

Input names should match the argument/example input parameter names. Given test cases (examples) have `"given"` as contributor.

If the problem allows the answer to be returned in any order, or similar:
- sort each entry in the output list, if necessary (list of lists)
- sort the entire output list
- add the **sorted** answer in JSON, and add code to sort the result in the test file. (see [`test/cpp/test_17.cpp`](../test/cpp/test_17.cpp), [`test/test_json/test_17.json`](../test/test_json/test_17.json))

If multiple correct answers:
-   add a **list** of all correct answers in JSON, and add code to check that the result is in said list in the test file. (see [`test/cpp/test_5.cpp`](../test/cpp/test_5.cpp), [`test/test_json/test_5.json`](../test/test_json/test_5.json))