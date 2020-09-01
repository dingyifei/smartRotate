import unittest
import rotate_win


class Rotate(unittest.TestCase):
    def test_monitors_len(self):
        a = rotate_win.Monitors()
        self.assertEqual(len(a), 2)

    def test_monitors_init(self):
        a = rotate_win.Monitors()
        monitor1 = "\Registry\Machine\System\CurrentControlSet\Control\Video\{43FB2533-47B3-11EA-A2C7-309C230C9A9D}\\0000"
        monitor2 = "\Registry\Machine\System\CurrentControlSet\Control\Video\{43FB2533-47B3-11EA-A2C7-309C230C9A9D}\\0001"
        self.assertEqual(a[0].get_device_key(), monitor1)
        self.assertEqual(a[1].get_device_key(), monitor2)

    def test_monitors_get_monitor_from_key(self):
        a = rotate_win.Monitors()
        monitor1 = "\Registry\Machine\System\CurrentControlSet\Control\Video\{43FB2533-47B3-11EA-A2C7-309C230C9A9D}\\0000"
        monitor2 = "\Registry\Machine\System\CurrentControlSet\Control\Video\{43FB2533-47B3-11EA-A2C7-309C230C9A9D}\\0001"
        self.assertEqual(a.get_monitor_from_key(monitor1).get_device_key(), monitor1)
        self.assertEqual(a.get_monitor_from_key(monitor2).get_device_key(), monitor2)
        with self.assertRaises(LookupError):
            a.get_monitor_from_key("")

    def test_monitors_get_monitor_from_id(self):
        a = rotate_win.Monitors()
        monitor1 = "MONITOR\DELA0E7\{4d36e96e-e325-11ce-bfc1-08002be10318}\\0011"
        monitor2 = "MONITOR\DEL40E0\{4d36e96e-e325-11ce-bfc1-08002be10318}\\0010"
        self.assertEqual(a.get_monitor_from_id(monitor1).get_device_id(), monitor1)
        self.assertEqual(a.get_monitor_from_id(monitor2).get_device_id(), monitor2)
        with self.assertRaises(LookupError):
            a.get_monitor_from_id("")


if __name__ == '__main__':
    unittest.main()
