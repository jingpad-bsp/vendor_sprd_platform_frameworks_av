#ifndef ANDROID_SERVERS_CAMERA_CAMERAPROVIDERMANAGER_EX_H
#define ANDROID_SERVERS_CAMERA_CAMERAPROVIDERMANAGER_EX_H

namespace android {

// For sprd multi-camera id
typedef enum {
    SPRD_MULTI_CAMERA_BASE_ID = 16,
    SPRD_3D_FACE_ID,
    SPRD_RANGE_FINDER_ID,
    SPRD_3D_CAPTURE_ID,
    SPRD_3D_CALIBRATION_ID = 20,
    SPRD_REFOCUS_ID,
    SPRD_3D_PREVIEW_ID,
    SPRD_SOFY_OPTICAL_ZOOM_ID,
    SPRD_BLUR_ID,
    SPRD_SELF_SHOT_ID = 25,
    SPRD_PAGE_TURN_ID,
    SPRD_BLUR_FRONT_ID,
    SPRD_BOKEH_ID,
    SPRD_SBS_ID,
    SPRD_SINGLE_FACEID_REGISTER_ID = 30,
    SPRD_SINGLE_FACEID_UNLOCK_ID,
    SPRD_DUAL_FACEID_REGISTER_ID,
    SPRD_DUAL_FACEID_UNLOCK_ID,
    SPRD_3D_VIDEO_ID,
    SPRD_ULTRA_WIDE_ID,
    SPRD_MULTI_CAMERA_ID = 36,
    SPRD_BACK_HIGH_RESOLUTION_ID = 37,
    SPRD_PORTRAIT_ID = 38,
    SPRD_FRONT_HIGH_RES = 39,
    SPRD_OPTICSZOOM_W_ID = 40,
    SPRD_OPTICSZOOM_T_ID = 41,
    SPRD_PORTRAIT_SINGLE_ID = 42,
    SPRD_3D_FACEID_REGISTER_ID = 46,
    SPRD_3D_FACEID_UNLOCK_ID = 47,
    SPRD_FOV_FUSION_ID = 48,
    SPRD_MULTI_CAMERA_MAX_ID
} multiCameraId;

inline bool isSprdMultiCamera(int cameraId) {
    if((cameraId > SPRD_MULTI_CAMERA_BASE_ID) &&
       (cameraId < SPRD_MULTI_CAMERA_MAX_ID))
        return true;
    else
        return false;
}

// Get main camera id for multi camera
inline int getMainCamIdForMultiCamId(int multiCameraId) {
    int mainCameraId = 0;

    switch(multiCameraId) {
        case SPRD_3D_VIDEO_ID:
        case SPRD_RANGE_FINDER_ID:
        case SPRD_3D_CAPTURE_ID:
        case SPRD_3D_CALIBRATION_ID:
        case SPRD_3D_PREVIEW_ID:
        case SPRD_SELF_SHOT_ID:
        case SPRD_SINGLE_FACEID_REGISTER_ID:
        case SPRD_SINGLE_FACEID_UNLOCK_ID:
        case SPRD_DUAL_FACEID_REGISTER_ID:
        case SPRD_DUAL_FACEID_UNLOCK_ID:
        case SPRD_BLUR_FRONT_ID:
        case SPRD_FRONT_HIGH_RES:
            mainCameraId = 1;
            break;
        case SPRD_REFOCUS_ID:
        case SPRD_BLUR_ID:
        case SPRD_BOKEH_ID:
        case SPRD_PORTRAIT_ID:
        case SPRD_PORTRAIT_SINGLE_ID:
        case SPRD_SOFY_OPTICAL_ZOOM_ID:
        case SPRD_FOV_FUSION_ID:
        case SPRD_ULTRA_WIDE_ID:
        case SPRD_MULTI_CAMERA_ID:
        case SPRD_BACK_HIGH_RESOLUTION_ID:
        case SPRD_OPTICSZOOM_W_ID:
        case SPRD_OPTICSZOOM_T_ID:
            mainCameraId = 0;
            break;
        case SPRD_PAGE_TURN_ID:
            mainCameraId = 2;
            break;
        default:
            ALOGE("unknown multiple camera id");
            break;
    }

    return mainCameraId;
}

inline bool initSprdMultiCamera(std::vector<std::string>& fakeCameraList) {

    std::string prefix = "device@3.3/legacy/";
    for(int index = SPRD_MULTI_CAMERA_BASE_ID + 1; index < SPRD_MULTI_CAMERA_MAX_ID; index++){
        std::string fakeCamera = prefix + std::to_string(index);
        fakeCameraList.push_back(fakeCamera);
    }

    ALOGI("%s, size = %zu", __FUNCTION__, fakeCameraList.size());
    if(fakeCameraList.size() > 0) {
        return true;
    }

    return false;
}

};
#endif

