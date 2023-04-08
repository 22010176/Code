from line import linear_line1 as my
from LOGIC import linear_line2 as ee
# from old import linear_line as eee
from random import *
import os

cate = ['aveX', 'aveY', 'SSx', 'SSxy', 'B1',
        'B0', 'MAE', 'MSE', "R1", 'R2', 'SSR', 'SST']


def out(value):
    print(f'{value[1]}.{value[2]}')


def test(funcs, *test):
    a = [[i, f.__name__, map(lambda i:round(i, 3), f(*test[i]))]
         for f in funcs for i in range(len(test))]
    a.sort(key=lambda x: x[0])
    os.system("cls")
    for i in a:
        i[2] = {key: val for (key, val) in zip(cate, i[2])}
    [(out(i), print("_"*100)
      if (a.index(i)+1) % len(funcs) == 0 else 0) for i in a]


test(
    [my, ee],

    [[i for i in range(0, 200)], [randrange(10, 30) for _ in range(1000)]],
    [[17, 21, 35, 39, 50, 65], [132, 150, 160, 162, 149, 170]],
    [[1, 2, 3, 45], [2, 3, 4, 5]]
)
