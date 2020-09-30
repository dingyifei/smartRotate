EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3350 4000 550  450 
U 5EF5359A
F0 "MCU" 50
F1 "MCU.sch" 50
F2 "SDA" I R 3900 4150 50 
F3 "SCL" I R 3900 4300 50 
$EndSheet
$Comp
L Device:C_Small C?
U 1 1 5ED17446
P 6900 4250
AR Path="/5EF84708/5ED17446" Ref="C?"  Part="1" 
AR Path="/5ED17446" Ref="C14"  Part="1" 
F 0 "C14" H 6992 4296 50  0000 L CNN
F 1 "100nF" H 6992 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6900 4250 50  0001 C CNN
F 3 "~" H 6900 4250 50  0001 C CNN
F 4 "C80516" H 6900 4250 50  0001 C CNN "LCSC"
F 5 "0603B104K160CT" H 6900 4250 50  0001 C CNN "Part Number"
	1    6900 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5ED1744C
P 7300 4250
AR Path="/5EF84708/5ED1744C" Ref="C?"  Part="1" 
AR Path="/5ED1744C" Ref="C15"  Part="1" 
F 0 "C15" H 7392 4296 50  0000 L CNN
F 1 "100nF" H 7392 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7300 4250 50  0001 C CNN
F 3 "~" H 7300 4250 50  0001 C CNN
F 4 "C80516" H 7300 4250 50  0001 C CNN "LCSC"
F 5 "0603B104K160CT" H 7300 4250 50  0001 C CNN "Part Number"
	1    7300 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5ED2AB9E
P 6150 4700
AR Path="/5EB4B275/5ED2AB9E" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED2AB9E" Ref="#PWR?"  Part="1" 
AR Path="/5ED2AB9E" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 6150 4550 50  0001 C CNN
F 1 "+3.3V" V 6165 4828 50  0000 L CNN
F 2 "" H 6150 4700 50  0001 C CNN
F 3 "" H 6150 4700 50  0001 C CNN
	1    6150 4700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5ED309CF
P 6150 3700
AR Path="/5EB4B275/5ED309CF" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED309CF" Ref="#PWR?"  Part="1" 
AR Path="/5ED309CF" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 6150 3450 50  0001 C CNN
F 1 "GND" H 6155 3527 50  0000 C CNN
F 2 "" H 6150 3700 50  0001 C CNN
F 3 "" H 6150 3700 50  0001 C CNN
	1    6150 3700
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5ED36806
P 6150 4300
AR Path="/5EB4B275/5ED36806" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED36806" Ref="#PWR?"  Part="1" 
AR Path="/5ED36806" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 6150 4150 50  0001 C CNN
F 1 "+3.3V" V 6165 4428 50  0000 L CNN
F 2 "" H 6150 4300 50  0001 C CNN
F 3 "" H 6150 4300 50  0001 C CNN
	1    6150 4300
	0    1    1    0   
$EndComp
NoConn ~ 5250 4200
NoConn ~ 5250 4100
$Comp
L smartRotate:BMA253 U4
U 1 1 5ECF17B8
P 5700 4200
F 0 "U4" H 5700 4881 50  0000 C CNN
F 1 "BMA253" H 5700 4790 50  0000 C CNN
F 2 "Package_LGA:LGA-12_2x2mm_P0.5mm" H 5650 3650 50  0001 C CNN
F 3 "https://www.bosch-sensortec.com/products/motion-sensors/accelerometers/bma253.html" H 6100 4250 50  0001 C CNN
F 4 "C165275" H 5700 4200 50  0001 C CNN "LCSC"
F 5 "BMA253" H 5700 4200 50  0001 C CNN "Part Number"
	1    5700 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 3700 5650 3700
Connection ~ 5750 3700
Wire Wire Line
	5650 4700 5750 4700
Connection ~ 5750 4700
$Comp
L power:GND #PWR?
U 1 1 5ECF6B27
P 6150 4100
AR Path="/5EB4B275/5ECF6B27" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ECF6B27" Ref="#PWR?"  Part="1" 
AR Path="/5ECF6B27" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 6150 3850 50  0001 C CNN
F 1 "GND" H 6155 3927 50  0000 C CNN
F 2 "" H 6150 4100 50  0001 C CNN
F 3 "" H 6150 4100 50  0001 C CNN
	1    6150 4100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 3700 6150 3700
Wire Wire Line
	5750 4700 6150 4700
$Comp
L power:GND #PWR?
U 1 1 5ECF7866
P 5250 4400
AR Path="/5EB4B275/5ECF7866" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ECF7866" Ref="#PWR?"  Part="1" 
AR Path="/5ECF7866" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 5250 4150 50  0001 C CNN
F 1 "GND" H 5255 4227 50  0000 C CNN
F 2 "" H 5250 4400 50  0001 C CNN
F 3 "" H 5250 4400 50  0001 C CNN
	1    5250 4400
	0    1    1    0   
$EndComp
NoConn ~ 6150 4200
Text Label 5250 4300 2    50   ~ 0
SDA
Text Label 6150 4400 0    50   ~ 0
SCL
Text Label 4500 4150 0    50   ~ 0
SDA
Text Label 4500 4300 0    50   ~ 0
SCL
$Comp
L Device:R_Small R11
U 1 1 5ED8AEE3
P 4400 3850
F 0 "R11" H 4459 3896 50  0000 L CNN
F 1 "1.5k" H 4459 3805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4400 3850 50  0001 C CNN
F 3 "~" H 4400 3850 50  0001 C CNN
	1    4400 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 4300 4000 4300
Wire Wire Line
	4500 4150 4400 4150
Connection ~ 4000 4300
Wire Wire Line
	4000 4300 4500 4300
Wire Wire Line
	4400 4150 4400 3950
Connection ~ 4400 4150
Wire Wire Line
	4400 4150 3900 4150
$Comp
L power:+3.3V #PWR?
U 1 1 5ED8CE80
P 4400 3750
AR Path="/5EB4B275/5ED8CE80" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED8CE80" Ref="#PWR?"  Part="1" 
AR Path="/5ED8CE80" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 4400 3600 50  0001 C CNN
F 1 "+3.3V" V 4415 3878 50  0000 L CNN
F 2 "" H 4400 3750 50  0001 C CNN
F 3 "" H 4400 3750 50  0001 C CNN
	1    4400 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5ED8C8EC
P 4000 3750
AR Path="/5EB4B275/5ED8C8EC" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED8C8EC" Ref="#PWR?"  Part="1" 
AR Path="/5ED8C8EC" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 4000 3600 50  0001 C CNN
F 1 "+3.3V" V 4015 3878 50  0000 L CNN
F 2 "" H 4000 3750 50  0001 C CNN
F 3 "" H 4000 3750 50  0001 C CNN
	1    4000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3950 4000 4300
$Comp
L Device:R_Small R10
U 1 1 5ED88F10
P 4000 3850
F 0 "R10" H 4059 3896 50  0000 L CNN
F 1 "1.5k" H 4059 3805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4000 3850 50  0001 C CNN
F 3 "~" H 4000 3850 50  0001 C CNN
	1    4000 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5ED95DAC
P 6900 3950
AR Path="/5EB4B275/5ED95DAC" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED95DAC" Ref="#PWR?"  Part="1" 
AR Path="/5ED95DAC" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 6900 3800 50  0001 C CNN
F 1 "+3.3V" V 6915 4078 50  0000 L CNN
F 2 "" H 6900 3950 50  0001 C CNN
F 3 "" H 6900 3950 50  0001 C CNN
	1    6900 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5ED9647B
P 6900 4550
AR Path="/5EB4B275/5ED9647B" Ref="#PWR?"  Part="1" 
AR Path="/5EF5359A/5ED9647B" Ref="#PWR?"  Part="1" 
AR Path="/5ED9647B" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 6900 4300 50  0001 C CNN
F 1 "GND" H 6905 4377 50  0000 C CNN
F 2 "" H 6900 4550 50  0001 C CNN
F 3 "" H 6900 4550 50  0001 C CNN
	1    6900 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3950 6900 4150
Wire Wire Line
	6900 4150 7300 4150
Connection ~ 6900 4150
Wire Wire Line
	7300 4350 6900 4350
Wire Wire Line
	6900 4350 6900 4550
Connection ~ 6900 4350
$Comp
L Sensor_Motion:MPU-6050 U?
U 1 1 5F74ECF6
P 3750 2200
F 0 "U?" H 3750 1411 50  0000 C CNN
F 1 "MPU-6050" H 3750 1320 50  0000 C CNN
F 2 "Sensor_Motion:InvenSense_QFN-24_4x4mm_P0.5mm" H 3750 1400 50  0001 C CNN
F 3 "https://store.invensense.com/datasheets/invensense/MPU-6050_DataSheet_V3%204.pdf" H 3750 2050 50  0001 C CNN
	1    3750 2200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
