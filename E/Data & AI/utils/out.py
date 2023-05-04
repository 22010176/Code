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
    [x_, y_] = [i for i in [_aver(x), _aver(y)]]
    [ssx, ssxy] = [i for i in [_R_(x, x_), _SSxy(x, y, x_, y_)]]
    [b1, b0] = [ssxy/ssx, _B0(y_, ssxy/ssx, x_)]
    line = _create_line(b1, b0)
    y_pred = [line(i) for i in x2]
    [mae, mse, ssr, sst, r1, r2] = [i for i in [_MAE(y2, y_pred), _MSE(y2, y_pred),  _R_(
        y_pred, y_), _R_(y2, y_), _R1(y2, y_pred, y_), _R2(y2, y_pred, y_)]]
    out([x_, y_, ssx, ssxy, b1, b0, mae, mse, r1, r2, ssr, sst], digit)

    return x_, y_, ssx, ssxy, b1, b0, mae, mse, r1, r2, ssr, sst
