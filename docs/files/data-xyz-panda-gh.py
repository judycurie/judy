#
import serial
import time
import pandas as pd

ser = serial.Serial('COM19', 9800, timeout=1)

def getdata():

   line = ser.readline() 
   if line:
        string = line.decode()  
        string = string.replace("\r\n","")  
        stringlist = string.split(";", 3)
        x = float(stringlist[0])
        y = float(stringlist[1])
        z = float(stringlist[2])
        
        return [x,y,z]
   
i = 0
x = []
y= []
z = []
while i<20:
   
    xyz = getdata()
    print (xyz)
    if type(xyz)== list:
        if xyz[0] != 0:
    
            x.append(xyz[0])
            y.append(xyz[1])
            z.append(xyz[2])
            i+=1
        
        
    
df = pd.DataFrame([x,y,z], index=['x', 'y', 'z'])
path = 'C:\\Users\\judyt\\Dropbox\\2023_FabAcademy2023\\week14\\pandas_to_excel.xlsx'
df.to_excel(excel_writer=path, sheet_name='new_sheet_name')
        


    
    



