#ifndef _PARAMETERS_EX_FUN_H_
#define _PARAMETERS_EX_FUN_H_

namespace android{
namespace camera2{

/*
 * dont edit the enum alone, camera hal have the same enum
 */
enum top_app_id {
    TOP_APP_NONE,
    TOP_APP_WECHAT,
    TOP_APP_MAX
};

status_t initializeEx(Parameters *p);
status_t setEx(Parameters *p , Parameters *validatedParams , CameraParameters2 *newParams);
status_t updateRequestEx(const Parameters *p , CameraMetadata *request);
status_t updateIsTakePictureWithFlashToAppEx(Parameters *p , int value);
};
};

#endif
