import sys
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

data = ''

head = ''
wifi1 = ''
wifi2 = ''
wifi3 = ''
wifi4 = ''
wifi5 = ''
wifi6 = ''
tail = ''
el_end = '</p>\n\n<p>'

full_page ='';

trigger_buttonSCL = False;
trigger_buttonSDA = False;
trigger_buttonSCK = False;
trigger_buttonMISO = False;
trigger_buttonMOSI = False;
trigger_buttonSS = False;

speed = 0;

f = open("index.html", "r")
full_page = f.read()
#print(f.read())

array = full_page.split('@')
head = array[0]
print(array)
wifi1 = array[1].split('<')[0]
wifi2 = array[2].split('<')[0]
wifi3 = array[3].split('<')[0]
wifi4 = array[4].split('<')[0]
wifi5 = array[5].split('<')[0]
wifi6 = array[6].split('<')[0]


tail = array[6]
tail = tail.split('</p>')[1];


f.close()

def change_info():

   print('change info!')
   global wifi6
   #print(wifi6);
   wifi6_changeable = list(wifi6)
   #print(wifi6_changeable)
   #print(wifi6_changeable[0])



   if (trigger_buttonSCL) :
      wifi6_changeable[0] = "1"
      #print(wifi6_changeable[0])
   else:
      wifi6_changeable[0] = "0"
      #print(wifi6_changeable[0])
   
   if (trigger_buttonSDA)  :
      wifi6_changeable[1] = "1"
   else:
      wifi6_changeable[1] = "0"
   
   if (trigger_buttonSCK) :
      wifi6_changeable[2] = "1"
   else:
      wifi6_changeable[2] = "0"
      
   if (trigger_buttonMISO) :
      wifi6_changeable[3] = "1"
   else:
      wifi6_changeable[3] = "0"
   
   if (trigger_buttonMOSI) :
      wifi6_changeable[4] = "1"
   else:
      wifi6_changeable[4] = "0"
   
   if (trigger_buttonSS)  :
      wifi6_changeable[5] = "1"
   else:
      wifi6_changeable[5] = "0"
   


   #speed change
   if (speed == 0):
      wifi6_changeable[6] = "0"
   
   if (speed == 1):
      wifi6_changeable[6] = "1"
   
   if (speed == 2):
      wifi6_changeable[6] = "2"

   #print(wifi6_changeable[0])
   #print(wifi6_changeable)
   
   wifi6_stroke = ''.join(wifi6_changeable)

   full_page = head+'@'+wifi1+el_end+'@'+wifi2+el_end+'@'+wifi3+el_end+'@'
   full_page += wifi4+el_end+'@'+wifi5+el_end+'@'+wifi6_stroke+el_end+tail

   f = open("index.html", "w")
   f.write(full_page)
   print("The file was saved!");





a = 0
def window():

   global a
   print(a)
   app = QApplication(sys.argv)
   widget = QWidget()
   
   button1 = QPushButton(widget)
   button1.setText("SCL")
   button1.move(64,32)
   button1.clicked.connect(SCL_clicked)

   button2 = QPushButton(widget)
   button2.setText("SDA")
   button2.move(64,64)
   button2.clicked.connect(SDA_clicked)
   
   button3 = QPushButton(widget)
   button3.setText("SCK")
   button3.move(64,96)
   button3.clicked.connect(SCK_clicked)
   
   button4 = QPushButton(widget)
   button4.setText("MISO")
   button4.move(64,128)
   button4.clicked.connect(MISO_clicked)

   button5 = QPushButton(widget)
   button5.setText("MOSI")
   button5.move(64,160)
   button5.clicked.connect(MOSI_clicked)
   
   button6 = QPushButton(widget)
   button6.setText("SS")
   button6.move(64,192)
   button6.clicked.connect(SS_clicked)

   button7 = QPushButton(widget)
   button7.setText("100 milisecond")
   button7.move(64,224)
   button7.clicked.connect(ms100_clicked)

   button8 = QPushButton(widget)
   button8.setText("500 milisecond")
   button8.move(64,256)
   button8.clicked.connect(ms500_clicked)
   
   button9 = QPushButton(widget)
   button9.setText("5 seconds")
   button9.move(64,288)
   button9.clicked.connect(s5_clicked)

   button10 = QPushButton(widget)
   button10.setText("Analog signal")
   button10.move(64,320)
   button10.clicked.connect(on_button_clicked)






                            # last two - width and height
   widget.setGeometry(900,350,250,400)
   widget.setWindowTitle("PyQt5 Button Click Example")
   widget.show()
   sys.exit(app.exec_())


def SCL_clicked():
   global trigger_buttonSCL
   print("SCL clicked")
   trigger_buttonSCL = not trigger_buttonSCL
   print(trigger_buttonSCL)
   change_info()
		
def SDA_clicked():
   global trigger_buttonSDA
   print("SDA clicked")
   trigger_buttonSDA = not trigger_buttonSDA
   print(trigger_buttonSDA)
   change_info()

def SCK_clicked():
   global trigger_buttonSCK
   print("SCK clicked")
   trigger_buttonSCK = not trigger_buttonSCK
   print(trigger_buttonSCK)
   change_info()

def MISO_clicked():
   global trigger_buttonMISO
   print("MISO clicked")
   trigger_buttonMISO = not trigger_buttonMISO
   print(trigger_buttonMISO)
   change_info()

def MOSI_clicked():
   global trigger_buttonMOSI
   print("MOSI clicked")
   trigger_buttonMOSI = not trigger_buttonMOSI
   print(trigger_buttonMOSI)
   change_info()

def SS_clicked():
   global trigger_buttonSS
   print("SS clicked")
   trigger_buttonSS = not trigger_buttonSS
   print(trigger_buttonSS)
   change_info()

def ms100_clicked():
   global speed
   print("speed clicked")
   speed = 2
   print(speed)
   change_info()

def ms500_clicked():
   global speed
   print("speed clicked")
   speed = 1
   print(speed)
   change_info()

def s5_clicked():
   global speed
   print("speed clicked")
   speed = 0
   print(speed)
   change_info()
   
def on_button_clicked():
   alert = QMessageBox()
   alert.setText(str(a))
   alert.exec()
   change_info()


if __name__ == '__main__':
   window()




