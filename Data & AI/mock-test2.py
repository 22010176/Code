from Chay_cai_nay import *

# Copy code từ dưới dòng này rồi paste vào cái file Chay_cai_nay.py rồi mới chạy. Ko phải chạy trực tiệp ở đây.
O = [0 for _ in range(10000)]

# Bai1
print("Bai 1")
x = [73, 63, 36, 74, 22, 39, 40, 79, 3]
TimTB(x)
# Bai 2
print("Bai 2")
x = [69, 83, 83, 95, 87, 44, 91, 92, 150]
TimPhuongSai(x)
# Bai 3
print("Bai 3")
x = [148, 123, 134, 15, 6, 80, 65, 52, 95]
DoLechChuan(x)
# Bai 4
print("Bai 4")
x = [14, 22, 17, 2, 34, 9, 13, 8, 5, 8]
y = [34, 45, 28, 6, 64, 9, 18, 13, 7, 23]
HeSoToungQuan(x, y)
# Bai 5
print('Bai 5')
x = [30, 44, 24, 35, 50, 16, 37, 32, 16, 49]
y = [27, 19, 29, 26, 30, 24, 39, 41, 13, 40]
TimA(x, y)

# Bai 6
print('Bai 6')
x = [37, 48, 42, 17, 47, 33, 23, 41, 45, 9]
y = [136, 137, 146, 78, 170, 91, 101, 141, 167, 33]
TimB(x, y)

# Bai 7
print('Bai 7')
y = [21, 77, 19, 9, 4, 85, 68, 96, 11]
x = [11, 76, 18, 4, 4, 72, 68, 95, 1]
TimX(x, y, 29)

# Bai 8
print('Bai 8')

# Bai 9
print('Bai 9')
x = [22, 47, 19, 32, 37, 8, 22, 45, 16, 20, *O]
y = [101, 174, 92, 89, 123, 46, 45, 145, 42, 36, *O]
TimA(x, y)

# Bai 10
print('Bai 10')
x = [16, 0, 18, 3, 35, 26, 39, 3, 31, 41]
y = [140, 63, 72, 22, 143, 178, 205, -44, 93, 165]
TimR2(x, y)

# Bai 11 Chiu
print('Bai 11')
x = [-15, 6, 38, 3, 41, -20, 26, 26, -18, -5, *O]
y = [-3, 14, 38, 2, 62, -22, 49, 48, -33, 24, *O]
TimR2(x, y)

# Bai 12
print("Bai 12")
y = [208, 49, 258, 80, 164, 267, 77, 225, 171]
x = [68, 14, 86, 26, 55, 89, 22, 78, 57]
TimY(x, y, 175)
