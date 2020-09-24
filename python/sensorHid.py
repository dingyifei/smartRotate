from pywinusb import hid

filter_hid = hid.HidDeviceFilter(vendor_id=0x2234, product_id=0x0006)


class Acceleronmeter:
    def __init__(self):
        print("helloworld")
