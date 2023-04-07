import math


def linear_line(x, y):
    # Get user input for prediction and target
    # prediction = input("Enter the predicted values (separated by commas): ")
    # target = input("Enter the target values (separated by commas): ")

    # Convert input strings to lists of floats
    prediction_list = x
    target_list = y

    # Check if the input lists have the same length
    # if len(prediction_list) != len(target_list):
    #     print("Error: Prediction and target lists must have the same length.\n")
    #     continue  # Ask user for input again

    # Calculate average X and Y
    n = len(prediction_list)
    x_ = sum(prediction_list) / n
    y_ = sum(target_list) / n

    # Calculate sums of squares
    SSx = sum([(x - x_) ** 2 for x in prediction_list])
    SSxy = sum([(x - x_) * (y - y_)
               for x, y in zip(prediction_list, target_list)])

    # Calculate regression line
    a = SSxy / SSx
    b = y_ - a * x_

    # Calculate MAE, MSE, RMSE, SSR, R-squared, and adjusted R-squared
    mae = sum([abs(p - t) for p, t in zip(prediction_list, target_list)]) / n
    mse = sum([(p - t) ** 2 for p, t in zip(prediction_list, target_list)]) / n
    rmse = math.sqrt(mse)
    ssr = sum([(a * x + b - y) ** 2 for x,
              y in zip(prediction_list, target_list)])
    sst = sum([(y - y_) ** 2 for y in target_list])
    R1 = 1 - (ssr / sst)
    R2 = 1 - ((n - 1) / (n - 2 - 1)) * (1 - R1**2)

    # Print results
    # print(f"\nAverage X: {x_:.3f}")
    # print(f"Average Y: {y_:.3f}")
    # print(f"SSx: {SSx:.3f}")
    # print(f"SSxy: {SSxy:.3f}")
    # print(f"Regression line: Y = {a:.3f}X + {b:.3f}")
    # print(f"MAE: {mae:.3f}")
    # print(f"MSE: {mse:.3f}")
    # print(f"RMSE: {rmse:.3f}")
    # print(f"SSR: {ssr:.3f}")
    # print(f"SST: {sst:.3f}")
    # print(f"R-squared: {R1:.3f}")
    # print(f"Adjusted R-squared: {R2:.3f}")
    return x_, y_, SSx, SSxy, mae, mse, rmse, ssr, sst

    # Ask user if they want to continue
    # answer = input("Do you want to continue? (y/n) ")
    # if answer.lower() != 'y':
    #     break  # Exit loop
print(linear_line([1, 2, 3, 4, 5, 6], [.5, 2.9, 3.2, 3.7, 4.8, 6.1]))
