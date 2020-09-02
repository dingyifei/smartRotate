"""
Copyright (c) 2020-2020, Yifei Ding
SPDX-License-Identifier: Apache-2.0

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.

You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
either express or implied.

See the License for the specific language governing permissions and limitations under the License.
"""
import os
import sys

from PyQt5 import QtWidgets

from mainWindow import Ui_MainWindow

if os.name == "nt":
    from rotate_win import *


class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, monitors: Monitors = Monitors(), *args, obj=None, **kwargs):
        self.monitors = Monitors()

        super(MainWindow, self).__init__(*args, **kwargs)
        self.setupUi(self)

        self.pushButton_default.clicked.connect(self.btn_default)
        self.pushButton_90.clicked.connect(self.btn_90)
        self.pushButton_180.clicked.connect(self.btn_180)
        self.pushButton_270.clicked.connect(self.btn_270)

        self.pushButton_ccw.clicked.connect(self.btn_ccw)
        self.pushButton_cw.clicked.connect(self.btn_cw)

        self.update_list()

    def update_monitors(self):
        self.monitors = Monitors()

    def update_list(self):
        self.update_monitors()
        self.comboBox.clear()
        for monitor in self.monitors:
            self.comboBox.addItem("%s (%s)" % (monitor.get_device_string(), monitor.get_device_id()))

    def get_selected_monitor_pos(self) -> int:
        currentIndex = self.comboBox.currentIndex()
        if currentIndex == -1:
            return 0
        else:
            return currentIndex

    def btn_default(self):
        self.monitors[self.get_selected_monitor_pos()].rotation_default()

    def btn_90(self):
        self.monitors[self.get_selected_monitor_pos()].rotation_90()

    def btn_180(self):
        self.monitors[self.get_selected_monitor_pos()].rotation_180()

    def btn_270(self):
        self.monitors[self.get_selected_monitor_pos()].rotation_270()

    def btn_ccw(self):
        self.monitors[self.get_selected_monitor_pos()].rotate_ccw()

    def btn_cw(self):
        self.monitors[self.get_selected_monitor_pos()].rotate_cw()

    def btn_load(self):
        return 0
        fp = ""
        self.monitors[self.get_selected_monitor_pos()].replace_config(Monitor.from_json(fp).config)

    def btn_save(self):
        return 0
        fp = ""
        self.monitors[self.get_selected_monitor_pos()].to_json(fp)


def main():
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    app.exec()


if __name__ == "__main__":
    main()
