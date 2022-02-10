#ifndef SPRD_SERVERS_CAMERA_CAMERA2PARAMETERS_EX_H
#define SPRD_SERVERS_CAMERA_CAMERA2PARAMETERS_EX_H

#ifdef SPRD_FEATURE_BRIGHTNESS
int brightness;
#endif /* SPRD_FEATURE_BRIGHTNESS */
#ifdef SPRD_FEATURE_3GVT
int sensorRot;
int sensorOrient;
#endif // #ifdef SPRD_FEATURE_3GVT

#ifdef SPRD_FEATURE_ISO
int iso;
#endif /* SPRD_FEATURE_ISO */

#ifdef SPRD_FEATURE_CONTRAST
int contrast;
#endif /* SPRD_FEATURE_CONTRAST */

#ifdef SPRD_FEATURE_SATURATION
int saturation;
#endif /* SPRD_FEATURE_SATURATION */

#ifdef SPRD_FEATURE_METERING_MODE
int meteringmode;
#endif /* SPRD_FEATURE_METERING_MODE */

#ifdef SPRD_FEATURE_SLOW_MOTION
int slowmotion;
#endif /* SPRD_FEATURE_SLOW_MOTION */

#ifdef SPRD_FEATURE_BEAUTY
static const int FACE_BEAUTY_LEVEL_NUM = 9;
int perfectSkinlevel[FACE_BEAUTY_LEVEL_NUM];
#endif // #ifdef SPRD_FEATURE_BEAUTY

#ifdef SPRD_FEATURE_ZSL
bool zsl;
#endif // #ifdef SPRD_FEATURE_ZSL


#ifdef SPRD_FEATURE_COVERED_SENSOR
int availableSensorSelfShot;
#endif // #ifdef SPRD_FEATURE_COVERED_SENSOR

#ifdef SPRD_FEATURE_3DNR
bool threednr;
#endif

uint8_t isTakePictureWithFlash;

int appmode;

int topAppId;

#endif /* SPRD_SERVERS_CAMERA_CAMERA2PARAMETERS_EX_H */
