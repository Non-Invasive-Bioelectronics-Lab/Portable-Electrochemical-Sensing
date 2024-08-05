#define CONFIG_GPIO 1
#define CONFIG_SPI 1
#define CONFIG_NET_CONFIG_IEEE802154_DEV_NAME ""
#define CONFIG_GPIO_INIT_PRIORITY 40
#define CONFIG_SENSOR 1
#define CONFIG_BT_HCI_VS_EXT 1
#define CONFIG_BOARD "bl654_dvk"
#define CONFIG_BT_CTLR 1
#define CONFIG_SOC "nRF52840_QIAA"
#define CONFIG_SOC_SERIES "nrf52"
#define CONFIG_NUM_IRQS 48
#define CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC 32768
#define CONFIG_CLOCK_CONTROL_INIT_PRIORITY 30
#define CONFIG_FLASH_SIZE 1024
#define CONFIG_FLASH_BASE_ADDRESS 0x0
#define CONFIG_HEAP_MEM_POOL_SIZE 0
#define CONFIG_ROM_START_OFFSET 0x0
#define CONFIG_PINCTRL 1
#define CONFIG_SOC_HAS_TIMING_FUNCTIONS 1
#define CONFIG_ARCH_HAS_CUSTOM_BUSY_WAIT 1
#define CONFIG_PM 1
#define CONFIG_CLOCK_CONTROL 1
#define CONFIG_NRF_RTC_TIMER 1
#define CONFIG_SYS_CLOCK_TICKS_PER_SEC 32768
#define CONFIG_BUILD_OUTPUT_HEX 1
#define CONFIG_SERIAL_INIT_PRIORITY 55
#define CONFIG_TINYCRYPT 1
#define CONFIG_SERIAL 1
#define CONFIG_MP_NUM_CPUS 1
#define CONFIG_PLATFORM_SPECIFIC_INIT 1
#define CONFIG_NUM_METAIRQ_PRIORITIES 0
#define CONFIG_SYSTEM_WORKQUEUE_STACK_SIZE 2048
#define CONFIG_MAIN_STACK_SIZE 2048
#define CONFIG_LOG_BUFFER_SIZE 1024
#define CONFIG_WARN_EXPERIMENTAL 1
#define CONFIG_PRIVILEGED_STACK_SIZE 1024
#define CONFIG_BT_BUF_CMD_TX_COUNT 2
#define CONFIG_ENTROPY_GENERATOR 1
#define CONFIG_INIT_ARCH_HW_AT_BOOT 1
#define CONFIG_NORDIC_QSPI_NOR_FLASH_LAYOUT_PAGE_SIZE 4096
#define CONFIG_LOG_DEFAULT_LEVEL 3
#define CONFIG_PM_PARTITION_SIZE_PROVISION 0x1000
#define CONFIG_PM_PARTITION_SIZE_B0_IMAGE 0x8000
#define CONFIG_SB_VALIDATION_INFO_MAGIC 0x86518483
#define CONFIG_SB_VALIDATION_POINTER_MAGIC 0x6919b47e
#define CONFIG_SB_VALIDATION_INFO_CRYPTO_ID 1
#define CONFIG_SB_VALIDATION_INFO_VERSION 2
#define CONFIG_SB_VALIDATION_METADATA_OFFSET 0
#define CONFIG_SB_VALIDATE_FW_SIGNATURE 1
#define CONFIG_BT_MAX_CONN 1
#define CONFIG_BT_LL_SOFTDEVICE 1
#define CONFIG_BT_LL_SOFTDEVICE_BUILD_TYPE_LIB 1
#define CONFIG_BT_HCI_TX_STACK_SIZE 1536
#define CONFIG_BT_RX_STACK_SIZE 2200
#define CONFIG_BT_CTLR_SDC_PERIPHERAL_COUNT 1
#define CONFIG_BT_CTLR_SDC_MAX_CONN_EVENT_LEN_DEFAULT 7500
#define CONFIG_BT_CTLR_SDC_TX_PACKET_COUNT 3
#define CONFIG_BT_CTLR_SDC_RX_PACKET_COUNT 2
#define CONFIG_BT_CTLR_SDC_SCAN_BUFFER_COUNT 3
#define CONFIG_BT_CTLR_SDC_PERIODIC_SYNC_BUFFER_COUNT 2
#define CONFIG_BT_CTLR_SDC_RX_PRIO 6
#define CONFIG_BT_CTLR_SDC_RX_STACK_SIZE 1024
#define CONFIG_BT_LL_SOFTDEVICE_PERIPHERAL 1
#define CONFIG_BT_CTLR_ECDH_LIB_OBERON 1
#define CONFIG_BT_CTLR_ECDH_STACK_SIZE 900
#define CONFIG_BT_RPA_TIMEOUT 900
#define CONFIG_BT_DIS 1
#define CONFIG_BT_L2CAP_TX_MTU 65
#define CONFIG_BT_BUF_ACL_TX_SIZE 27
#define CONFIG_BT_BUF_ACL_RX_SIZE 69
#define CONFIG_BT_CTLR_DATA_LENGTH_MAX 27
#define CONFIG_BT_PERIPHERAL 1
#define CONFIG_BT_BROADCASTER 1
#define CONFIG_BT_CONN 1
#define CONFIG_BT_PHY_UPDATE 1
#define CONFIG_BT_DATA_LEN_UPDATE 1
#define CONFIG_BT_DIS_MODEL "nRF52840_QIAA"
#define CONFIG_BT_DIS_MANUF "Manufacturer"
#define CONFIG_BT_DIS_PNP 1
#define CONFIG_BT_DIS_PNP_VID_SRC 1
#define CONFIG_BT_DIS_PNP_VID 0x0
#define CONFIG_BT_DIS_PNP_PID 0x0
#define CONFIG_BT_DIS_PNP_VER 0x1
#define CONFIG_BT_BAS 1
#define CONFIG_BT_BAS_LOG_LEVEL_INF 1
#define CONFIG_BT_BAS_LOG_LEVEL 3
#define CONFIG_BT_HRS 1
#define CONFIG_BT_HRS_DEFAULT_PERM_RW 1
#define CONFIG_BT_HRS_LOG_LEVEL_INF 1
#define CONFIG_BT_HRS_LOG_LEVEL 3
#define CONFIG_BT_IAS 1
#define CONFIG_BT_IAS_SEC_NONE 1
#define CONFIG_BT_IAS_LOG_LEVEL_INF 1
#define CONFIG_BT_IAS_LOG_LEVEL 3
#define CONFIG_BT_BUF_ACL_TX_COUNT 3
#define CONFIG_BT_BUF_ACL_RX_COUNT 6
#define CONFIG_BT_BUF_EVT_RX_SIZE 68
#define CONFIG_BT_BUF_EVT_RX_COUNT 10
#define CONFIG_BT_BUF_EVT_DISCARDABLE_SIZE 43
#define CONFIG_BT_BUF_EVT_DISCARDABLE_COUNT 3
#define CONFIG_BT_BUF_CMD_TX_SIZE 65
#define CONFIG_BT_HAS_HCI_VS 1
#define CONFIG_BT_HCI_VS 1
#define CONFIG_BT_RPA 1
#define CONFIG_BT_ASSERT 1
#define CONFIG_BT_ASSERT_VERBOSE 1
#define CONFIG_BT_DEBUG 1
#define CONFIG_BT_DEBUG_LOG 1
#define CONFIG_BT_LONG_WQ 1
#define CONFIG_BT_LONG_WQ_STACK_SIZE 1300
#define CONFIG_BT_LONG_WQ_PRIO 10
#define CONFIG_BT_HCI_HOST 1
#define CONFIG_BT_HCI_TX_PRIO 7
#define CONFIG_BT_HCI_RESERVE 0
#define CONFIG_BT_RECV_WORKQ_BT 1
#define CONFIG_BT_RX_PRIO 8
#define CONFIG_BT_DRIVER_RX_HIGH_PRIO 6
#define CONFIG_BT_SETTINGS 1
#define CONFIG_BT_SETTINGS_CCC_LAZY_LOADING 1
#define CONFIG_BT_SETTINGS_CCC_STORE_ON_WRITE 1
#define CONFIG_BT_SETTINGS_USE_PRINTK 1
#define CONFIG_BT_LIM_ADV_TIMEOUT 30
#define CONFIG_BT_CONN_TX_MAX 3
#define CONFIG_BT_AUTO_PHY_UPDATE 1
#define CONFIG_BT_AUTO_DATA_LEN_UPDATE 1
#define CONFIG_BT_SMP 1
#define CONFIG_BT_PRIVACY 1
#define CONFIG_BT_SIGNING 1
#define CONFIG_BT_BONDABLE 1
#define CONFIG_BT_SMP_ENFORCE_MITM 1
#define CONFIG_BT_KEYS_OVERWRITE_OLDEST 1
#define CONFIG_BT_SMP_MIN_ENC_KEY_SIZE 7
#define CONFIG_BT_L2CAP_TX_BUF_COUNT 3
#define CONFIG_BT_L2CAP_TX_FRAG_COUNT 2
#define CONFIG_BT_ATT_ENFORCE_FLOW 1
#define CONFIG_BT_ATT_PREPARE_COUNT 5
#define CONFIG_BT_ATT_RETRY_ON_SEC_ERR 1
#define CONFIG_BT_GATT_AUTO_SEC_REQ 1
#define CONFIG_BT_GATT_SERVICE_CHANGED 1
#define CONFIG_BT_GATT_CACHING 1
#define CONFIG_BT_GATT_ENFORCE_SUBSCRIPTION 1
#define CONFIG_BT_GATT_READ_MULTIPLE 1
#define CONFIG_BT_GATT_READ_MULT_VAR_LEN 1
#define CONFIG_BT_GAP_AUTO_UPDATE_CONN_PARAMS 1
#define CONFIG_BT_GAP_PERIPHERAL_PREF_PARAMS 1
#define CONFIG_BT_PERIPHERAL_PREF_MIN_INT 24
#define CONFIG_BT_PERIPHERAL_PREF_MAX_INT 40
#define CONFIG_BT_PERIPHERAL_PREF_LATENCY 0
#define CONFIG_BT_PERIPHERAL_PREF_TIMEOUT 42
#define CONFIG_BT_DEVICE_NAME_GATT_WRITABLE 1
#define CONFIG_DEVICE_NAME_GATT_WRITABLE_ENCRYPT 1
#define CONFIG_BT_MAX_PAIRED 1
#define CONFIG_BT_CREATE_CONN_TIMEOUT 3
#define CONFIG_BT_CONN_PARAM_UPDATE_TIMEOUT 5000
#define CONFIG_BT_DEVICE_NAME_DYNAMIC 1
#define CONFIG_BT_DEVICE_NAME_MAX 65
#define CONFIG_BT_DEVICE_NAME "Zephyr Peripheral Sample Long Name"
#define CONFIG_BT_DEVICE_APPEARANCE 833
#define CONFIG_BT_ID_MAX 1
#define CONFIG_BT_ECC 1
#define CONFIG_NRF_CLOUD_CLIENT_ID_SRC_COMPILE_TIME 1
#define CONFIG_NRF_CLOUD_CLIENT_ID "my-client-id"
#define CONFIG_NRF_CLOUD_LOG_LEVEL_INF 1
#define CONFIG_NRF_CLOUD_LOG_LEVEL 3
#define CONFIG_MPSL_FEM_LOG_LEVEL_INF 1
#define CONFIG_MPSL_FEM_LOG_LEVEL 3
#define CONFIG_MPSL_CX_LOG_LEVEL_INF 1
#define CONFIG_MPSL_CX_LOG_LEVEL 3
#define CONFIG_MPSL_THREAD_COOP_PRIO 6
#define CONFIG_MPSL_WORK_STACK_SIZE 1024
#define CONFIG_MPSL_TIMESLOT_SESSION_COUNT 0
#define CONFIG_MPSL_LOG_LEVEL_INF 1
#define CONFIG_MPSL_LOG_LEVEL 3
#define CONFIG_SRAM_SIZE 256
#define CONFIG_SRAM_BASE_ADDRESS 0x20000000
#define CONFIG_PM_PARTITION_SIZE_SETTINGS_STORAGE 0x2000
#define CONFIG_PM_EXTERNAL_FLASH_BASE 0x0
#define CONFIG_PM_SRAM_BASE 0x20000000
#define CONFIG_PM_SRAM_SIZE 0x40000
#define CONFIG_MGMT_FMFU_LOG_LEVEL_INF 1
#define CONFIG_MGMT_FMFU_LOG_LEVEL 3
#define CONFIG_NRF_ACL_FLASH_REGION_SIZE 0x1000
#define CONFIG_FPROTECT_BLOCK_SIZE 0x1000
#define CONFIG_MULTITHREADING_LOCK 1
#define CONFIG_RESET_ON_FATAL_ERROR 1
#define CONFIG_FATAL_ERROR_LOG_LEVEL_INF 1
#define CONFIG_FATAL_ERROR_LOG_LEVEL 3
#define CONFIG_HW_UNIQUE_KEY_PARTITION_SIZE 0x1000
#define CONFIG_ENTROPY_CC3XX 1
#define CONFIG_HW_CC3XX 1
#define CONFIG_NRFX_GPIOTE_NUM_OF_EVT_HANDLERS 1
#define CONFIG_CLOCK_CONTROL_MPSL 1
#define CONFIG_SOC_FLASH_NRF_RADIO_SYNC_MPSL 1
#define CONFIG_SOC_FLASH_NRF_RADIO_SYNC_MPSL_TIMESLOT_SESSION_COUNT 1
#define CONFIG_TEMP_NRF5_MPSL 1
#define CONFIG_ZTEST_MULTICORE_DEFAULT_SETTINGS 1
#define CONFIG_ZEPHYR_NRF_MODULE 1
#define CONFIG_ZEPHYR_HOSTAP_MODULE 1
#define CONFIG_BOOT_SIGNATURE_KEY_FILE ""
#define CONFIG_DT_FLASH_WRITE_BLOCK_SIZE 4
#define CONFIG_MCUBOOT_USB_SUPPORT 1
#define CONFIG_ZEPHYR_MCUBOOT_MODULE 1
#define CONFIG_ZEPHYR_MBEDTLS_MODULE 1
#define CONFIG_MBEDTLS_BUILTIN 1
#define CONFIG_ZEPHYR_TRUSTED_FIRMWARE_M_MODULE 1
#define CONFIG_ZEPHYR_CJSON_MODULE 1
#define CONFIG_ZEPHYR_AZURE_SDK_FOR_C_MODULE 1
#define CONFIG_ZEPHYR_MEMFAULT_FIRMWARE_SDK_MODULE 1
#define CONFIG_ZEPHYR_CIRRUS_LOGIC_MODULE 1
#define CONFIG_ZEPHYR_OPENTHREAD_MODULE 1
#define CONFIG_ZEPHYR_CANOPENNODE_MODULE 1
#define CONFIG_ZEPHYR_CHRE_MODULE 1
#define CONFIG_ZEPHYR_HAL_NORDIC_MODULE 1
#define CONFIG_HAS_NORDIC_DRIVERS 1
#define CONFIG_HAS_NRFX 1
#define CONFIG_NRFX_GPIOTE 1
#define CONFIG_NRFX_NVMC 1
#define CONFIG_NRFX_SPI 1
#define CONFIG_NRFX_SPI1 1
#define CONFIG_ZEPHYR_LIBLC3CODEC_MODULE 1
#define CONFIG_ZEPHYR_LITTLEFS_MODULE 1
#define CONFIG_ZEPHYR_LORAMAC_NODE_MODULE 1
#define CONFIG_ZEPHYR_LVGL_MODULE 1
#define CONFIG_ZEPHYR_LZ4_MODULE 1
#define CONFIG_ZEPHYR_NANOPB_MODULE 1
#define CONFIG_ZEPHYR_PICOLIBC_MODULE 1
#define CONFIG_ZEPHYR_TRACERECORDER_MODULE 1
#define CONFIG_ZEPHYR_ZCBOR_MODULE 1
#define CONFIG_ZEPHYR_ZSCILIB_MODULE 1
#define CONFIG_NRF_MODEM_SHMEM_CTRL_SIZE 0x4e8
#define CONFIG_MPSL 1
#define CONFIG_MPSL_BUILD_TYPE_LIB 1
#define CONFIG_NRFXLIB_CRYPTO 1
#define CONFIG_CRYPTOCELL_CC310_USABLE 1
#define CONFIG_CRYPTOCELL_USABLE 1
#define CONFIG_NRF_OBERON 1
#define CONFIG_NRF_CC3XX_PLATFORM 1
#define CONFIG_CC3XX_MUTEX_LOCK 1
#define CONFIG_NRF_802154_SOURCE_NRFXLIB 1
#define CONFIG_LC3_ENC_CHAN_MAX 1
#define CONFIG_LC3_DEC_CHAN_MAX 1
#define CONFIG_LC3_ENC_SAMPLE_RATE_8KHZ_SUPPORT 1
#define CONFIG_LC3_ENC_SAMPLE_RATE_16KHZ_SUPPORT 1
#define CONFIG_LC3_ENC_SAMPLE_RATE_24KHZ_SUPPORT 1
#define CONFIG_LC3_ENC_SAMPLE_RATE_32KHZ_SUPPORT 1
#define CONFIG_LC3_ENC_SAMPLE_RATE_441KHZ_SUPPORT 1
#define CONFIG_LC3_ENC_SAMPLE_RATE_48KHZ_SUPPORT 1
#define CONFIG_LC3_DEC_SAMPLE_RATE_8KHZ_SUPPORT 1
#define CONFIG_LC3_DEC_SAMPLE_RATE_16KHZ_SUPPORT 1
#define CONFIG_LC3_DEC_SAMPLE_RATE_24KHZ_SUPPORT 1
#define CONFIG_LC3_DEC_SAMPLE_RATE_32KHZ_SUPPORT 1
#define CONFIG_LC3_DEC_SAMPLE_RATE_441KHZ_SUPPORT 1
#define CONFIG_LC3_DEC_SAMPLE_RATE_48KHZ_SUPPORT 1
#define CONFIG_ZEPHYR_NRFXLIB_MODULE 1
#define CONFIG_ZEPHYR_CONNECTEDHOMEIP_MODULE 1
#define CONFIG_HAS_CMSIS_CORE 1
#define CONFIG_HAS_CMSIS_CORE_M 1
#define CONFIG_TINYCRYPT_AES 1
#define CONFIG_TINYCRYPT_AES_CMAC 1
#define CONFIG_BOARD_REVISION "$BOARD_REVISION"
#define CONFIG_BOARD_BL654_DVK 1
#define CONFIG_BOARD_ENABLE_DCDC 1
#define CONFIG_SOC_SERIES_NRF52X 1
#define CONFIG_CPU_HAS_ARM_MPU 1
#define CONFIG_HAS_SWO 1
#define CONFIG_SOC_FAMILY "nordic_nrf"
#define CONFIG_SOC_FAMILY_NRF 1
#define CONFIG_HAS_HW_NRF_ACL 1
#define CONFIG_HAS_HW_NRF_CC310 1
#define CONFIG_HAS_HW_NRF_CCM 1
#define CONFIG_HAS_HW_NRF_CCM_LFLEN_8BIT 1
#define CONFIG_HAS_HW_NRF_CLOCK 1
#define CONFIG_HAS_HW_NRF_ECB 1
#define CONFIG_HAS_HW_NRF_EGU0 1
#define CONFIG_HAS_HW_NRF_EGU1 1
#define CONFIG_HAS_HW_NRF_EGU2 1
#define CONFIG_HAS_HW_NRF_EGU3 1
#define CONFIG_HAS_HW_NRF_EGU4 1
#define CONFIG_HAS_HW_NRF_EGU5 1
#define CONFIG_HAS_HW_NRF_GPIO0 1
#define CONFIG_HAS_HW_NRF_GPIO1 1
#define CONFIG_HAS_HW_NRF_GPIOTE 1
#define CONFIG_HAS_HW_NRF_NVMC_PE 1
#define CONFIG_HAS_HW_NRF_POWER 1
#define CONFIG_HAS_HW_NRF_PPI 1
#define CONFIG_HAS_HW_NRF_PWM0 1
#define CONFIG_HAS_HW_NRF_RADIO_BLE_2M 1
#define CONFIG_HAS_HW_NRF_RADIO_BLE_CODED 1
#define CONFIG_HAS_HW_NRF_RADIO_IEEE802154 1
#define CONFIG_HAS_HW_NRF_RADIO_TX_PWR_HIGH 1
#define CONFIG_HAS_HW_NRF_RNG 1
#define CONFIG_HAS_HW_NRF_RTC0 1
#define CONFIG_HAS_HW_NRF_RTC1 1
#define CONFIG_HAS_HW_NRF_RTC2 1
#define CONFIG_HAS_HW_NRF_SAADC 1
#define CONFIG_HAS_HW_NRF_SPI1 1
#define CONFIG_HAS_HW_NRF_SWI0 1
#define CONFIG_HAS_HW_NRF_SWI1 1
#define CONFIG_HAS_HW_NRF_SWI2 1
#define CONFIG_HAS_HW_NRF_SWI3 1
#define CONFIG_HAS_HW_NRF_SWI4 1
#define CONFIG_HAS_HW_NRF_SWI5 1
#define CONFIG_HAS_HW_NRF_TEMP 1
#define CONFIG_HAS_HW_NRF_TIMER0 1
#define CONFIG_HAS_HW_NRF_TIMER1 1
#define CONFIG_HAS_HW_NRF_TIMER2 1
#define CONFIG_HAS_HW_NRF_TIMER3 1
#define CONFIG_HAS_HW_NRF_TIMER4 1
#define CONFIG_HAS_HW_NRF_UART0 1
#define CONFIG_HAS_HW_NRF_USBD 1
#define CONFIG_HAS_HW_NRF_WDT0 1
#define CONFIG_NRF_HW_RTC1_RESERVED 1
#define CONFIG_SOC_NRF52840 1
#define CONFIG_SOC_NRF52840_QIAA 1
#define CONFIG_SOC_DCDC_NRF52X 1
#define CONFIG_GPIO_AS_PINRESET 1
#define CONFIG_NRF_ENABLE_ICACHE 1
#define CONFIG_NRF_RTC_TIMER_USER_CHAN_COUNT 0
#define CONFIG_NRF_SOC_SECURE_SUPPORTED 1
#define CONFIG_NRF_APPROTECT_USE_UICR 1
#define CONFIG_SOC_LOG_LEVEL_INF 1
#define CONFIG_SOC_LOG_LEVEL 3
#define CONFIG_SOC_COMPATIBLE_NRF 1
#define CONFIG_SOC_COMPATIBLE_NRF52X 1
#define CONFIG_ARCH "arm"
#define CONFIG_CPU_CORTEX 1
#define CONFIG_CPU_CORTEX_M 1
#define CONFIG_ISA_THUMB2 1
#define CONFIG_ASSEMBLER_ISA_THUMB2 1
#define CONFIG_COMPILER_ISA_THUMB2 1
#define CONFIG_STACK_ALIGN_DOUBLE_WORD 1
#define CONFIG_FAULT_DUMP 2
#define CONFIG_FP16 1
#define CONFIG_FP16_IEEE 1
#define CONFIG_CPU_CORTEX_M4 1
#define CONFIG_CPU_CORTEX_M_HAS_SYSTICK 1
#define CONFIG_CPU_CORTEX_M_HAS_DWT 1
#define CONFIG_CPU_CORTEX_M_HAS_BASEPRI 1
#define CONFIG_CPU_CORTEX_M_HAS_VTOR 1
#define CONFIG_CPU_CORTEX_M_HAS_PROGRAMMABLE_FAULT_PRIOS 1
#define CONFIG_ARMV7_M_ARMV8_M_MAINLINE 1
#define CONFIG_ARMV7_M_ARMV8_M_FP 1
#define CONFIG_GEN_ISR_TABLES 1
#define CONFIG_ZERO_LATENCY_IRQS 1
#define CONFIG_ZERO_LATENCY_LEVELS 1
#define CONFIG_NULL_POINTER_EXCEPTION_DETECTION_NONE 1
#define CONFIG_GEN_IRQ_VECTOR_TABLE 1
#define CONFIG_ARM_MPU 1
#define CONFIG_ARM_MPU_REGION_MIN_ALIGN_AND_SIZE 32
#define CONFIG_MPU_ALLOW_FLASH_WRITE 1
#define CONFIG_CUSTOM_SECTION_MIN_ALIGN_SIZE 32
#define CONFIG_ARM 1
#define CONFIG_ARCH_IS_SET 1
#define CONFIG_ARCH_LOG_LEVEL_INF 1
#define CONFIG_ARCH_LOG_LEVEL 3
#define CONFIG_KOBJECT_TEXT_AREA 256
#define CONFIG_KOBJECT_DATA_AREA_RESERVE_EXTRA_PERCENT 100
#define CONFIG_KOBJECT_RODATA_AREA_EXTRA_BYTES 16
#define CONFIG_GEN_PRIV_STACKS 1
#define CONFIG_ARCH_IRQ_VECTOR_TABLE_ALIGN 4
#define CONFIG_IRQ_VECTOR_TABLE_JUMP_BY_ADDRESS 1
#define CONFIG_GEN_SW_ISR_TABLE 1
#define CONFIG_ARCH_SW_ISR_TABLE_ALIGN 4
#define CONFIG_GEN_IRQ_START_VECTOR 0
#define CONFIG_ARCH_HAS_SINGLE_THREAD_SUPPORT 1
#define CONFIG_ARCH_HAS_TIMING_FUNCTIONS 1
#define CONFIG_ARCH_HAS_STACK_PROTECTION 1
#define CONFIG_ARCH_HAS_USERSPACE 1
#define CONFIG_ARCH_HAS_EXECUTABLE_PAGE_BIT 1
#define CONFIG_ARCH_HAS_RAMFUNC_SUPPORT 1
#define CONFIG_ARCH_HAS_NESTED_EXCEPTION_DETECTION 1
#define CONFIG_ARCH_SUPPORTS_COREDUMP 1
#define CONFIG_ARCH_SUPPORTS_ARCH_HW_INIT 1
#define CONFIG_ARCH_HAS_EXTRA_EXCEPTION_INFO 1
#define CONFIG_ARCH_HAS_THREAD_LOCAL_STORAGE 1
#define CONFIG_ARCH_HAS_SUSPEND_TO_RAM 1
#define CONFIG_ARCH_HAS_THREAD_ABORT 1
#define CONFIG_CPU_HAS_FPU 1
#define CONFIG_CPU_HAS_MPU 1
#define CONFIG_MPU 1
#define CONFIG_MPU_LOG_LEVEL_INF 1
#define CONFIG_MPU_LOG_LEVEL 3
#define CONFIG_MPU_REQUIRES_POWER_OF_TWO_ALIGNMENT 1
#define CONFIG_SRAM_REGION_PERMISSIONS 1
#define CONFIG_DCACHE 1
#define CONFIG_TOOLCHAIN_HAS_BUILTIN_FFS 1
#define CONFIG_KERNEL_LOG_LEVEL_INF 1
#define CONFIG_KERNEL_LOG_LEVEL 3
#define CONFIG_MULTITHREADING 1
#define CONFIG_NUM_COOP_PRIORITIES 16
#define CONFIG_NUM_PREEMPT_PRIORITIES 15
#define CONFIG_MAIN_THREAD_PRIORITY 0
#define CONFIG_COOP_ENABLED 1
#define CONFIG_PREEMPT_ENABLED 1
#define CONFIG_PRIORITY_CEILING -127
#define CONFIG_IDLE_STACK_SIZE 320
#define CONFIG_ISR_STACK_SIZE 2048
#define CONFIG_THREAD_STACK_INFO 1
#define CONFIG_ERRNO 1
#define CONFIG_SCHED_DUMB 1
#define CONFIG_WAITQ_DUMB 1
#define CONFIG_BOOT_BANNER 1
#define CONFIG_BOOT_DELAY 0
#define CONFIG_SYSTEM_WORKQUEUE_PRIORITY -1
#define CONFIG_ATOMIC_OPERATIONS_BUILTIN 1
#define CONFIG_TIMESLICING 1
#define CONFIG_TIMESLICE_SIZE 0
#define CONFIG_TIMESLICE_PRIORITY 0
#define CONFIG_POLL 1
#define CONFIG_NUM_MBOX_ASYNC_MSGS 10
#define CONFIG_KERNEL_MEM_POOL 1
#define CONFIG_ARCH_HAS_CUSTOM_SWAP_TO_MAIN 1
#define CONFIG_SWAP_NONATOMIC 1
#define CONFIG_SYS_CLOCK_EXISTS 1
#define CONFIG_TIMEOUT_64BIT 1
#define CONFIG_SYS_CLOCK_MAX_TIMEOUT_DAYS 365
#define CONFIG_XIP 1
#define CONFIG_KERNEL_INIT_PRIORITY_OBJECTS 30
#define CONFIG_KERNEL_INIT_PRIORITY_DEFAULT 40
#define CONFIG_KERNEL_INIT_PRIORITY_DEVICE 50
#define CONFIG_APPLICATION_INIT_PRIORITY 90
#define CONFIG_STACK_POINTER_RANDOM 0
#define CONFIG_TICKLESS_KERNEL 1
#define CONFIG_TOOLCHAIN_SUPPORTS_THREAD_LOCAL_STORAGE 1
#define CONFIG_HAS_DTS 1
#define CONFIG_DT_HAS_ARM_ARMV7M_ITM_ENABLED 1
#define CONFIG_DT_HAS_ARM_CORTEX_M4F_ENABLED 1
#define CONFIG_DT_HAS_ARM_CRYPTOCELL_310_ENABLED 1
#define CONFIG_DT_HAS_ARM_V7M_NVIC_ENABLED 1
#define CONFIG_DT_HAS_FIXED_PARTITIONS_ENABLED 1
#define CONFIG_DT_HAS_GPIO_KEYS_ENABLED 1
#define CONFIG_DT_HAS_GPIO_LEDS_ENABLED 1
#define CONFIG_DT_HAS_MMIO_SRAM_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_ACL_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_CC310_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_CCM_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_CLOCK_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_ECB_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_EGU_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_FICR_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_GPIO_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_GPIOTE_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_MWU_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_PINCTRL_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_POWER_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_PPI_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_PWM_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_RADIO_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_RNG_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_RTC_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_SAADC_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_SPI_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_SWI_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_TEMP_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_TIMER_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_UART_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_UICR_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_USBD_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF_WDT_ENABLED 1
#define CONFIG_DT_HAS_NORDIC_NRF52_FLASH_CONTROLLER_ENABLED 1
#define CONFIG_DT_HAS_SOC_NV_FLASH_ENABLED 1
#define CONFIG_DT_HAS_ZEPHYR_BT_HCI_ENTROPY_ENABLED 1
#define CONFIG_CONSOLE 1
#define CONFIG_CONSOLE_INPUT_MAX_LINE_LEN 128
#define CONFIG_CONSOLE_HAS_DRIVER 1
#define CONFIG_CONSOLE_INIT_PRIORITY 60
#define CONFIG_UART_CONSOLE 1
#define CONFIG_UART_CONSOLE_INPUT_EXPIRED 1
#define CONFIG_UART_CONSOLE_INPUT_EXPIRED_TIMEOUT 15000
#define CONFIG_RTT_CONSOLE 1
#define CONFIG_RTT_TX_RETRY_CNT 2
#define CONFIG_RTT_TX_RETRY_DELAY_MS 2
#define CONFIG_UART_CONSOLE_LOG_LEVEL_INF 1
#define CONFIG_UART_CONSOLE_LOG_LEVEL 3
#define CONFIG_HAS_SEGGER_RTT 1
#define CONFIG_USE_SEGGER_RTT 1
#define CONFIG_SEGGER_RTT_CUSTOM_LOCKING 1
#define CONFIG_SEGGER_RTT_MAX_NUM_UP_BUFFERS 3
#define CONFIG_SEGGER_RTT_MAX_NUM_DOWN_BUFFERS 3
#define CONFIG_SEGGER_RTT_BUFFER_SIZE_UP 1024
#define CONFIG_SEGGER_RTT_BUFFER_SIZE_DOWN 16
#define CONFIG_SEGGER_RTT_PRINTF_BUFFER_SIZE 64
#define CONFIG_SEGGER_RTT_MODE_NO_BLOCK_SKIP 1
#define CONFIG_SEGGER_RTT_MODE 0
#define CONFIG_SEGGER_RTT_SECTION_NONE 1
#define CONFIG_SERIAL_HAS_DRIVER 1
#define CONFIG_SERIAL_SUPPORT_ASYNC 1
#define CONFIG_SERIAL_SUPPORT_INTERRUPT 1
#define CONFIG_UART_LOG_LEVEL_INF 1
#define CONFIG_UART_LOG_LEVEL 3
#define CONFIG_UART_USE_RUNTIME_CONFIGURE 1
#define CONFIG_UART_NRFX 1
#define CONFIG_UART_0_NRF_UART 1
#define CONFIG_NRF_UART_PERIPHERAL 1
#define CONFIG_INTC_INIT_PRIORITY 40
#define CONFIG_INTC_LOG_LEVEL_INF 1
#define CONFIG_INTC_LOG_LEVEL 3
#define CONFIG_SYSTEM_CLOCK_INIT_PRIORITY 0
#define CONFIG_TICKLESS_CAPABLE 1
#define CONFIG_NRF_RTC_TIMER_LOCK_ZERO_LATENCY_IRQS 1
#define CONFIG_SYSTEM_CLOCK_WAIT_FOR_STABILITY 1
#define CONFIG_RISCV_MACHINE_TIMER_SYSTEM_CLOCK_DIVIDER 0
#define CONFIG_RISCV_MACHINE_TIMER_MIN_DELAY 100
#define CONFIG_ENTROPY_LOG_LEVEL_INF 1
#define CONFIG_ENTROPY_LOG_LEVEL 3
#define CONFIG_ENTROPY_INIT_PRIORITY 50
#define CONFIG_ENTROPY_NRF5_RNG 1
#define CONFIG_ENTROPY_NRF5_THR_POOL_SIZE 8
#define CONFIG_ENTROPY_NRF5_THR_THRESHOLD 4
#define CONFIG_ENTROPY_NRF5_ISR_POOL_SIZE 16
#define CONFIG_ENTROPY_NRF5_ISR_THRESHOLD 12
#define CONFIG_ENTROPY_BT_HCI 1
#define CONFIG_ENTROPY_HAS_DRIVER 1
#define CONFIG_GPIO_LOG_LEVEL_INF 1
#define CONFIG_GPIO_LOG_LEVEL 3
#define CONFIG_GPIO_NRFX 1
#define CONFIG_FXL6408_LOG_LEVEL_INF 1
#define CONFIG_FXL6408_LOG_LEVEL 3
#define CONFIG_SPI_INIT_PRIORITY 70
#define CONFIG_SPI_COMPLETION_TIMEOUT_TOLERANCE 200
#define CONFIG_SPI_LOG_LEVEL_INF 1
#define CONFIG_SPI_LOG_LEVEL 3
#define CONFIG_SPI_NRFX 1
#define CONFIG_SPI_1_NRF_SPI 1
#define CONFIG_CLOCK_CONTROL_LOG_LEVEL_INF 1
#define CONFIG_CLOCK_CONTROL_LOG_LEVEL 3
#define CONFIG_CLOCK_CONTROL_NRF_FORCE_ALT 1
#define CONFIG_CLOCK_CONTROL_NRF 1
#define CONFIG_CLOCK_CONTROL_NRF_K32SRC_RC 1
#define CONFIG_CLOCK_CONTROL_NRF_K32SRC_RC_CALIBRATION 1
#define CONFIG_CLOCK_CONTROL_NRF_CALIBRATION_LF_ALWAYS_ON 1
#define CONFIG_CLOCK_CONTROL_NRF_CALIBRATION_PERIOD 4000
#define CONFIG_CLOCK_CONTROL_NRF_CALIBRATION_MAX_SKIP 1
#define CONFIG_CLOCK_CONTROL_NRF_CALIBRATION_TEMP_DIFF 2
#define CONFIG_CLOCK_CONTROL_NRF_K32SRC_500PPM 1
#define CONFIG_CLOCK_CONTROL_NRF_ACCURACY 500
#define CONFIG_FLASH_HAS_DRIVER_ENABLED 1
#define CONFIG_FLASH_HAS_PAGE_LAYOUT 1
#define CONFIG_FLASH 1
#define CONFIG_FLASH_LOG_LEVEL_INF 1
#define CONFIG_FLASH_LOG_LEVEL 3
#define CONFIG_FLASH_PAGE_LAYOUT 1
#define CONFIG_FLASH_INIT_PRIORITY 50
#define CONFIG_SOC_FLASH_NRF 1
#define CONFIG_SENSOR_LOG_LEVEL_INF 1
#define CONFIG_SENSOR_LOG_LEVEL 3
#define CONFIG_SENSOR_INIT_PRIORITY 90
#define CONFIG_TEMP_NRF5_FORCE_ALT 1
#define CONFIG_TEMP_NRF5 1
#define CONFIG_TMP112_FULL_SCALE_RUNTIME 1
#define CONFIG_TMP112_SAMPLING_FREQUENCY_RUNTIME 1
#define CONFIG_PINCTRL_LOG_LEVEL_INF 1
#define CONFIG_PINCTRL_LOG_LEVEL 3
#define CONFIG_PINCTRL_STORE_REG 1
#define CONFIG_PINCTRL_NRF 1
#define CONFIG_PINCTRL_STM32_REMAP_INIT_PRIORITY 2
#define CONFIG_SUPPORT_MINIMAL_LIBC 1
#define CONFIG_PICOLIBC_SUPPORTED 1
#define CONFIG_NEWLIB_LIBC 1
#define CONFIG_HAS_NEWLIB_LIBC_NANO 1
#define CONFIG_NEWLIB_LIBC_NANO 1
#define CONFIG_NEWLIB_LIBC_MIN_REQUIRED_HEAP_SIZE 2048
#define CONFIG_STDOUT_CONSOLE 1
#define CONFIG_MPSC_PBUF 1
#define CONFIG_REBOOT 1
#define CONFIG_CBPRINTF_COMPLETE 1
#define CONFIG_CBPRINTF_FULL_INTEGRAL 1
#define CONFIG_CBPRINTF_N_SPECIFIER 1
#define CONFIG_SYS_HEAP_ALLOC_LOOPS 3
#define CONFIG_SYS_HEAP_SMALL_ONLY 1
#define CONFIG_POSIX_MAX_FDS 4
#define CONFIG_MAX_TIMER_COUNT 5
#define CONFIG_BT 1
#define CONFIG_BT_LOG_LEVEL_INF 1
#define CONFIG_BT_LOG_LEVEL 3
#define CONFIG_BT_HCI 1
#define CONFIG_BT_CONN_TX 1
#define CONFIG_BT_CTLR_LE_ENC_SUPPORT 1
#define CONFIG_BT_CTLR_EXT_REJ_IND_SUPPORT 1
#define CONFIG_BT_CTLR_DATA_LEN_UPDATE_SUPPORT 1
#define CONFIG_BT_CTLR_PRIVACY_SUPPORT 1
#define CONFIG_BT_CTLR_EXT_SCAN_FP_SUPPORT 1
#define CONFIG_BT_CTLR_PHY_UPDATE_SUPPORT 1
#define CONFIG_BT_CTLR_PHY_2M_SUPPORT 1
#define CONFIG_BT_CTLR_PHY_CODED_SUPPORT 1
#define CONFIG_BT_CTLR_ADV_EXT_SUPPORT 1
#define CONFIG_BT_CTLR_ADV_PERIODIC_SUPPORT 1
#define CONFIG_BT_CTLR_SYNC_PERIODIC_SUPPORT 1
#define CONFIG_BT_CTLR_CHAN_SEL_2_SUPPORT 1
#define CONFIG_BT_CTLR_CONN_RSSI_SUPPORT 1
#define CONFIG_BT_CTLR_ECDH_SUPPORT 1
#define CONFIG_BT_CTLR_CRYPTO 1
#define CONFIG_BT_CTLR_HCI_VS_BUILD_INFO ""
#define CONFIG_BT_CTLR_AD_DATA_BACKUP 1
#define CONFIG_BT_CTLR_RX_BUFFERS 1
#define CONFIG_BT_CTLR_TX_PWR_0 1
#define CONFIG_BT_CTLR_LE_ENC 1
#define CONFIG_BT_CTLR_ECDH 1
#define CONFIG_BT_CTLR_EXT_REJ_IND 1
#define CONFIG_BT_CTLR_LE_PING 1
#define CONFIG_BT_CTLR_DATA_LENGTH 1
#define CONFIG_BT_CTLR_PHY 1
#define CONFIG_BT_CTLR_PRIVACY 1
#define CONFIG_BT_CTLR_RL_SIZE 8
#define CONFIG_BT_CTLR_PHY_2M 1
#define CONFIG_BT_CTLR_CHAN_SEL_2 1
#define CONFIG_BT_COMPANY_ID 0x05F1
#define CONFIG_PRINTK 1
#define CONFIG_EARLY_CONSOLE 1
#define CONFIG_ASSERT_VERBOSE 1
#define CONFIG_NVS 1
#define CONFIG_NVS_LOG_LEVEL_INF 1
#define CONFIG_NVS_LOG_LEVEL 3
#define CONFIG_LOG 1
#define CONFIG_LOG_MODE_DEFERRED 1
#define CONFIG_LOG_OVERRIDE_LEVEL 0
#define CONFIG_LOG_MAX_LEVEL 4
#define CONFIG_LOG_PRINTK 1
#define CONFIG_LOG_MODE_OVERFLOW 1
#define CONFIG_LOG_PROCESS_TRIGGER_THRESHOLD 10
#define CONFIG_LOG_PROCESS_THREAD 1
#define CONFIG_LOG_PROCESS_THREAD_STARTUP_DELAY_MS 0
#define CONFIG_LOG_PROCESS_THREAD_SLEEP_MS 1000
#define CONFIG_LOG_PROCESS_THREAD_STACK_SIZE 768
#define CONFIG_LOG_TRACE_SHORT_TIMESTAMP 1
#define CONFIG_LOG_FUNC_NAME_PREFIX_DBG 1
#define CONFIG_LOG_OUTPUT 1
#define CONFIG_LOG_BACKEND_SHOW_COLOR 1
#define CONFIG_LOG_TAG_MAX_LEN 0
#define CONFIG_LOG_BACKEND_FORMAT_TIMESTAMP 1
#define CONFIG_LOG_BACKEND_UART 1
#define CONFIG_LOG_BACKEND_UART_BUFFER_SIZE 1
#define CONFIG_LOG_BACKEND_UART_OUTPUT_TEXT 1
#define CONFIG_LOG_BACKEND_UART_OUTPUT_DEFAULT 0
#define CONFIG_LOG_BACKEND_RTT 1
#define CONFIG_LOG_BACKEND_RTT_MODE_BLOCK 1
#define CONFIG_LOG_BACKEND_RTT_OUTPUT_TEXT 1
#define CONFIG_LOG_BACKEND_RTT_OUTPUT_DEFAULT 0
#define CONFIG_LOG_BACKEND_RTT_OUTPUT_BUFFER_SIZE 16
#define CONFIG_LOG_BACKEND_RTT_RETRY_CNT 4
#define CONFIG_LOG_BACKEND_RTT_RETRY_DELAY_MS 5
#define CONFIG_LOG_BACKEND_RTT_BUFFER 0
#define CONFIG_LOG_BACKEND_RTT_FORCE_PRINTK 1
#define CONFIG_LOG_DOMAIN_ID 0
#define CONFIG_LOG_USE_VLA 1
#define CONFIG_NET_BUF 1
#define CONFIG_NET_BUF_USER_DATA_SIZE 0
#define CONFIG_NET_BUF_LOG_LEVEL_INF 1
#define CONFIG_NET_BUF_LOG_LEVEL 3
#define CONFIG_PM_LOG_LEVEL_INF 1
#define CONFIG_PM_LOG_LEVEL 3
#define CONFIG_PM_POLICY_DEFAULT 1
#define CONFIG_XOSHIRO_RANDOM_GENERATOR 1
#define CONFIG_CSPRING_ENABLED 1
#define CONFIG_HARDWARE_DEVICE_CS_GENERATOR 1
#define CONFIG_FLASH_MAP 1
#define CONFIG_SETTINGS 1
#define CONFIG_SETTINGS_LOG_LEVEL_INF 1
#define CONFIG_SETTINGS_LOG_LEVEL 3
#define CONFIG_SETTINGS_DYNAMIC_HANDLERS 1
#define CONFIG_SETTINGS_NVS 1
#define CONFIG_SETTINGS_NVS_SECTOR_SIZE_MULT 1
#define CONFIG_SETTINGS_NVS_SECTOR_COUNT 8
#define CONFIG_TOOLCHAIN_ZEPHYR_0_14 1
#define CONFIG_LINKER_ORPHAN_SECTION_WARN 1
#define CONFIG_HAS_FLASH_LOAD_OFFSET 1
#define CONFIG_FLASH_LOAD_OFFSET 0x0
#define CONFIG_FLASH_LOAD_SIZE 0x0
#define CONFIG_LD_LINKER_SCRIPT_SUPPORTED 1
#define CONFIG_LD_LINKER_TEMPLATE 1
#define CONFIG_KERNEL_ENTRY "__start"
#define CONFIG_LINKER_SORT_BY_ALIGNMENT 1
#define CONFIG_SRAM_OFFSET 0x0
#define CONFIG_LINKER_GENERIC_SECTIONS_PRESENT_AT_BOOT 1
#define CONFIG_SIZE_OPTIMIZATIONS 1
#define CONFIG_COMPILER_COLOR_DIAGNOSTICS 1
#define CONFIG_COMPILER_OPT ""
#define CONFIG_RUNTIME_ERROR_CHECKS 1
#define CONFIG_KERNEL_BIN_NAME "zephyr"
#define CONFIG_OUTPUT_STAT 1
#define CONFIG_OUTPUT_DISASSEMBLY 1
#define CONFIG_OUTPUT_PRINT_MEMORY_USAGE 1
#define CONFIG_BUILD_OUTPUT_BIN 1
#define CONFIG_WARN_DEPRECATED 1
#define CONFIG_EXPERIMENTAL 1
#define CONFIG_ENFORCE_ZEPHYR_STDINT 1
#define CONFIG_COMPAT_INCLUDES 1
#define CONFIG_LEGACY_INCLUDE_PATH 1
