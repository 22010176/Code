from calculate import *

O = [0 for _ in range(10000)]
# Bai 1
print('Bai 1')
print(aver([73, 63, 36, 74, 22, 39, 40, 79, 3]))

# Bai 2
print('Bai 2')
e = [69, 83, 83, 95, 87, 44, 91, 92, 150]
print(R_(e, aver(e))/len(e))

# Bai 3
print('Bai 3')
e = [148, 123, 134, 15, 6, 80, 65, 52, 95]
print(DoLechChuan(e))

# Bai 4
print('Bai 4')
x = [14, 22, 17, 2, 34, 9, 13, 8, 5, 8]
y = [34, 45, 28, 6, 64, 9, 18, 13, 7, 23]
print(SSxy(x, y, aver(x), aver(y))/sqrt(R_(x, aver(x))*R_(y, aver(y))))

# Bai 5
print('Bai 5')
x = [30, 44, 24, 35, 50, 16, 37, 32, 16, 49]
y = [27, 19, 29, 26, 30, 24, 39, 41, 13, 40]
print(B1(x, y, aver(x), aver(y)))

# Bai 6
print('Bai 6')
x = [37, 48, 42, 17, 47, 33, 23, 41, 45, 9]
y = [136, 137, 146, 78, 170, 91, 101, 141, 167, 33]
print(B0(aver(y), B1(x, y, aver(x), aver(y)), aver(x)))

# Bai 7
print('Bai 7')
y = [21, 77, 19, 9, 4, 85, 68, 96, 11]
x = [11, 76, 18, 4, 4, 72, 68, 95, 1]
b1 = B1(x, y, aver(x), aver(y))
b0 = B0(aver(y), b1, aver(x))
print((29-b0)/b1)

# Bai 8
print('Bai 8')

# Bai 9
print('Bai 9')
x = [22, 47, 19, 32, 37, 8, 22, 45, 16, 20, *O]
y = [101, 174, 92, 89, 123, 46, 45, 145, 42, 36, *O]
print(B1(x, y, aver(x), aver(y)))

# Bai 10
print('Bai 10')
x = [16, 0, 18, 3, 35, 26, 39, 3, 31, 41]
y = [140, 63, 72, 22, 143, 178, 205, -44, 93, 165]
a = B1(x, y, aver(x), aver(y))
b = B0(aver(y), a, aver(x))
line = create_line(a, b)
Y = [line(i) for i in x]
print('R2 =', R1(y, Y, aver(y)))
print('R2 =', R2(y, Y, aver(y)))

# Bai 11
print('Bai 11')
x = [-15, 6, 38, 3, 41, -20, 26, 26, -18, -5]
y = [-3, 14, 38, 2, 62, -22, 49, 48, -33, 24]
a = B1(x, y, aver(x), aver(y))
b = B0(aver(y), a, aver(x))
line = create_line(a, b)
Y = [line(i) for i in x]
print('R2 =', R1(y, Y, aver(y)))
print('R2 =', R2(y, Y, aver(y)))

# Bai 12
y = [208, 49, 258, 80, 164, 267, 77, 225, 171]
x = [68, 14, 86, 26, 55, 89, 22, 78, 57]
a = B1(x, y, aver(x), aver(y))
b = B0(aver(y), a, aver(x))
line = create_line(a, b)
print(line(175))
