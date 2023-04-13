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


def A(x, y):
    [x0, y0] = TBXY(x, y)
    return SSxy(x, y, x0, y0)/R_(x, x0)


def MakeLine(x, y):
    return [A(x, y), B(x, y)]


def TimX(x, y, y0):
    [a, b] = MakeLine(x, y)
    return (y0 - b)/a


def TimY(x, y, x0):
    return create_line(*MakeLine(x, y))(x0)


def R2(x, y):
    line = create_line(*MakeLine(x, y))
    Y = [line(i) for i in x]
    return R1(y, Y, aver(y))
