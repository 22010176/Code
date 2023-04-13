from utils.calculate import *


def MakeLine(x, y):
    return A(x, y), B(x, y)


def TB(x):
    return aver(x)


def TBXY(x, y):
    return map(aver, [x, y])


def B(x, y):
    [x0, y0] = TBXY(x, y)
    xy = SSxy(x, y, x0, y0)
    xx = R_(x, x0)
    return (B0(y0, xy/xx, x0))


def A(x, y):
    [x0, y0] = TBXY(x, y)
    return (SSxy(x, y, x0, y0)/R_(x, x0))


def TimB(x, y):
    print(B(x, y))


def TimA(x, y):
    print(A(x, y))


def PhuongSai(x):
    print(R_(x)/len(x))


def DoLechChuan(x):
    print(sqrt(R_(x, aver(x)) / len(x)))


def HeSoToungQuan(x, y):
    [xo, yo] = TBXY(x, y)
    print(SSxy(x, y, xo, yo)/sqrt(R_(x, xo)*R_(y, yo)))


def TimX(x, y, y0):
    [a, b] = MakeLine(x, y)
    print((y0 - b)/a)


def TimY(x, y, x0):
    print((create_line(*MakeLine(x, y)))(x0))


def R2(x, y):
    line = create_line(*MakeLine(x, y))
    Y = [line(i) for i in x]
    print(R1(y, Y, aver(y)))


TimY(
    [68, 14, 86, 26, 55, 89, 22, 78, 57],
    [208, 49, 258, 80, 164, 267, 77, 225, 171],
    175
)
