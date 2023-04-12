from Regression_Line.Chay_code_nay import linear_line1
from Regression_Line.line2 import linear_line3
from random import *
import os
import matplotlib.pyplot as plt
import json


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


def dd(val):
    print(val)
    return val


def test(funcs, *test):
    a = [{'n': i, 'name': f.__name__, 'data': test[i], 'result': map(lambda i:round(i, acc), f(*test[i]))}
         for f in funcs for i in range(len(test))]
    a.sort(key=lambda x: x['n'])
    os.system("cls")
    data = {}
    for i in a:
        temp = i.copy()
        temp.pop('name')
        temp.pop('data')
        # print({CATE[ind]: val
        #       for ind, val in enumerate(temp.get('result'))})
        # temp.update(
        #     {'result'+str(i.get('n')): {CATE[ind]: val for ind, val in enumerate(temp.get('result'))}})
        # temp.update({'result': [*temp.get('result')]})
        # data.update({i.get('name' + str(a.index(i))): temp})

        # out(i)
        # if (a.index(i)+1) % len(funcs) == 0:
        #     print("_"*100)
    # with open('./a.json', 'w') as f:
    #     print(data)
        # json.dump(data, f, indent=2)


def test_Ger(len_cords, nums):
    return [[[random()*20 for _ in range(len_cords)], [random()*100 for _ in range(len_cords)]]for _ in range(nums)]


test(
    [linear_line1],
    [[1, 2, 3, 4], [1, 2, 3.5, 5]],
    *test_Ger(2000, 2)
)
