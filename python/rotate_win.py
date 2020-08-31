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

import pywintypes
import win32api
import win32con
import xml


# useful doc https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/

class Monitor:
    def __init__(self, device: win32api.PyDISPLAY_DEVICEType, ):
        self.device = device
        self.config = win32api.EnumDisplaySettingsEx(device.DeviceName, win32con.ENUM_CURRENT_SETTINGS)

    def update_config(self):
        self.config = win32api.EnumDisplaySettingsEx(self.device.DeviceName, win32con.ENUM_CURRENT_SETTINGS)

    def apply_config(self, dwflags=win32con.CDS_RESET):
        dm_size = 4  # private driver data following in the DEVMODE
        return win32api.ChangeDisplaySettingsEx(self.device.DeviceName, self.config, dwflags)

    def rotation_0(self):
        self.config.DisplayOrientation = win32con.DMDO_DEFAULT
        self.apply_config()

    def rotation_90(self):
        self.config.DisplayOrientation = win32con.DMDO_90
        self.apply_config()

    def rotation_180(self):
        self.config.DisplayOrientation = win32con.DMDO_180
        self.apply_config()

    def rotation_270(self):
        self.config.DisplayOrientation = win32con.DMDO_270
        self.apply_config()

    def rotate_cw(self):
        current = self.config.DisplayOrientation
        if current == win32con.DMDO_DEFAULT:
            self.config.DisplayOrientation = win32con.DMDO_270
        elif current == win32con.DMDO_90:
            self.config.DisplayOrientation = win32con.DMDO_DEFAULT
        elif current == win32con.DMDO_180:
            self.config.DisplayOrientation = win32con.DMDO_90
        elif current == win32con.DMDO_270:
            self.config.DisplayOrientation = win32con.DMDO_180
        self.apply_config()

    def rotate_ccw(self):
        current = self.config.DisplayOrientation
        if current == win32con.DMDO_DEFAULT:
            self.config.DisplayOrientation = win32con.DMDO_90
        elif current == win32con.DMDO_90:
            self.config.DisplayOrientation = win32con.DMDO_180
        elif current == win32con.DMDO_180:
            self.config.DisplayOrientation = win32con.DMDO_270
        elif current == win32con.DMDO_270:
            self.config.DisplayOrientation = win32con.DMDO_DEFAULT
        self.apply_config()


class Monitors():
    def __get_monitors(self):
        displays = []
        i = 0
        while True:
            try:
                display = win32api.EnumDisplayDevices(None, i)
                displays.append(display)
            except pywintypes.error:  # run out of displays
                break
            i += 1

        monitors = []
        for display in displays:
            try:
                win32api.EnumDisplayDevices(display.DeviceName, 0)
                monitors.append(Monitor(display))
            except pywintypes.error:
                continue

        return monitors

    def __init__(self):
        self.monitors = self.__get_monitors()

    def update_monitors(self):
        self.monitors = self.__get_monitors()

def main():
    """
        it's just for testing purposes
    """


if __name__ == "__main__":
    main()
