import unittest
import rotate_win


class Rotate(unittest.TestCase):
    def test_monitors_len(self):
        a = rotate_win.Monitors()
        self.assertEqual(len(a), 2)

    def test_monitors_init(self):
        a = rotate_win.Monitors()
        monitor1 = "MONITOR\DELA0E7\{4d36e96e-e325-11ce-bfc1-08002be10318}\\0011"
        monitor2 = "MONITOR\DEL40E0\{4d36e96e-e325-11ce-bfc1-08002be10318}\\0010"
        self.assertEqual(a[0].get_device_id(), monitor1)
        self.assertEqual(a[1].get_device_id(), monitor2)

    def test_monitors_get_monitor_from_id(self):
        a = rotate_win.Monitors()
        monitor1 = "MONITOR\DELA0E7\{4d36e96e-e325-11ce-bfc1-08002be10318}\\0011"
        monitor2 = "MONITOR\DEL40E0\{4d36e96e-e325-11ce-bfc1-08002be10318}\\0010"
        self.assertEqual(a.get_monitor_from_id(monitor1).get_device_id(), monitor1)
        self.assertEqual(a.get_monitor_from_id(monitor2).get_device_id(), monitor2)
        with self.assertRaises(LookupError):
            a.get_monitor_from_id("")

    def test_monitor_json(self):
        return 0
        #TODO: write test for this thing


if __name__ == '__main__':
    unittest.main()
