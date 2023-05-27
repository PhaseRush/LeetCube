import sys
import os
sys.path.append(os.getcwd())

from src.python.code_12 import Solution


def test():
    solu = Solution()
    assert solu.intToRoman(num=3) == "III"
    assert solu.intToRoman(num=58) == "LVIII"
    assert solu.intToRoman(num=1994) == "MCMXCIV"
