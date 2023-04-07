import math
import matplotlib.pyplot as plt

while True:
    # Get user input for prediction and target
    prediction = input("Enter the predicted values (separated by commas): ")
    target = input("Enter the target values (separated by commas): ")

    # Convert input strings to lists of floats
    prediction_list = [float(x.strip()) for x in prediction.split(',')]
    target_list = [float(x.strip()) for x in target.split(',')]

    # Check if the input lists have the same length
    if len(prediction_list) != len(target_list):
        print("Error: Prediction and target lists must have the same length.\n")
        continue  # Ask user for input again

    # Calculate average X and Y
    n = len(prediction_list)
    average_x = sum(prediction_list) / n
    average_y = sum(target_list) / n

    # Calculate sums of squares
    SSx = sum([(x - average_x) ** 2 for x in prediction_list])
    SSxy = sum([(x - average_x) * (y - average_y) for x, y in zip(prediction_list, target_list)])

    # Calculate regression line
    a = SSxy / SSx
    b = average_y - a * average_x

    # Calculate variance of target variable
    variance_y = sum([(y - average_y) ** 2 for y in target_list]) / n

    # Calculate MAE, MSE, RMSE, SSR, SST, R-squared, Alter R-squared
    mae = sum([abs(p - t) for p, t in zip(prediction_list, target_list)]) / n
    mse = sum([(p - t) ** 2 for p, t in zip(prediction_list, target_list)]) / n
    rmse = math.sqrt(mse)
    SSR = sum([(a * x + b - y) ** 2 for x, y in zip(prediction_list, target_list)])
    SST = sum([(y - average_y) ** 2 for y in target_list])
    R1 = 1 - (SSR / SST)
    R2 = 1 - (mse / (n * variance_y))

    # Draw scatter plot
    plt.scatter(prediction_list, target_list)
    plt.plot(prediction_list, [a * x + b for x in prediction_list], color='red')
    plt.xlabel('Predicted Values')
    plt.ylabel('Target Values')
    plt.title('Scatter plot with regression line')
    plt.show()

    # Print results
    print(f"\nAverage X: {average_x:.3f}")
    print(f"Average Y: {average_y:.3f}")
    print(f"SSx: {SSx:.3f}")
    print(f"SSxy: {SSxy:.3f}")
    print(f"Regression line: Y = {a:.3f}X + {b:.3f}")
    print(f"MAE: {mae:.3f}")
    print(f"MSE: {mse:.3f}")
    print(f"RMSE: {rmse:.3f}")
    print(f"SSR: {SSR:.3f}")
    print(f"SST: {SST:.3f}")
    print(f"R-squared: {R1:.3f}")
    print(f"Alternative R-squared: {R2:.3f}")

    # Ask user if they want to continue
    answer = input("\nDo you want to continue? (y/n) \n")
    if answer.lower() != 'y':
        break  # Exit loop
