import datetime
import string
from openpyxl import Workbook
wb = Workbook()

# grab the active worksheet
ws = wb.active
alphabet = string.ascii_uppercase.split()
CATE = ['funcs', 'aveX', 'aveY', 'SSx', 'SSxy', 'B1',
        'B0', 'MAE', 'MSE', "R1", 'R2', 'SSR', 'SST']
# Data can be assigned directly to cells
ws['A4'] = 42
for i in CATE:
    ws['A'+str(CATE.index(i)+1)] = i.upper()
# Rows can also be appended


# Python types will automatically be converted
# ws['A2'] = datetime.datetime.now()

# Save the file
wb.save("./playground/sample.xlsx")
