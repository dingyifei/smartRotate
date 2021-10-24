from pywinusb import hid

filter_hid = hid.HidDeviceFilter(vendor_id=0x2234, product_id=0x0006)



def on_data(data):
    print(f"Got message {data}")

all_hid_devices = hid.find_all_hid_devices()
mbed_devices = [d for d in all_hid_devices if "mbed" in d.vendor_name]

if mbed_devices is None:
    raise ValueError("No HID devices found")

# A buffer of bytes representing the values 1-8
# The first byte is the report ID which must be 0
buffer = [0,1,2,3,4,5,6,7,8]

mbed_devices[0].open()
# Set custom raw data handler
mbed_devices[0].set_raw_data_handler(on_data)

# Send the message to the Mbed board
out_report = mbed_devices[0].find_output_reports()
out_report[0].set_raw_data(buffer)
out_report[0].send()


class Acceleronmeter:
    def __init__(self):
        print("helloworld")
