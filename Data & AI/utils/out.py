from calculate import *


def out(data, digit):
    [x_, y_, ssx, ssxy, b1, b0, mae, mse, r1, r2,
        ssr, sst] = [round(i, digit) for i in data]
    print("__________________________________")
    print("Y = b1.X + b0")
    print(f"Y = {b1}.X + {b0}")
    print("__________________________________")
    print(f"xtb = {x_}")
    print(f"ytb = {y_}")
    print("__________________________________")
    print(f"SSx = {ssx}")
    print(f"SSxy = {ssxy}")
    print("__________________________________")
    print(f"MAE = {mae}")
    print(f"MSE = {mse}")
    print(f"RMSE = {sqrt(mse)}")
    print("__________________________________")
    print(f"SSE = SSR = {ssr}")
    print(f"SST = {sst}")
    print(f"R1 = {r1}")
    print(f"R2 = {r2}")


def linear_line1(x, y, digit=5):
    [x2, y2] = [[*x], [*y]]
    [x_, y_] = [i for i in [aver(x), aver(y)]]
    [ssx, ssxy] = [i for i in [R_(x, x_), SSxy(x, y, x_, y_)]]
    [b1, b0] = [ssxy/ssx, B0(y_, ssxy/ssx, x_)]
    line = create_line(b1, b0)
    y_pred = [line(i) for i in x2]
    [mae, mse, ssr, sst, r1, r2] = [i for i in [MAE(y2, y_pred), MSE(y2, y_pred),  R_(
        y_pred, y_), R_(y2, y_), R1(y2, y_pred, y_), R2(y2, y_pred, y_)]]
    out([x_, y_, ssx, ssxy, b1, b0, mae, mse, r1, r2, ssr, sst], digit)

    return x_, y_, ssx, ssxy, b1, b0, mae, mse, r1, r2, ssr, sst
