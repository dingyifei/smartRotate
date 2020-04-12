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
import win32api, win32con
import pywintypes


# useful doc https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/


def change_orientation(display: win32api.PyDISPLAY_DEVICEType, settings: list):
    win32api.ChangeDisplaySettingsEx(display.DeviceName, settings, 4)  # 4 is a magic number  I don't know why it worked
    return 0


def get_display_settings(display: win32api.PyDISPLAY_DEVICEType):
    return win32api.EnumDisplaySettings(display.DeviceName)


def get_displays():
    displays = []
    i = 0

    while True:
        try:
            adapter = win32api.EnumDisplayDevices(None, i)
            displays.append(adapter)
        except pywintypes.error:
            break
        i += 1
    return displays


def get_displays_info(displays: list):
    # display_count = win32api.GetSystemMetrics(80)
    displays = []

    for adapter in displays:
        try:
            display = win32api.EnumDisplayDevices(adapter.DeviceName, 0)  # the 0 here is a magic number, take caution
            displays.append(display)
        except pywintypes.error:
            continue
    return displays


def main():
    display_list = get_displays()


if __name__ == "__main__":
    main()
