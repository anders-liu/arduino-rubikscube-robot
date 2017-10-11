from PyQt5.QtCore import Qt, pyqtSlot, pyqtSignal
from PyQt5.QtWidgets import QWidget, QHBoxLayout, QVBoxLayout, QLabel, QSpinBox, QSlider, QGroupBox, QPushButton

class ServoValueWidget(QWidget):
    SERVO_MIN = 90
    SERVO_MAX = 420
    SERVO_DEFAULT = 307

    valueChanged = pyqtSignal(str, int)

    def __init__(self):
        super().__init__()
        self.__currentValue = ServoValueWidget.SERVO_DEFAULT
        self.__initUI()

    def setServoName(self, name):
        self.__servoName = name
        self.__groupBox.setTitle(name)

    def servoName():
        return self.__servoName

    def setCurrentValue(self, value):
        self.__currentValue = value
        self.__valueSlider.setValue(value)
        self.__valueSpin.setValue(value)

    def currentValue():
        return self.__currentValue

    def __initUI(self):
        self.setLayout(self.__createLayout())

    def __createLayout(self):
        l = QVBoxLayout()
        l.addWidget(self.__createMainGroupBox())
        return l

    def __createMainGroupBox(self):
        w = self.__groupBox = QGroupBox()
        w.setLayout(self.__createMainGroupBoxLayout())
        return w

    def __createMainGroupBoxLayout(self):
        l = QVBoxLayout()
        l.addLayout(self.__createValueEditLayout())
        l.addWidget(self.__createValueSlider())
        l.addWidget(self.__createSetButton())
        return l

    def __createValueEditLayout(self):
        l = QHBoxLayout()
        l.addWidget(self.__createValueLablel())
        l.addWidget(self.__createValueSpin())
        return l

    def __createValueLablel(self):
        w = QLabel()
        w.setText('Value:')
        return w

    def __createValueSpin(self):
        w = self.__valueSpin = QSpinBox()
        w.setMinimum(ServoValueWidget.SERVO_MIN)
        w.setMaximum(ServoValueWidget.SERVO_MAX)
        w.setValue(ServoValueWidget.SERVO_DEFAULT)
        w.valueChanged.connect(self.__onValueSpinChanged)
        return w

    def __createValueSlider(self):
        w = self.__valueSlider = QSlider()
        w.setOrientation(Qt.Horizontal)
        w.setMinimum(ServoValueWidget.SERVO_MIN)
        w.setMaximum(ServoValueWidget.SERVO_MAX)
        w.setValue(ServoValueWidget.SERVO_DEFAULT)
        w.valueChanged.connect(self.__onValueSliderChanged)
        return w

    def __createSetButton(self):
        w = QPushButton()
        w.setText('Set Value')
        w.clicked.connect(self.__onSetButtonClicked)
        return w

    def __emitValueChanged(self, value):
        if(self.__currentValue != value):
            self.__currentValue = value
            if(self.__valueSlider.value != value):
                self.__valueSlider.setValue(value)
            if(self.__valueSpin.value != value):
                self.__valueSpin.setValue(value)
            self.valueChanged.emit(self.__servoName, value)

    @pyqtSlot(int)
    def __onValueSpinChanged(self, value):
        self.__emitValueChanged(value)

    @pyqtSlot(int)
    def __onValueSliderChanged(self, value):
        self.__emitValueChanged(value)

    @pyqtSlot()
    def __onSetButtonClicked(self):
        self.__emitValueChanged(self.__currentValue)
