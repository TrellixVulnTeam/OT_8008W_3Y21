
#include <utils/Log.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <math.h>

#include "MediaHal.h"

//#include "lens_custom_cfg.h"
//#include "msdk_lens_exp.h"
#include "camera_custom_lens.h"
//#include "lens.h"
//nclude "image_sensor.h"
#include "kd_imgsensor.h"

extern PFUNC_GETLENSDEFAULT pDummy_getDefaultData;

#if defined(SENSORDRIVE)
extern PFUNC_GETLENSDEFAULT pSensorDrive_getDefaultData;
#endif

#if defined(FM50AF)
extern PFUNC_GETLENSDEFAULT pFM50AF_getDefaultData;
#endif


#if defined(OV8825AF)
extern PFUNC_GETLENSDEFAULT pOV8825AF_getDefaultData;
#endif

#if defined(OV8825SUNNYAF)
extern PFUNC_GETLENSDEFAULT pOV8825SUNNYAF_getDefaultData;
#endif

#if defined(OV8825TRULYAF)
extern PFUNC_GETLENSDEFAULT pOV8825TRULYAF_getDefaultData;
#endif

MSDK_LENS_INIT_FUNCTION_STRUCT LensList[MAX_NUM_OF_SUPPORT_LENS] =
{
	{DUMMY_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},

#if defined(SENSORDRIVE)
	{DUMMY_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},	

    //  for backup lens, need assign correct SensorID
    //{OV5642_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},
#endif

#if defined(OV8825AF)
		{OV8825_SENSOR_ID, OV8825AF_LENS_ID, "OV8825AF", pOV8825AF_getDefaultData},
#endif

#if defined(OV8825SUNNYAF)
		{OV8825_SUNNY_SENSOR_ID, OV8825SUNNYAF_LENS_ID, "OV8825SUNNYAF", pOV8825SUNNYAF_getDefaultData},
#endif

#if defined(OV8825TRULYAF)
		{OV8825_TRULY_SENSOR_ID, OV8825TRULYAF_LENS_ID, "OV8825TRULYAF", pOV8825TRULYAF_getDefaultData},
#endif

#if defined(FM50AF)
	{DUMMY_SENSOR_ID, FM50AF_LENS_ID, "FM50AF", pFM50AF_getDefaultData},
#endif

    //  for new added lens, need assign correct SensorID

};

UINT32 GetLensInitFuncList(PMSDK_LENS_INIT_FUNCTION_STRUCT pLensList)
{
    memcpy(pLensList, &LensList[0], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT)* MAX_NUM_OF_SUPPORT_LENS);
    return MHAL_NO_ERROR;
} // GetLensInitFuncList()






