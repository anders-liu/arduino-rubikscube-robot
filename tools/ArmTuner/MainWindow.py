from PyQt5.QtCore import Qt, pyqtSlot, pyqtSignal
from PyQt5.QtWidgets import QMainWindow
from ServoValueWidget import ServoValueWidget

class MainWindow(QMainWindow):
    WIN_W = 1000
    WIN_H = 618

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Robotic Arm Tuner')
        self.resize(MainWindow.WIN_W, MainWindow.WIN_H)
        self.setMaximumSize(MainWindow.WIN_W, MainWindow.WIN_H)
        self.setMinimumSize(MainWindow.WIN_W, MainWindow.WIN_H)

        self.setCentralWidget(self.createServoValueWidget())

    def createServoValueWidget(self):
        w = self.s = ServoValueWidget()
        w.setServoName('L1')
        w.valueChanged.connect(self.onServoValueChanged)
        return w

    @pyqtSlot(str, int)
    def onServoValueChanged(self, name, value):
        self.setWindowTitle(f'{name} = {value}')
