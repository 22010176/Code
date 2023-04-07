from line import linear_line as func2
from LOGIC import linear_line as func1

import os


def test(funcs, *test):
    a = [f(*i) for f in funcs for i in test]

    os.system("cls")
    [print(i) for i in a]


test(
    [func2, func2, func2],

    [[1, 2, 34], [1, 5, 3]],
    [[1, 2, 3], [2, 3, 4]]

)
