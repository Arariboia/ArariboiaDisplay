/** @file
 *  @brief MAVLink comm protocol generated from arariboat.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_ARARIBOAT_H
#define MAVLINK_ARARIBOAT_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_ARARIBOAT.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_ARARIBOAT_XML_HASH -478484895394520516

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {0, 22, 14, 20, 14, 10, 45, 19, 14, 14, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 25, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 24, 51, 9, 0}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {0, 83, 87, 37, 26, 40, 65, 161, 194, 17, 246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 151, 0, 220, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 79, 106, 83, 46, 0}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_ARARIBOAT

// ENUM DEFINITIONS


/** @brief Component ids (values) for the different types and instances of onboard hardware/software that might make up a MAVLink system (autopilot, cameras, servos, GPS systems, avoidance systems etc.).
      Components must use the appropriate ID in their source address when sending messages. Components can also use IDs to determine if they are the intended recipient of an incoming message. The MAV_COMP_ID_ALL value is used to indicate messages that must be processed by all components.
      When creating new entries, components that can have multiple instances (e.g. cameras, servos etc.) should be allocated sequential values. An appropriate number of values should be left free after these components to allow the number of instances to be expanded. */
#ifndef HAVE_ENUM_MAV_COMPONENT
#define HAVE_ENUM_MAV_COMPONENT
typedef enum MAV_COMPONENT
{
   MAV_COMP_ID_ALL=0, /* Target id (target_component) used to broadcast messages to all components of the receiving system. Components should attempt to process messages with this component ID and forward to components on any other interfaces. Note: This is not a valid *source* component id for a message. | */
   MAV_COMP_ID_RADIO_915=1, /* TTGO Lora Radio(100mW) | */
   MAV_COMP_ID_RADIO_433=2, /* EByte Lora Radio(2W) | */
   MAV_COMP_ID_INTERNET=3, /* Message sent via internet | */
   MAV_COMPONENT_ENUM_END=4, /*  | */
} MAV_COMPONENT;
#endif

/** @brief Represents the status of the battery. Derived from input register 3200. */
#ifndef HAVE_ENUM_MPPT_BATTERY_STATUS
#define HAVE_ENUM_MPPT_BATTERY_STATUS
typedef enum MPPT_BATTERY_STATUS
{
   MPPT_STATUS_NORMAL=0, /* All monitored parameters are normal. For battery (ID=3200): Voltage Normal (D3-D0=00H), Temp Normal (D7-D4=00H), Internal Resistance Normal (D8=0), Rated Voltage ID Normal (D15=0). | */
   MPPT_STATUS_OVERVOLTAGE=1, /* Battery overvoltage detected (e.g., ID=3200, D3-D0 = 01H). | */
   MPPT_STATUS_UNDERVOLTAGE=2, /* Battery undervoltage detected (e.g., ID=3200, D3-D0 = 02H). | */
   MPPT_STATUS_VOLTAGE_LOW_VOLT_DISCONNECT=3, /* Battery low voltage disconnect activated (e.g., ID=3200, D3-D0 = 03H). | */
   MPPT_STATUS_VOLTAGE_FAULT=4, /* A general battery voltage fault detected (e.g., ID=3200, D3-D0 = 04H). | */
   MPPT_STATUS_TEMP_OVER=5, /* Over temperature detected (e.g., ID=3200, D7-D4 = 01H). | */
   MPPT_STATUS_TEMP_LOW=6, /* Low temperature detected (e.g., ID=3200, D7-D4 = 02H). | */
   MPPT_STATUS_INTERNAL_RESISTANCE_ABNORMAL=7, /* Battery internal resistance is abnormal (e.g., ID=3200, D8 = 1). | */
   MPPT_STATUS_RATED_VOLTAGE_ID_WRONG=8, /* Wrong identification for rated voltage (e.g., ID=3200, D15 = 1). | */
   MPPT_STATUS_UNKNOWN=255, /* The status is unknown or not yet determined. | */
   MPPT_BATTERY_STATUS_ENUM_END=256, /*  | */
} MPPT_BATTERY_STATUS;
#endif

/** @brief Represents the primary status of the charging equipment. Derived by interpreting bits in input register 3201. The reported status may depend on the priority logic implemented in the monitoring software if multiple conditions are present. */
#ifndef HAVE_ENUM_MPPT_CHARGING_EQUIPMENT_STATUS
#define HAVE_ENUM_MPPT_CHARGING_EQUIPMENT_STATUS
typedef enum MPPT_CHARGING_EQUIPMENT_STATUS
{
   MPPT_CHARGING_STATUS_RUNNING_STANDBY=0, /* Equipment is running mode, else standby (register 3201: D0=1 = running). Typically implies no active charging and no faults. | */
   MPPT_CHARGING_STATUS_NORMAL_FAULT=1, /* Equipment has detected a fault (D1=1=Fault) | */
   MPPT_CHARGING_STATUS_FLOAT=2, /* Equipment is in float charging mode (register 3201: D0=1, D1=0 (No Fault), D3-D2=01H (Float), and D15-D14=00H (Input Volt Normal)). | */
   MPPT_CHARGING_STATUS_BOOST=3, /* Equipment is in boost charging mode (register 3201: D0=1, D1=0 (No Fault), D3-D2=02H (Boost), and D15-D14=00H (Input Volt Normal)). | */
   MPPT_CHARGING_STATUS_EQUALIZATION=4, /* Equipment is in equalization charging mode (register 3201: D0=1, D1=0 (No Fault), D3-D2=03H (Equalization), and D15-D14=00H (Input Volt Normal)). | */
   MPPT_CHARGING_INPUT_VOLTAGE_NONE=5, /* No power connected to input (register 3201: D15-D14=01H). Equipment may be off or in a pre-start state. | */
   MPPT_CHARGING_INPUT_VOLTAGE_HIGH=6, /* Input voltage is too high (register 3201: D15-D14=02H). This may lead to a fault condition (D1=1). | */
   MPPT_CHARGING_INPUT_VOLTAGE_ERROR=7, /* General input voltage error detected (register 3201: D15-D14=03H). This may lead to a fault condition (D1=1). | */
   MPPT_CHARGING_FAULT_PV_SHORT=8, /* PV input short circuit detected (register 3201: D4=1. Typically, D1=1 will also be set). | */
   MPPT_CHARGING_FAULT_LOAD_SIDE=9, /* Fault on the load side, such as load over current (D9=1), load short circuit (D8=1), or load MOSFET short (D7=1) (register 3201. Typically, D1=1 will also be set). | */
   MPPT_CHARGING_FAULT_INPUT_OVERCURRENT=10, /* Input over current detected (register 3201: D10=1. Typically, D1=1 will also be set). | */
   MPPT_CHARGING_FAULT_MOSFET_SHORT=11, /* Internal MOSFET short circuit detected (Charging MOSFET D13=1, Charging or Anti-reverse MOSFET D12=1, or Anti-reverse MOSFET D11=1) (register 3201. Typically, D1=1 will also be set). | */
   MPPT_CHARGING_FAULT_SYSTEM=12, /* A general system fault is active (register 3201: D1=1), not covered by other more specific fault entries in this enum. | */
   MPPT_CHARGING_STATUS_NO_CHARGING=13, /* Equipment is running but not actively charging (register 3201: D0=1, D1=0 (No Fault), D3-D2=00H (No Charging), and D15-D14=00H (Input Volt Normal)). | */
   MPPT_CHARGING_STATUS_UNKNOWN=255, /* The charging equipment status is unknown or not yet determined. | */
   MPPT_CHARGING_EQUIPMENT_STATUS_ENUM_END=256, /*  | */
} MPPT_CHARGING_EQUIPMENT_STATUS;
#endif

/** @brief 
        Flags to describe the charge/discharge status of a battery system, designed to be packed into a single byte.
        The status is composed of three parts:
        1. Operational State (2 bits, bits 0-1): Indicates if the system is stationary, charging, or discharging.
           - 0 (00b): Stationary
           - 1 (01b): Charging
           - 2 (10b): Discharging
           - 3 (11b): Reserved for future use.
        2. Charge MOSFET State (1 bit, bit 2): Indicates if the charge MOSFET is ON (1) or OFF (0).
        3. Discharge MOSFET State (1 bit, bit 3): Indicates if the discharge MOSFET is ON (1) or OFF (0).

        The enum entries provide values that can be ORed together to form the complete status byte.
        For example, to represent 'Charging' with 'Charge MOS ON' and 'Discharge MOS OFF':
        (CHARGE_DISCHARGE_STATE_CHARGING | CHARGE_DISCHARGE_CHARGE_MOS_ON)
        This would result in a value of (1 | 4) = 5.

        To decode:
        - state = value and 0x03;
        - charge_mos_on = (value and CHARGE_DISCHARGE_CHARGE_MOS_ON) != 0
        - discharge_mos_on = (value and CHARGE_DISCHARGE_DISCHARGE_MOS_ON) != 0
       */
#ifndef HAVE_ENUM_BMS_CHARGE_DISCHARGE_STATUS_FLAGS
#define HAVE_ENUM_BMS_CHARGE_DISCHARGE_STATUS_FLAGS
typedef enum BMS_CHARGE_DISCHARGE_STATUS_FLAGS
{
   CHARGE_DISCHARGE_STATE_STATIONARY=1, /* Operational state is Stationary (neither charging nor discharging). This value (00b) occupies bits 0-1. | */
   CHARGE_DISCHARGE_STATE_CHARGING=2, /* Operational state is Charging. This value (01b) occupies bits 0-1. | */
   CHARGE_DISCHARGE_STATE_DISCHARGING=4, /* Operational state is Discharging. This value (10b) occupies bits 0-1. | */
   CHARGE_DISCHARGE_CHARGE_MOS_ON=8, /* Charge MOSFET is ON. This flag occupies bit 2. If this flag is not set, Charge MOS is OFF. | */
   CHARGE_DISCHARGE_DISCHARGE_MOS_ON=16, /* Discharge MOSFET is ON. This flag occupies bit 3. If this flag is not set, Discharge MOS is OFF. | */
   BMS_CHARGE_DISCHARGE_STATUS_FLAGS_ENUM_END=17, /*  | */
} BMS_CHARGE_DISCHARGE_STATUS_FLAGS;
#endif

/** @brief Flags for Byte 0 of the Daly BMS failure status: Voltage-related failures. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE0_VOLTAGE_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE0_VOLTAGE_FLAGS
typedef enum DALY_FAILURE_BYTE0_VOLTAGE_FLAGS
{
   DALY_FAILURE_CELL_VOLT_HIGH_LVL1=1, /* Cell voltage high level 1 alarm. | */
   DALY_FAILURE_CELL_VOLT_HIGH_LVL2=2, /* Cell voltage high level 2 alarm. | */
   DALY_FAILURE_CELL_VOLT_LOW_LVL1=4, /* Cell voltage low level 1 alarm. | */
   DALY_FAILURE_CELL_VOLT_LOW_LVL2=8, /* Cell voltage low level 2 alarm. | */
   DALY_FAILURE_SUM_VOLT_HIGH_LVL1=16, /* Sum voltage high level 1 alarm. | */
   DALY_FAILURE_SUM_VOLT_HIGH_LVL2=32, /* Sum voltage high level 2 alarm. | */
   DALY_FAILURE_SUM_VOLT_LOW_LVL1=64, /* Sum voltage low level 1 alarm. | */
   DALY_FAILURE_SUM_VOLT_LOW_LVL2=128, /* Sum voltage low level 2 alarm. | */
   DALY_FAILURE_BYTE0_VOLTAGE_FLAGS_ENUM_END=129, /*  | */
} DALY_FAILURE_BYTE0_VOLTAGE_FLAGS;
#endif

/** @brief Flags for Byte 1 of the Daly BMS failure status: Temperature-related failures. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE1_TEMP_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE1_TEMP_FLAGS
typedef enum DALY_FAILURE_BYTE1_TEMP_FLAGS
{
   DALY_FAILURE_CHG_TEMP_HIGH_LVL1=1, /* Charge temperature high level 1 alarm. | */
   DALY_FAILURE_CHG_TEMP_HIGH_LVL2=2, /* Charge temperature high level 2 alarm. | */
   DALY_FAILURE_CHG_TEMP_LOW_LVL1=4, /* Charge temperature low level 1 alarm. | */
   DALY_FAILURE_CHG_TEMP_LOW_LVL2=8, /* Charge temperature low level 2 alarm. | */
   DALY_FAILURE_DISCHG_TEMP_HIGH_LVL1=16, /* Discharge temperature high level 1 alarm. | */
   DALY_FAILURE_DISCHG_TEMP_HIGH_LVL2=32, /* Discharge temperature high level 2 alarm. | */
   DALY_FAILURE_DISCHG_TEMP_LOW_LVL1=64, /* Discharge temperature low level 1 alarm. | */
   DALY_FAILURE_DISCHG_TEMP_LOW_LVL2=128, /* Discharge temperature low level 2 alarm. | */
   DALY_FAILURE_BYTE1_TEMP_FLAGS_ENUM_END=129, /*  | */
} DALY_FAILURE_BYTE1_TEMP_FLAGS;
#endif

/** @brief Flags for Byte 2 of the Daly BMS failure status: Current and SOC related failures. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE2_CURRENT_SOC_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE2_CURRENT_SOC_FLAGS
typedef enum DALY_FAILURE_BYTE2_CURRENT_SOC_FLAGS
{
   DALY_FAILURE_CHG_OVERCURRENT_LVL1=1, /* Charge overcurrent level 1 alarm. | */
   DALY_FAILURE_CHG_OVERCURRENT_LVL2=2, /* Charge overcurrent level 2 alarm. | */
   DALY_FAILURE_DISCHG_OVERCURRENT_LVL1=4, /* Discharge overcurrent level 1 alarm. | */
   DALY_FAILURE_DISCHG_OVERCURRENT_LVL2=8, /* Discharge overcurrent level 2 alarm. | */
   DALY_FAILURE_SOC_HIGH_LVL1=16, /* SOC high level 1 alarm. | */
   DALY_FAILURE_SOC_HIGH_LVL2=32, /* SOC high level 2 alarm. | */
   DALY_FAILURE_SOC_LOW_LVL1=64, /* SOC low level 1 alarm. | */
   DALY_FAILURE_SOC_LOW_LVL2=128, /* SOC low level 2 alarm. | */
   DALY_FAILURE_BYTE2_CURRENT_SOC_FLAGS_ENUM_END=129, /*  | */
} DALY_FAILURE_BYTE2_CURRENT_SOC_FLAGS;
#endif

/** @brief Flags for Byte 3 of the Daly BMS failure status: Differential voltage/temperature failures. Bits 4-7 are reserved. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE3_DIFFERENTIAL_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE3_DIFFERENTIAL_FLAGS
typedef enum DALY_FAILURE_BYTE3_DIFFERENTIAL_FLAGS
{
   DALY_FAILURE_DIFF_VOLT_LVL1=1, /* Differential voltage level 1 alarm. | */
   DALY_FAILURE_DIFF_VOLT_LVL2=2, /* Differential voltage level 2 alarm. | */
   DALY_FAILURE_DIFF_TEMP_LVL1=4, /* Differential temperature level 1 alarm. | */
   DALY_FAILURE_DIFF_TEMP_LVL2=8, /* Differential temperature level 2 alarm. | */
   DALY_FAILURE_BYTE3_DIFFERENTIAL_FLAGS_ENUM_END=9, /*  | */
} DALY_FAILURE_BYTE3_DIFFERENTIAL_FLAGS;
#endif

/** @brief Flags for Byte 4 of the Daly BMS failure status: MOSFET and related sensor failures. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE4_MOSFET_SENSOR_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE4_MOSFET_SENSOR_FLAGS
typedef enum DALY_FAILURE_BYTE4_MOSFET_SENSOR_FLAGS
{
   DALY_FAILURE_CHG_MOS_TEMP_HIGH_ALARM=1, /* Charge MOS temperature high alarm. | */
   DALY_FAILURE_DISCHG_MOS_TEMP_HIGH_ALARM=2, /* Discharge MOS temperature high alarm. | */
   DALY_FAILURE_CHG_MOS_TEMP_SENSOR_ERR=4, /* Charge MOS temperature sensor error. | */
   DALY_FAILURE_DISCHG_MOS_TEMP_SENSOR_ERR=8, /* Discharge MOS temperature sensor error. | */
   DALY_FAILURE_CHG_MOS_ADHESION_ERR=16, /* Charge MOS adhesion error. | */
   DALY_FAILURE_DISCHG_MOS_ADHESION_ERR=32, /* Discharge MOS adhesion error. | */
   DALY_FAILURE_CHG_MOS_OPEN_CIRCUIT_ERR=64, /* Charge MOS open circuit error. | */
   DALY_FAILURE_DISCHG_MOS_OPEN_CIRCUIT_ERR=128, /* Discharge MOS open circuit error (Corrected from 'Discrg' in PDF). | */
   DALY_FAILURE_BYTE4_MOSFET_SENSOR_FLAGS_ENUM_END=129, /*  | */
} DALY_FAILURE_BYTE4_MOSFET_SENSOR_FLAGS;
#endif

/** @brief Flags for Byte 5 of the Daly BMS failure status: System/Component failures. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE5_SYSTEM_COMPONENT_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE5_SYSTEM_COMPONENT_FLAGS
typedef enum DALY_FAILURE_BYTE5_SYSTEM_COMPONENT_FLAGS
{
   DALY_FAILURE_AFE_COLLECT_CHIP_ERR=1, /* AFE collect chip error. | */
   DALY_FAILURE_VOLTAGE_COLLECT_DROPPED=2, /* Voltage collect dropped. | */
   DALY_FAILURE_CELL_TEMP_SENSOR_ERR=4, /* Cell temperature sensor error. | */
   DALY_FAILURE_EEPROM_ERR=8, /* EEPROM error. | */
   DALY_FAILURE_RTC_ERR=16, /* RTC error. | */
   DALY_FAILURE_PRECHARGE_FAILURE=32, /* Precharge failure. | */
   DALY_FAILURE_COMMUNICATION_FAILURE=64, /* Communication failure (external). | */
   DALY_FAILURE_INTERNAL_COMM_FAILURE=128, /* Internal communication failure. | */
   DALY_FAILURE_BYTE5_SYSTEM_COMPONENT_FLAGS_ENUM_END=129, /*  | */
} DALY_FAILURE_BYTE5_SYSTEM_COMPONENT_FLAGS;
#endif

/** @brief Flags for Byte 6 of the Daly BMS failure status: Other faults. Bits 4-7 are reserved. */
#ifndef HAVE_ENUM_DALY_FAILURE_BYTE6_OTHER_FAULTS_FLAGS
#define HAVE_ENUM_DALY_FAILURE_BYTE6_OTHER_FAULTS_FLAGS
typedef enum DALY_FAILURE_BYTE6_OTHER_FAULTS_FLAGS
{
   DALY_FAILURE_CURRENT_MODULE_FAULT=1, /* Current module fault. | */
   DALY_FAILURE_SUM_VOLTAGE_DETECT_FAULT=2, /* Sum voltage detect fault. | */
   DALY_FAILURE_SHORT_CIRCUIT_PROTECT_FAULT=4, /* Short circuit protect fault. | */
   DALY_FAILURE_LOW_VOLT_FORBIDDEN_CHG_FAULT=8, /* Low voltage forbidden charge fault. | */
   DALY_FAILURE_BYTE6_OTHER_FAULTS_FLAGS_ENUM_END=9, /*  | */
} DALY_FAILURE_BYTE6_OTHER_FAULTS_FLAGS;
#endif

/** @brief ESC Gear status derived from bits 2-0 from message II, byte 3 */
#ifndef HAVE_ENUM_EZKONTROL_STATUS_GEAR
#define HAVE_ENUM_EZKONTROL_STATUS_GEAR
typedef enum EZKONTROL_STATUS_GEAR
{
   EZKONTROL_GEAR_NO=0, /* Gear: NO (Neutral/No Gear) | */
   EZKONTROL_GEAR_R=1, /* Gear: R (Reverse) | */
   EZKONTROL_GEAR_N=2, /* Gear: N (Neutral) | */
   EZKONTROL_GEAR_D1=3, /* Gear: D1 (Drive 1) | */
   EZKONTROL_GEAR_D2=4, /* Gear: D2 (Drive 2) | */
   EZKONTROL_GEAR_D3=5, /* Gear: D3 (Drive 3) | */
   EZKONTROL_GEAR_S=6, /* Gear: S (Sport/Special) | */
   EZKONTROL_GEAR_P=7, /* Gear: P (Park) | */
   EZKONTROL_STATUS_GEAR_ENUM_END=8, /*  | */
} EZKONTROL_STATUS_GEAR;
#endif

/** @brief ESC operation mode derived from bits 6-4 from message II, byte 3 */
#ifndef HAVE_ENUM_EZKONTROL_STATUS_OPERATION_MODE
#define HAVE_ENUM_EZKONTROL_STATUS_OPERATION_MODE
typedef enum EZKONTROL_STATUS_OPERATION_MODE
{
   EZKONTROL_OP_MODE_STOP=0, /* Operation Mode: Stop | */
   EZKONTROL_OP_MODE_DRIVE=1, /* Operation Mode: Drive | */
   EZKONTROL_OP_MODE_CRUISE=2, /* Operation Mode: Cruise | */
   EZKONTROL_OP_MODE_EBS=3, /* Operation Mode: EBS (Electronic Braking System) | */
   EZKONTROL_OP_MODE_HOLD=4, /* Operation Mode: Hold | */
   EZKONTROL_STATUS_OPERATION_MODE_ENUM_END=5, /*  | */
} EZKONTROL_STATUS_OPERATION_MODE;
#endif

/** @brief Status flags from Byte 3 of EZkontrol MCU Message II (Brake, DC Contactor). */
#ifndef HAVE_ENUM_EZKONTROL_STATUS_BYTE3_FLAGS
#define HAVE_ENUM_EZKONTROL_STATUS_BYTE3_FLAGS
typedef enum EZKONTROL_STATUS_BYTE3_FLAGS
{
   EZKONTROL_STATUS_BRAKE_ACTIVE=8, /* Brake is active. | */
   EZKONTROL_STATUS_DC_CONTACTOR_ON=128, /* DC Contactor is ON. | */
   EZKONTROL_STATUS_BYTE3_FLAGS_ENUM_END=129, /*  | */
} EZKONTROL_STATUS_BYTE3_FLAGS;
#endif

/** @brief Error flags from Byte 4 of EZkontrol MCU Message II. */
#ifndef HAVE_ENUM_EZKONTROL_ERROR_BYTE4_FLAGS
#define HAVE_ENUM_EZKONTROL_ERROR_BYTE4_FLAGS
typedef enum EZKONTROL_ERROR_BYTE4_FLAGS
{
   EZKONTROL_ERROR_OVERCURRENT=1, /* Error: Overcurrent. | */
   EZKONTROL_ERROR_OVERLOAD=2, /* Error: Overload. | */
   EZKONTROL_ERROR_OVERVOLTAGE=4, /* Error: Overvoltage. | */
   EZKONTROL_ERROR_UNDERVOLTAGE=8, /* Error: Undervoltage. | */
   EZKONTROL_ERROR_CONTROLLER_OVERHEAT=16, /* Error: Controller Overheat. | */
   EZKONTROL_ERROR_MOTOR_OVERHEAT=32, /* Error: Motor Overheat. | */
   EZKONTROL_ERROR_MOTOR_STALLED=64, /* Error: Motor Stalled. | */
   EZKONTROL_ERROR_MOTOR_OUT_OF_PHASE=128, /* Error: Motor Out of phase. | */
   EZKONTROL_ERROR_BYTE4_FLAGS_ENUM_END=129, /*  | */
} EZKONTROL_ERROR_BYTE4_FLAGS;
#endif

/** @brief Error flags from Byte 5 of EZkontrol MCU Message II. */
#ifndef HAVE_ENUM_EZKONTROL_ERROR_BYTE5_FLAGS
#define HAVE_ENUM_EZKONTROL_ERROR_BYTE5_FLAGS
typedef enum EZKONTROL_ERROR_BYTE5_FLAGS
{
   EZKONTROL_ERROR_MOTOR_SENSOR=1, /* Error: Motor Sensor. | */
   EZKONTROL_ERROR_MOTOR_AUX_SENSOR=2, /* Error: Motor AUX Sensor. | */
   EZKONTROL_ERROR_ENCODER_MISALIGNED=4, /* Error: Encoder Misaligned. | */
   EZKONTROL_ERROR_ANTI_RUNAWAY_ENGAGED=8, /* Error: Anti-Runaway Engaged. | */
   EZKONTROL_ERROR_MAIN_ACCELERATOR=16, /* Error: Main Accelerator. | */
   EZKONTROL_ERROR_AUX_ACCELERATOR=32, /* Error: AUX Accelerator. | */
   EZKONTROL_ERROR_PRE_CHARGE=64, /* Error: Pre-charge. | */
   EZKONTROL_ERROR_DC_CONTACTOR_FAULT=128, /* Error: DC Contactor fault (distinct from status). | */
   EZKONTROL_ERROR_BYTE5_FLAGS_ENUM_END=129, /*  | */
} EZKONTROL_ERROR_BYTE5_FLAGS;
#endif

/** @brief Error flags from Byte 6 of EZkontrol MCU Message II. */
#ifndef HAVE_ENUM_EZKONTROL_ERROR_BYTE6_FLAGS
#define HAVE_ENUM_EZKONTROL_ERROR_BYTE6_FLAGS
typedef enum EZKONTROL_ERROR_BYTE6_FLAGS
{
   EZKONTROL_ERROR_POWER_VALVE=1, /* Error: Power valve. | */
   EZKONTROL_ERROR_CURRENT_SENSOR=2, /* Error: Current Sensor. | */
   EZKONTROL_ERROR_AUTO_TUNE=4, /* Error: Auto-tune. | */
   EZKONTROL_ERROR_RS485=8, /* Error: RS485 communication. | */
   EZKONTROL_ERROR_CAN_COMM=16, /* Error: CAN communication. | */
   EZKONTROL_ERROR_SOFTWARE=32, /* Error: Software. | */
   EZKONTROL_ERROR_BYTE6_FLAGS_ENUM_END=33, /*  | */
} EZKONTROL_ERROR_BYTE6_FLAGS;
#endif

/** @brief Specifies the datatype of a MAVLink parameter. */
#ifndef HAVE_ENUM_MAV_PARAM_TYPE
#define HAVE_ENUM_MAV_PARAM_TYPE
typedef enum MAV_PARAM_TYPE
{
   MAV_PARAM_TYPE_UINT8=1, /* 8-bit unsigned integer | */
   MAV_PARAM_TYPE_INT8=2, /* 8-bit signed integer | */
   MAV_PARAM_TYPE_UINT16=3, /* 16-bit unsigned integer | */
   MAV_PARAM_TYPE_INT16=4, /* 16-bit signed integer | */
   MAV_PARAM_TYPE_UINT32=5, /* 32-bit unsigned integer | */
   MAV_PARAM_TYPE_INT32=6, /* 32-bit signed integer | */
   MAV_PARAM_TYPE_UINT64=7, /* 64-bit unsigned integer | */
   MAV_PARAM_TYPE_INT64=8, /* 64-bit signed integer | */
   MAV_PARAM_TYPE_REAL32=9, /* 32-bit floating-point | */
   MAV_PARAM_TYPE_REAL64=10, /* 64-bit floating-point | */
   MAV_PARAM_TYPE_ENUM_END=11, /*  | */
} MAV_PARAM_TYPE;
#endif

/** @brief Indicates the severity level, generally used for status messages to indicate their relative urgency. Based on RFC-5424 using expanded definitions at: http://www.kiwisyslog.com/kb/info:-syslog-message-levels/. */
#ifndef HAVE_ENUM_MAV_SEVERITY
#define HAVE_ENUM_MAV_SEVERITY
typedef enum MAV_SEVERITY
{
   MAV_SEVERITY_EMERGENCY=0, /* System is unusable. This is a "panic" condition. | */
   MAV_SEVERITY_ALERT=1, /* Action should be taken immediately. Indicates error in non-critical systems. | */
   MAV_SEVERITY_CRITICAL=2, /* Action must be taken immediately. Indicates failure in a primary system. | */
   MAV_SEVERITY_ERROR=3, /* Indicates an error in secondary/redundant systems. | */
   MAV_SEVERITY_WARNING=4, /* Indicates about a possible future error if this is not resolved within a given timeframe. Example would be a low battery warning. | */
   MAV_SEVERITY_NOTICE=5, /* An unusual event has occurred, though not an error condition. This should be investigated for the root cause. | */
   MAV_SEVERITY_INFO=6, /* Normal operational messages. Useful for logging. No action is required for these messages. | */
   MAV_SEVERITY_DEBUG=7, /* Useful non-operational messages that can assist in debugging. These should not occur during normal operation. | */
   MAV_SEVERITY_ENUM_END=8, /*  | */
} MAV_SEVERITY;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_instrumentation.h"
#include "./mavlink_msg_temperatures.h"
#include "./mavlink_msg_gps.h"
#include "./mavlink_msg_mppt.h"
#include "./mavlink_msg_mppt_state.h"
#include "./mavlink_msg_bms.h"
#include "./mavlink_msg_bms_status.h"
#include "./mavlink_msg_ezkontrol_mcu_meter_data_i.h"
#include "./mavlink_msg_ezkontrol_mcu_meter_data_ii.h"
#include "./mavlink_msg_pumps.h"
#include "./mavlink_msg_param_request_read.h"
#include "./mavlink_msg_param_value.h"
#include "./mavlink_msg_param_set.h"
#include "./mavlink_msg_radio_status.h"
#include "./mavlink_msg_named_value_float.h"
#include "./mavlink_msg_named_value_int.h"
#include "./mavlink_msg_statustext.h"
#include "./mavlink_msg_debug.h"

// base include



#if MAVLINK_ARARIBOAT_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {{"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_INSTRUMENTATION, MAVLINK_MESSAGE_INFO_TEMPERATURES, MAVLINK_MESSAGE_INFO_GPS, MAVLINK_MESSAGE_INFO_MPPT, MAVLINK_MESSAGE_INFO_MPPT_STATE, MAVLINK_MESSAGE_INFO_BMS, MAVLINK_MESSAGE_INFO_BMS_STATUS, MAVLINK_MESSAGE_INFO_EZKONTROL_MCU_METER_DATA_I, MAVLINK_MESSAGE_INFO_EZKONTROL_MCU_METER_DATA_II, MAVLINK_MESSAGE_INFO_PUMPS, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_READ, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_PARAM_VALUE, MAVLINK_MESSAGE_INFO_PARAM_SET, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_RADIO_STATUS, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_NAMED_VALUE_FLOAT, MAVLINK_MESSAGE_INFO_NAMED_VALUE_INT, MAVLINK_MESSAGE_INFO_STATUSTEXT, MAVLINK_MESSAGE_INFO_DEBUG, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}}
# define MAVLINK_MESSAGE_NAMES {{ "BMS", 6 }, { "BMS_STATUS", 7 }, { "DEBUG", 254 }, { "EZKONTROL_MCU_METER_DATA_I", 8 }, { "EZKONTROL_MCU_METER_DATA_II", 9 }, { "GPS", 3 }, { "INSTRUMENTATION", 1 }, { "MPPT", 4 }, { "MPPT_STATE", 5 }, { "NAMED_VALUE_FLOAT", 251 }, { "NAMED_VALUE_INT", 252 }, { "PARAM_REQUEST_READ", 20 }, { "PARAM_SET", 23 }, { "PARAM_VALUE", 22 }, { "PUMPS", 10 }, { "RADIO_STATUS", 109 }, { "STATUSTEXT", 253 }, { "TEMPERATURES", 2 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_ARARIBOAT_H
