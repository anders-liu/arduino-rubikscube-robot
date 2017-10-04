from PyQt5.QtCore import Qt, pyqtSlot, pyqtSignal
from PyQt5.QtWidgets import QWidget, QHBoxLayout, QVBoxLayout, QLabel, QSpinBox, QSlider, QGroupBox, QPushButton

class ServoValueWidget(QWidget):
    SERVO_MIN = 90
    SERVO_MAX = 420
    SERVO_DEFAULT = 307

    valueChanged = pyqtSignal(int)

    def __init__(self):
        super().__init__()
        self.currentValue = ServoValueWidget.SERVO_DEFAULT
        self.initUI()

    def initUI(self):
        self.setLayout(self.createLayout())

    def createLayout(self):
        l = QVBoxLayout()
        l.addWidget(self.createMainGroupBox())
        return l

    def createMainGroupBox(self):
        w = self.groupBox = QGroupBox()
        w.setLayout(self.createMainGroupBoxLayout())
        return w

    def createMainGroupBoxLayout(self):
        l = QVBoxLayout()
        l.addLayout(self.createValueEditLayout())
        l.addWidget(self.createValueSlider())
        return l

    def createValueEditLayout(self):
        l = QHBoxLayout()
        l.addWidget(self.createValueLablel())
        l.addWidget(self.createValueSpin())
        return l

    def createValueLablel(self):
        w = QLabel()
        w.setText('Value:')
        return w

    def createValueSpin(self):
        w = self.valueSpin = QSpinBox()
        w.setMinimum(ServoValueWidget.SERVO_MIN)
        w.setMaximum(ServoValueWidget.SERVO_MAX)
        w.setValue(ServoValueWidget.SERVO_DEFAULT)
        w.valueChanged.connect(self.onValueSpinChanged)
        return w

    def createValueSlider(self):
        w = self.valueSlider = QSlider()
        w.setOrientation(Qt.Horizontal)
        w.setMinimum(ServoValueWidget.SERVO_MIN)
        w.setMaximum(ServoValueWidget.SERVO_MAX)
        w.setValue(ServoValueWidget.SERVO_DEFAULT)
        w.valueChanged.connect(self.onValueSliderChanged)
        return w

    def createSetButton(self):
        w = QPushButton()
        w.setText('Set Value')
        w.clicked.connect(self.onSetButtonClicked)
        return w

    @pyqtSlot(int)
    def onValueSpinChanged(self, value):
        if(self.currentValue != value):
            self.currentValue = value
            self.valueSlider.setValue(value)
            self.valueChanged.emit(value)

    @pyqtSlot(int)
    def onValueSliderChanged(self, value):
        if(self.currentValue != value):
            self.currentValue = value
            self.valueSpin.setValue(value)
            self.valueChanged.emit(value)

    @pyqtSlot()
    def onSetButtonClicked(self):


    def setServoName(self, name):
        self.servoName = name
        self.groupBox.setTitle(name)

    def servoName():
        return self.servoName

    def setCurrentValue(self, name):
        pass

    def currentValue():
        pass
