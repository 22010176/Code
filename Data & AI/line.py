from random import *


def average(num):
    return sum(num) / len(num)


def R_(num, val):
    return sum([(i-val)**2 for i in num])


def create_line(a, b):
    return lambda x: (a*x + b)


def SSx(num):
    return R_(num, average(num))


def SSxy(x, y):
    ave1, ave2 = average(x), average(y)
    return sum([(a-ave1)*(b-ave2) for (a, b) in zip(x, y)])


def B0(y, b0, x):
    return y - b0*x


def B1(num1, num2):
    return SSxy(num1, num2)/SSx(num1)


def MAE(x, y, Y):
    return average([abs(Y(a)-b) for (a, b) in zip(x, y)])


def MSE(x, y, Y):
    return average([(Y(a)-b)**2 for (a, b) in zip(x, y)])


def RMSE(x, y, Y):
    return MSE(x, y, Y)**0.5


def SSR(x, a, Y):
    return R_([Y(i) for i in x], a)


def SST(y, a):
    return R_(y, a)


def R1(x, y, Y):
    a = average(y)
    return SSR(x, a, Y)/SST(y, a)


def R2(x, y, Y):
    return 1 - (MSE(x, y, Y)*len(y)) / R_(y, average(y))


def linear_line(x, y, digit=5):
    [x_, y_, b1] = [round(i, digit)
                    for i in [average(x), average(y),  B1(x, y)]]
    [ssx, ssxy, b0] = [round(i, digit)
                       for i in [SSx(x), SSxy(x, y), B0(y_, b1, x_)]]
    line = create_line(b1, b0)

    print("__________________________________")
    print("y = b1*x + b0")
    print(f"y = {b1}*x + {b0}")
    print("__________________________________")
    print(f"xtb = {x_}")
    print(f"ytb = {y_}")
    print("__________________________________")
    print(f"SSx = {ssx}")
    print(f"SSxy = {ssxy}")
    print("__________________________________")

    [mae, mse, rmse, ssr, sst, r1, r2] = [round(i, digit) for i in [MAE(x, y, line), MSE(
        x, y, line), RMSE(x, y, line), SSR(x, y_, line), SST(y, y_), R1(x, y, line), R2(x, y, line)]]
    print(f"MAE = {mae}")
    print(f"MSE = {mse}")
    print(f"RMSE = {rmse}")
    print("__________________________________")
    print(f"SSE = SSR = {ssr}")
    print(f"SST = {sst}")
    print(f"R1 = {r1}")
    print(f"R2 = {r2}")

    return x_, y_, ssx, ssxy, mae, mse, rmse, ssr, sst
