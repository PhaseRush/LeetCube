# How to run

- Let `n` be the question number

## C++

```shell
make test_n
./test_n
```

Test cases

- C++ + JSON: should be straightforward. If there are multiple expected answers:
  - If return answer in any order, or similar: add the **sorted** answer in JSON, and sort the result in the test file. (see `test/test_17`)
  - If multiple correct answers: add a **list** of all correct answers in JSON, and check that the result is in said list in the test file. (see `test/test_5`)

## Python

```shell
pytest test/test_n.py
```

## JavaScript

```shell
node test/test_n.js
```
