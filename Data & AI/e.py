from utils.calculate import *


def TB(x):
    return aver(x)


def TBXY(x, y):
    return map(aver, [x, y])


def PhuongSai(x):
    return R_(x)/len(x)


def DoLechChuan(x):
    return sqrt(R_(x, aver(x)) / len(x))


def HeSoToungQuan(x, y):
    [xo, yo] = TBXY(x, y)
    return SSxy(x, y, xo, yo)/sqrt(R_(x, xo)*R_(y, yo))


def B(x, y):
    [x0, y0] = TBXY(x, y)
    xy = SSxy(x, y, x0, y0)
    xx = R_(x, x0)
    return B0(y0, xy/xx, x0)
