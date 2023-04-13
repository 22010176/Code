from utils.calculate import *
from random import *
from math import *


def aver(num):
    return sum(num) / len(num)


def R_(num, val):
    return sum([pow(i-val, 2) for i in num])


def create_line(a, b):
    return lambda x: (a*x + b)


def SSxy(x, y, x_, y_):
    return sum([(a-x_)*(b-y_) for a, b in zip(x, y)])


def B0(y, a, x):
    return y - a*x


def _B1(x, y, x_, y_):
    return SSxy(x, y, x_, y_)/R_(x, x_)


def _MAE(y, Y):
    return aver([(b-a if b > a else a-b) for a, b in zip(y, Y)])


def _MSE(y, Y):
    return aver([pow(b-a, 2) for a, b in zip(y, Y)])


def _R1(y, Y, y_):
    return R_(Y, y_)/R_(y, y_)


def _R2(y, Y, y_):
    return 1 - sum([pow(b-a, 2) for a, b in zip(y, Y)]) / R_(y, y_)


def _MakeLine(x, y):
    return _A(x, y), _B(x, y)


def _TBXY(x, y):
    return map(aver, [x, y])


def _B(x, y):
    [x0, y0] = _TBXY(x, y)
    xy = SSxy(x, y, x0, y0)
    xx = R_(x, x0)
    return (B0(y0, xy/xx, x0))


def _A(x, y):
    [x0, y0] = _TBXY(x, y)
    return (SSxy(x, y, x0, y0)/R_(x, x0))

# ______________________________________________________________________________________________


def TimB(x, y):
    print(_B(x, y))


def TimA(x, y):
    print(_A(x, y))


def PhuongSai(x):
    print(R_(x)/len(x))


def DoLechChuan(x):
    print(sqrt(R_(x, aver(x)) / len(x)))


def HeSoToungQuan(x, y):
    [xo, yo] = _TBXY(x, y)
    print(SSxy(x, y, xo, yo)/sqrt(R_(x, xo)*R_(y, yo)))


def TimX(x, y, y0):
    [a, b] = _MakeLine(x, y)
    print((y0 - b)/a)


def TimY(x, y, x0):
    print((create_line(*_MakeLine(x, y)))(x0))


def TimR2(x, y):
    print(_R1(y, [create_line(*_MakeLine(x, y))(i) for i in x], aver(y)))


def TimMSE(x, y):
    print(_MSE(y, [create_line(*_MakeLine(x, y))(i)for i in x]))


def TimMAE(x, y):
    print(_MAE(y, [create_line(*_MakeLine(x, y))(i)for i in x]))


def TimRMSE(x, y):
    print(sqrt(_MSE(y, [create_line(*_MakeLine(x, y))(i)for i in x])))


def TimSSxy(x, y):
    print(SSxy(x, y, *_TBXY(x, y)))


def TimSSx(x):
    print(R_(x, aver(x)))


def TimTB(x):
    print(aver(x))
