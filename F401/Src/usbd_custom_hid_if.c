/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
  //My current plan is to emulate a HID Monitor device.
  0x50, 0x80,       // USAGE_PAGE (Monitor)
  0x09, 0x01,       // USAGE (Monitor Control)
  0xA1, 0x01,       // COLLECTION (Application)
  0x85, 0x01,       // REPORT_ID (1)
  0x15, 0x00,       // LOGICAL_MINIMUM (0)
  0x26, 0xFF, 0x00, // LOGICAL_MAXIMUM (255)
  0x75, 0x08,       // REPORT_SIZE (8)
  0x95, 0x80,       // REPORT_COUNT (128)
  0x09, 0x02,       // USAGE (EDID Information)
  0xB2, 0x02, 0x01, // FEATURE (Data,Var,Abs,Buf)
  0x85, 0x02,       // REPORT_ID (2)
  0x95, 0xF3,       // REPORT_COUNT (243)
  0x09, 0x03,       // USAGE (VDIF Information)
  0xB2, 0x02, 0x01, // FEATURE (Data,Var,Abs,Buf)
  0x85, 0x03,       // REPORT_ID (3)
  0x05, 0x82,       // USAGE_PAGE (VESA Virtual Controls)
  0x95, 0x01,       // REPORT_COUNT (1)
  0x75, 0x10,       // REPORT_SIZE (16)
  0x26, 0xC8, 0x00, // LOGICAL_MAXIMUM (200)
  0x09, 0x10,       // USAGE (Bright)
  0xB1, 0x02,       // FEATURE (Data,Var,Abs)
  0x85, 0x04,       // REPORT_ID (4)
  0x25, 0x64,       // LOGICAL_MAXIMUM (100)
  0x09, 0x12,       // USAGE (Contrast)
  0xB1, 0x02,       // FEATURE (Data,Var,Abs
  0x95, 0x06,       // REPORT_COUNT (6)
  0x26, 0xFF, 0x00, // LOGICAL_MAXIMUM (255)
  0x09, 0x16,       // USAGE (Video Gain Red)
  0x09, 0x18,       // USAGE (Video Gain Green)
  0x09, 0x1A,       // USAGE (Video Gain Blue)
  0x09, 0x6C,       // USAGE (Video Black Level Red)
  0x09, 0x6E,       // USAGE (Video Black Level Green)
  0x09, 0x70,       // USAGE (Video Black Level Blue)
  0xB1, 0x02,       // FEATURE (Data,Var,Abs)
  0x85, 0x05,       // REPORT_ID (5)
  0x25, 0x7F,       // LOGICAL_MAXIMUM (127)
  0x09, 0x20,       // USAGE (Horizontal Position)
  0x09, 0x22,       // USAGE (Horizontal Size)
  0x09, 0x30,       // USAGE (Vertical Position)
  0x09, 0x32,       // USAGE (Vertical Size)
  0x09, 0x42,       // USAGE (Trapezoidal Distortion)
  0x09, 0x44,       // USAGE (Tilt)
  0xB1, 0x02,       // FEATURE (Data,Var,Abs)
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
  UNUSED(event_idx);
  UNUSED(state);

  /* Start next USB packet transfer once data processing is completed */
  USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS);

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

