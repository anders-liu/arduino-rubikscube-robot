import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from MainWindow import Ui_MainWindow

if(__name__ == '__main__'):
    app = QApplication(sys.argv)
    win = Ui_MainWindow()
    ui = QMainWindow()
    win.setupUi(ui)
    ui.show()
    sys.exit(app.exec())
