from PyQt5.QtGui import * 
from PyQt5.QtWidgets import * 

class Ui_Tray(object):
    def setupUi(self, Tray: QSystemTrayIcon):
        self.tray = Tray
        self.menu = QMenu()
        self.quit = QAction("Quit")
        self.menu.addAction(self.quit)
        Tray.setContextMenu(self.menu)
        
