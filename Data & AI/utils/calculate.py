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


def B1(x, y, x_, y_):
    return SSxy(x, y, x_, y_)/R_(x, x_)


def MAE(y, Y):
    return aver([(b-a if b > a else a-b) for a, b in zip(y, Y)])


def MSE(y, Y):
    return aver([pow(b-a, 2) for a, b in zip(y, Y)])


def R1(y, Y, y_):
    return R_(Y, y_)/R_(y, y_)


def R2(y, Y, y_):
    return 1 - sum([pow(b-a, 2) for a, b in zip(y, Y)]) / R_(y, y_)
