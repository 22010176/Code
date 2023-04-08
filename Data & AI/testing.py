from line import linear_line1 as my
from LOGIC import linear_line2 as ee
from random import *
import os
import matplotlib.pyplot as plt


def drawGrap(*t):
    # Sort the prediction and target lists in ascending order
    for x, y, a, b in t:
        x, y = zip(*sorted(zip(x, y)))

        # Draw Graph
        plt.scatter(x, y)
        plt.plot(x, [
            a * x + b for x in x], color='blue')

        # Present regression line as dashed lines
        for i in range(len(x)-1):
            x1, y1 = x[i], y[i]
            x2, y2 = x[i+1], y[i+1]
            plt.plot([x1, x2], [y1, y2], color='blue', linestyle='--', linewidth=0.2, alpha=0.1,
                     solid_capstyle='round', dash_capstyle='round', dash_joinstyle='round', dashes=[3, 3], zorder=0)

        for i in range(len(x)):
            plt.annotate(
                f"({x[i]}, {y[i]})", (x[i], y[i]))

    plt.xlabel('Predicted Values')
    plt.ylabel('Target Values')
    plt.title('Regression Line Graph')
    plt.show()


def out(value):
    print(f'{value[1]}.{value[2]}')


CATE = ['aveX', 'aveY', 'SSx', 'SSxy', 'B1',
        'B0', 'MAE', 'MSE', "R1", 'R2', 'SSR', 'SST']

acc = 9


def test(funcs, *test):
    a = [[i, f.__name__, map(lambda i:round(i, acc), f(*test[i]))]
         for f in funcs for i in range(len(test))]
    a.sort(key=lambda x: x[0])
    os.system("cls")
    for i in a:
        i[2] = {key: val for (key, val) in zip(CATE, i[2])}
        out(i)
        if (a.index(i)+1) % len(funcs) == 0:
            print("_"*100)


nums = 30000


def test_Ger(len_cords, nums):
    return [[[random()*20 for _ in range(len_cords)], [random()*100 for _ in range(len_cords)]]for _ in range(nums)]


test(
    [my, ee],
    [[1, 2, 3, 4], [1, 2, 3.5, 5]],
    # *test_Ger(1000, 20)
)
