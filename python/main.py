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
from tkinter import *
import rotate_win


def cmd_ccw():
    return 0


def cmd_cw():
    return 0


def cmd_rst():
    return 0


def cmd_bind():
    return 0


def main():
    """
    This is the GUI for rotating display, etc
    """
    main_window = Tk()
    main_window.title("Smart Rotate")
    main_frame = Frame(main_window)
    main_frame.grid(sticky=(N, W, E, S))
    # main_window.columnconfigure()
    # main_window.rowconfigure()
    x_rotation = IntVar()
    y_rotation = IntVar()
    z_rotation = IntVar()
    orientation = StringVar()

    label_x_rotation = Label(main_frame, text="X Rotation:")
    label_x_rotation.grid(column=0, row=0, sticky=W)
    label_y_rotation = Label(main_frame, text="Y Rotation:")
    label_y_rotation.grid(column=0, row=1, sticky=W)
    label_z_rotation = Label(main_frame, text="Z Rotation:")
    label_z_rotation.grid(column=0, row=2, sticky=W)
    label_orientation = Label(main_frame, text="Orientation:")
    label_orientation.grid(column=0, row=3, sticky=W)
    menubutton_display = Listbox(main_frame)
    menubutton_display.grid(column=0, row=4, sticky=W, columnspan=2)

    label_x_reading = Label(main_frame, textvariable=x_rotation)
    label_x_reading.grid(column=1, row=0, sticky=W)
    label_y_reading = Label(main_frame, textvariable=y_rotation)
    label_y_reading.grid(column=1, row=1, sticky=W)
    label_z_reading = Label(main_frame, textvariable=z_rotation)
    label_z_reading.grid(column=1, row=2, sticky=W)
    label_orientation = Label(main_frame, textvariable=orientation)
    label_orientation.grid(column=1, row=3, sticky=W)

    btn_ccw = Button(main_frame, text="CCW Turn", command=cmd_ccw)
    btn_ccw.grid(column=2, row=0, sticky=EW, ipadx=5)
    btn_cw = Button(main_frame, text="CW Turn", command=cmd_cw)
    btn_cw.grid(column=2, row=1, sticky=EW, ipadx=5)
    btn_rst = Button(main_frame, text="Reset", command=cmd_rst)
    btn_rst.grid(column=2, row=2, sticky=EW, ipadx=5)
    btn_bind = Button(main_frame, text="Bind", command=cmd_bind)
    btn_bind.grid(column=2, row=3, sticky=EW, ipadx=5)

    main_window.mainloop()


if __name__ == "__main__":
    main()
