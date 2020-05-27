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
from sys import platform
import pywintypes
import win32api
import win32con

if platform.startswith('win32'):
    platform = "windows"


# useful doc https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/


def win_apply_monitor_settings(monitor: win32api.PyDISPLAY_DEVICEType, settings: list):
    """
    apply the DEVMODE to a known display
    :param monitor: a PyDISPLAY_DEVICEType object that have been confirmed to be a monitor
    :param settings: DEVMODE object
    """
    dm_size = 4  # private driver data following in the DEVMODE, not sure how to do it
    win32api.ChangeDisplaySettingsEx(monitor.DeviceName, settings, dm_size, None, win32con.CDS_GLOBAL)


def win_get_monitor_settings(monitor: win32api.PyDISPLAY_DEVICEType):
    """
    Only physical monitor can be accepted because of some magical reason
    :param monitor: a DISPLAY_DEVICE object that have been confirmed to be a monitor
    :return: the DEVMODE object of the monitor object
    """
    return win32api.EnumDisplaySettings(monitor.DeviceName)


def win_get_displays() -> list:
    """
    enumerate all the displays connected at the time.
    :return: list of PyDISPLAY_DEVICEType object
    """
    displays = []
    i = 0

    while True:
        try:
            display = win32api.EnumDisplayDevices(None, i)
            displays.append(display)
        except pywintypes.error:  # if a error happen, it means we find something that's not a object.
            break
        i += 1
    return displays


def win_get_display_info(display: win32api.PyDISPLAY_DEVICEType) -> win32api.PyDISPLAY_DEVICEType:
    """
    obtain detail information of a display, raise pywintypes.error when a display is not a physical monitor
    :param display: a PyDISPLAY_DEVICEType object from EnumDisplayDevices
    :return: return a PyDISPLAY_DEVICEType with detailed information of display
    """
    return win32api.EnumDisplayDevices(display.DeviceName, 0)  # the 0 here is a magic number, take caution


def win_is_monitor(display: win32api.PyDISPLAY_DEVICEType):
    """

    :param display:
    :return:
    """
    try:
        win_get_display_info(display)
    except pywintypes.error:
        return False
    return True


def win_change_orientation(monitor: win32api.PyDISPLAY_DEVICEType, orientation):
    """
    apply a orientation setting that can be win32con.DMDO*
    :param monitor: the PyDISPLAY_DEVICEType object
    :param orientation: win32con.DMDO_* object or 0-3
    """
    settings = win_get_monitor_settings(monitor)
    settings.DisplayOrientation = orientation
    win_apply_monitor_settings(monitor, settings)


def main():
    """
        it's just for testing purposes
    """
    # just random code for testing
    display_list = win_get_displays()
    y = win_get_display_info(display_list[0])
    x = win_get_monitor_settings(display_list[0])
    if win32con.DMDO_90 == x.DisplayOrientation:
        print("yes")
    print(x)


if __name__ == "__main__":
    main()
