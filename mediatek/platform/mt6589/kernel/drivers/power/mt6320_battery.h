
#ifndef MT6320_BATTERY_H
#define MT6320_BATTERY_H

#include <linux/ioctl.h>

#define PRE_CHARGE_VOLTAGE                  3200
#define SYSTEM_OFF_VOLTAGE                  3550  //mingquan.lai change power-off voltage to 3.55V
#define CONSTANT_CURRENT_CHARGE_VOLTAGE     4100  
#define CONSTANT_VOLTAGE_CHARGE_VOLTAGE     4200  
#define CV_DROPDOWN_VOLTAGE                 4000
#define CHARGER_THRESH_HOLD                 4300
#define BATTERY_UVLO_VOLTAGE                2700

//#define MAX_CHARGING_TIME                   8*60*60 	// 8hr
//#define MAX_CHARGING_TIME                   12*60*60 	// 12hr
#define MAX_CHARGING_TIME                   24*60*60 	// 24hr
#define MAX_POSTFULL_SAFETY_TIME       		1*30*60 	// 30mins
#define MAX_PreCC_CHARGING_TIME         	1*30*60  	// 0.5hr
#define MAX_CV_CHARGING_TIME              	3*60*60 	// 3hr
//#define MAX_CV_CHARGING_TIME              	24*60*60 	// 24hr
#define MUTEX_TIMEOUT                       5000
#define BAT_TASK_PERIOD                     10 			// 10sec
#define g_free_bat_temp 					1000 		// 1 s

#define Battery_Percent_100    100
#define charger_OVER_VOL	    1
#define BATTERY_UNDER_VOL		2
#define BATTERY_OVER_TEMP		3
#define ADC_SAMPLE_TIMES        5
#define BATTERY_LOW_TEMP 	4


#define TURN_OFF_CHARGING_FOR_FACTORY _IOW('k', 7, int)
#define  CHR_PRE                        0x1000
#define  CHR_CC                         0x1001 
#define  CHR_TOP_OFF                    0x1002 
#define  CHR_POST_FULL                  0x1003
#define  CHR_BATFULL                    0x1004 
#define  CHR_ERROR                      0x1005

typedef unsigned int       WORD;
typedef enum {
    CHARGER_UNKNOWN = 0,
    STANDARD_HOST,          // USB : 450mA
    CHARGING_HOST,
    NONSTANDARD_CHARGER,    // AC : 450mA~1A 
    STANDARD_CHARGER,       // AC : ~1A
} CHARGER_TYPE;

typedef enum
{
	USB_SUSPEND = 0,
	USB_UNCONFIGURED,
	USB_CONFIGURED
}usb_state_enum;

typedef enum
{
        TEMP_BELOW_NEG_10 = 0,
        TEMP_NEG_10_TO_POS_0,
        TEMP_POS_0_TO_POS_10,
        TEMP_POS_10_TO_POS_45,
        TEMP_POS_45_TO_POS_60,
        TEMP_ABOVE_POS_60
}temp_state_enum;
    
#define TEMP_POS_60_THRESHOLD  50
#define TEMP_POS_60_THRES_MINUS_X_DEGREE 47  

#define TEMP_POS_45_THRESHOLD  45
#define TEMP_POS_45_THRES_MINUS_X_DEGREE 39

#define TEMP_POS_10_THRESHOLD  10
#define TEMP_POS_10_THRES_PLUS_X_DEGREE 16

#define TEMP_POS_0_THRESHOLD  0
#define TEMP_POS_0_THRES_PLUS_X_DEGREE 6

#ifdef MTK_FAN5405_SUPPORT
#define TEMP_NEG_10_THRESHOLD  0
#define TEMP_NEG_10_THRES_PLUS_X_DEGREE  0
#elif defined( MTK_BQ24158_SUPPORT)
#define TEMP_NEG_10_THRESHOLD  0
#define TEMP_NEG_10_THRES_PLUS_X_DEGREE  0
#else
#define TEMP_NEG_10_THRESHOLD  0
#define TEMP_NEG_10_THRES_PLUS_X_DEGREE  0
#endif

#ifdef CONFIG_MTK_SMART_BATTERY

extern void wake_up_bat(void);
extern unsigned long BAT_Get_Battery_Voltage(int polling_mode);

#else

#define wake_up_bat()			do {} while (0)
#define BAT_Get_Battery_Voltage(polling_mode)	({ 0; })

#endif

#endif

