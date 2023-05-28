import json
from timeit import default_timer as timer

from src.python.code_2709 import Solution


def test():
    with open('../test_json/test_2709.json', 'r') as f:
        data = json.load(f)
        print(f"Running {len(data)} cases")

    s = Solution()

    start = timer()
    for case in data:
        assert s.canTraverseAllPairs(nums=case['input']['nums']) == case['output'], \
            f"Failed case. Should have been {case['output']}: {case['input']}"
    end = timer()

    # Accepted solution gets ~ 110ms
    print(f"Elapsed time: {(end - start) * 1000: .0f} ms")


if __name__ == '__main__':
    test()
