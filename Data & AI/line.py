from random import *


def average(num):
    return Sum(num) / len(num)


def Sum(num):
    sum = 0
    for i in num:
        sum += i
    return sum


def R_(num, val):
    return Sum([(i-val)**2 for i in num])


def create_line(a, b):
    return lambda x: (a*x + b)


def SSx(num):
    return R_(num, average(num))


def SSxy(num1, num2):
    ave1, ave2 = average(num1), average(num2)
    return Sum([(num1[i]-ave1)*(num2[i]-ave2) for i in range(len(num1))])


def B0(y, b0, x):
    return y - b0*x


def B1(num1, num2):
    return SSxy(num1, num2)/SSx(num1)


def MAE(x, y, Y):
    return average([abs(Y(x[i])-y[i]) for i in range(len(x))])


def MSE(x, y, Y):
    return average([(Y(x[i])-y[i])**2 for i in range(len(x))])


def RMSE(x, y, Y):
    return MSE(x, y, Y)**0.5


def R1(x, y, Y):
    a = average(y)
    return R_([Y(i) for i in x], a) / R_(y, a)


def R2(x, y, Y):
    return 1 - (MSE(x, y, Y)*len(y)) / R_(y, average(y))


def linear_line(x, y, digit=5):
    [x_, y_, b1] = [round(i, digit)
                    for i in [average(x), average(y),  B1(x, y)]]
    [ssx, ssxy, b0] = [round(i, digit) for i in [
        SSx(x), SSxy(x, y), B0(y_, b1, x_)]]
    line = create_line(b1, b0)

    print(f"xtb = {x_}")
    print(f"ytb = {y_}")
    print(f"SSx = {ssx}")
    print(f"SSxy = {ssxy}")
    print("y = b1*x + b0")
    print(f"y = {b1}*x + {b0}")

    [mae, mse, rmse, r1, r2] = [round(i, digit) for i in [MAE(
        x, y, line), MSE(x, y, line), RMSE(x, y, line), R1(x, y, line), R2(x, y, line)]]
    print(f"MAE = {mae}")
    print(f"MSE = {mse}")
    print(f"RMSE = {rmse}")
    print(f"R1 = {r1}")
    print(f"R2 = {r2}")

    return {x_, y_, b1, b0, ssx, ssxy, mae, mse, rmse, r1, r2}


linear_line(
    [1, 2, 3, 4, 5, 6],
    [.5, 2.9, 3.2, 3.7, 4.8, 6.1],
    digit=5
)
# xtb = 3.5
# ytb = 3.5333
# SSx = 17.5
# SSxy = 17.1
# y = 0.9771*x + 0.1135
# MAE = 0.3705
# MSE = 0.204
# RMSE = 0.4517
# R1 = 0.9317
