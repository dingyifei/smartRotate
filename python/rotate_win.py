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
import json


# useful doc https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/


class Monitor:
    """
    A class to represent a monitor(an adapter to be exact)
    """

    def __init__(self, adapter: win32api.PyDISPLAY_DEVICEType,
                 device: win32api.PyDISPLAY_DEVICEType = None,
                 config: pywintypes.DEVMODEType = None):
        self.adapter = adapter
        if device is not None:
            self.device = device
        else:
            self.device = win32api.EnumDisplayDevices(adapter.DeviceName, 0)  # Device is just for readability
        if config is not None:
            self.config = config
        else:
            self.config = win32api.EnumDisplaySettingsEx(adapter.DeviceName, win32con.ENUM_CURRENT_SETTINGS)

    def __str__(self) -> str:
        return self.get_device_string()

    # def __eq__(self, other):
    #     """
    #     Compare two monitor object, return false when Device and Adapter doesn't match with the input
    #     :param other: another monitor object
    #     :return: true if they are the same (regardless of the config)
    #     """
    #     # TODO: compare two monitor

    def update_config(self):
        """
        This function call win32 api to get the current config
        """
        self.config = win32api.EnumDisplaySettingsEx(self.adapter.DeviceName, win32con.ENUM_CURRENT_SETTINGS)

    def apply_config(self) -> int:
        """
        apply the config changes to windows.
        :return: successful when it return 0
        """
        return win32api.ChangeDisplaySettingsEx(self.adapter.DeviceName, self.config)

    def replace_config(self, monitor):
        """
        replace the config of the current monitor object with a config from another monitor object
        :param monitor:
        """
        self.config = monitor.config

    def get_device_id(self) -> str:
        """
        return the DeviceID of the monitor
        :return:
        """
        return self.device.DeviceID

    def get_device_key(self) -> str:
        """
        return the DeviceKey of the monitor
        :return:
        """
        return self.adapter.DeviceKey

    def get_device_string(self) -> str:
        """
        return the DeviceString of the monitor
        :return:
        """
        return self.device.DeviceString

    def swap_pels(self):
        """
        Swap the vertical and horizontal pixel count
        """
        self.config.PelsHeight, self.config.PelsWidth = self.config.PelsWidth, self.config.PelsHeight

    def rotation_default(self):
        """
        Set rotation to 0 degree
        """
        if self.config.DisplayOrientation == win32con.DMDO_90 or \
                self.config.DisplayOrientation == win32con.DMDO_270:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_DEFAULT
        self.apply_config()

    def rotation_90(self):
        """
        Set monitor rotation to 90 degrees
        """
        if self.config.DisplayOrientation == win32con.DMDO_180 or \
                self.config.DisplayOrientation == win32con.DMDO_DEFAULT:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_90
        self.apply_config()

    def rotation_180(self):
        """
        Set monitor rotation to 180 degrees
        """
        if self.config.DisplayOrientation == win32con.DMDO_90 or \
                self.config.DisplayOrientation == win32con.DMDO_270:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_180
        self.apply_config()

    def rotation_270(self):
        """
        Set monitor rotation to 270 degrees
        """
        if self.config.DisplayOrientation == win32con.DMDO_180 or \
                self.config.DisplayOrientation == win32con.DMDO_DEFAULT:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_270
        self.apply_config()

    def rotate_cw(self):
        """
        Rotate the monitor clock wise for 90 degrees
        """
        current = self.config.DisplayOrientation
        if current == win32con.DMDO_DEFAULT:
            self.rotation_270()
        elif current == win32con.DMDO_90:
            self.rotation_default()
        elif current == win32con.DMDO_180:
            self.rotation_90()
        elif current == win32con.DMDO_270:
            self.rotation_180()

    def rotate_ccw(self):
        """
        Rotate the monitor counter-clock wise for 90 degrees
        """
        current = self.config.DisplayOrientation
        if current == win32con.DMDO_DEFAULT:
            self.rotation_90()
        elif current == win32con.DMDO_90:
            self.rotation_180()
        elif current == win32con.DMDO_180:
            self.rotation_270()
        elif current == win32con.DMDO_270:
            self.rotation_default()


def get_monitors() -> list:
    """
    this function return a list of monitors recognize by the computer
    :return: A list of Monitor objects
    """
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


class Monitors:
    """
    A class to represent all the monitors(adapters to be exact) that are detectable by windows.
    """

    def __init__(self):
        self.monitors = get_monitors()

    def __getitem__(self, item) -> Monitor:
        return self.monitors[item]

    def __len__(self):
        return len(self.monitors)

    def get_monitor_from_key(self, DeviceKey: str) -> Monitor:
        """
        find the monitor with the provided DeviceKey
        :param DeviceKey:
        :return: the first monitor with the provided DeviceKey
        """
        for monitor in self.monitors:
            if monitor.get_device_key() == DeviceKey:
                return monitor
        raise LookupError("%s Monitor does not exist" % DeviceKey)

    def get_monitor_from_id(self, DeviceID: str) -> Monitor:
        """
        find the monitor with the provided DeviceID
        :param DeviceID:
        :return: the first monitor with the provided DeviceID
        """
        for monitor in self.monitors:
            if monitor.get_device_id() == DeviceID:
                return monitor
        raise LookupError("%s Monitor does not exist" % DeviceID)


def save_monitor_in_json(monitor: Monitor, filepath: str):
    dict_monitor: dict = {
        "adapter": {
            "DeviceID": monitor.adapter.DeviceID,
            "DeviceKey": monitor.adapter.DeviceKey,
            "DeviceName": monitor.adapter.DeviceName,
            "DeviceString": monitor.adapter.DeviceString,
            "Size": str(monitor.adapter.Size),
            "StateFlags": str(monitor.adapter.StateFlags)
        },
        "device": {
            "DeviceID": monitor.device.DeviceID,
            "DeviceKey": monitor.device.DeviceKey,
            "DeviceName": monitor.device.DeviceName,
            "DeviceString": monitor.device.DeviceString,
            "Size": str(monitor.device.Size),
            "StateFlags": str(monitor.device.StateFlags)
        },
        "config": {
            "BitsPerPel": monitor.config.BitsPerPel,
            "Collate": monitor.config.Collate,
            "Color": monitor.config.Color,
            "Copies": monitor.config.Copies,
            "DefaultSource": monitor.config.DefaultSource,
            "DeviceName": monitor.config.DeviceName,
            "DisplayFixedOutput": monitor.config.DisplayFixedOutput,
            "DisplayFlags": monitor.config.DisplayFlags,
            "DisplayFrequency": monitor.config.DisplayFrequency,
            "DisplayOrientation": monitor.config.DisplayOrientation,
            "DitherType": monitor.config.DitherType,
            "DriverData": monitor.config.DriverData,
            "DriverExtra": monitor.config.DriverExtra,
            "DriverVersion": monitor.config.DriverVersion,
            "Duplex": monitor.config.Duplex,
            "Fields": monitor.config.Fields,
            "FormName": monitor.config.FormName,
            "ICMIntent": monitor.config.ICMIntent,
            "ICMMethod": monitor.config.ICMMethod,
            "LogPixels": monitor.config.LogPixels,
            "MediaType": monitor.config.MediaType,
            "Nup": monitor.config.Nup,
            "Orientation": monitor.config.Orientation,
            "PanningHeight": monitor.config.PanningHeight,
            "PanningWidth": monitor.config.PanningWidth,
            "PaperLength": monitor.config.PaperLength,
            "PaperSize": monitor.config.PaperSize,
            "PaperWidth": monitor.config.PaperWidth,
            "PelsHeight": monitor.config.PelsHeight,
            "PelsWidth": monitor.config.PelsWidth,
            "Position_x": monitor.config.Position_x,
            "Position_y": monitor.config.Position_y,
            "PrintQuality": monitor.config.PrintQuality,
            "Reserved1": monitor.config.Reserved1,
            "Reserved2": monitor.config.Reserved2,
            "Scale": monitor.config.Scale,
            "Size": monitor.config.Size,
            "SpecVersion": monitor.config.SpecVersion,
            "TTOption": monitor.config.TTOption,
            "YResolution": monitor.config.YResolution
        }
    }
    with open(filepath, 'w') as file:
        json.dump(dict_monitor, file, sort_keys=True, indent=4)


def main():
    """
    it's just for testing purposes
    """
    monitors = Monitors()
    for monitor in monitors:
        print(monitor.get_device_id())
        save_monitor_in_json(monitor, "a.json")


if __name__ == "__main__":
    main()
