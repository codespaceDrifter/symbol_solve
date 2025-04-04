#pragma once

#include "../common/defs.hpp"
#include "raylib.h"
#include "raymath.h"

namespace visualization {

class Camera {
public:
    static void Init();
    static void Update();
    static Camera3D GetCamera();
    
    static void SetPosition(Vector3 pos);
    static void SetTarget(Vector3 target);
    static void SetUp(Vector3 up);
    static void SetFOV(float fov);
    
    static Vector3 GetPosition();
    static Vector3 GetTarget();
    static Vector3 GetUp();
    static float GetFOV();
    
private:
    static Camera3D camera;
};

} // namespace visualization 