#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
ZetCode PyQt5 tutorial

In this example, we connect a signal
of a QSlider to a slot of a QLCDNumber.

Author: Jan Bodnar
Website: zetcode.com
Last edited: January 2017
"""

import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QSlider,
                             QVBoxLayout, QApplication)


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        lcd = QLCDNumber(self)
        # create a QSlider of horizontal
        sld = QSlider(Qt.Horizontal, self)
        # create a vbox layout
        vbox = QVBoxLayout()
        # add two widget into the  layout
        vbox.addWidget(lcd)
        vbox.addWidget(sld)

        self.setLayout(vbox)
        # connect event and slot
        sld.valueChanged.connect(lcd.display)

        self.setGeometry(300, 300, 250,250)
        self.setWindowTitle('Signal and slot')
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())