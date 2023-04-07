from line import linear_line
from LOGIC import linear_line


# def print(*a):
#     pass


def test(func1, func2, *test):

    func1_res = func1(*test)
    func2_res = func2(*test)
    print(func1_res)
    print(func2_res)


print(*zip([1, 2, 3], [4, 5, 6]))
