#pragma once
#include "raylib.h"
#include "raymath.h"
#include "../common/defs.hpp"

namespace visualization {

class Control {
public:
    static void Init();
    static void Update();
    static void HandleMouseInput();
    static void HandleKeyboardInput();
    
    static float GetZoomSpeed();
    static float GetRotationSpeed();
    static float GetPanSpeed();
    
    static void SetZoomSpeed(float speed);
    static void SetRotationSpeed(float speed);
    static void SetPanSpeed(float speed);
    
    static bool IsDragging();
    static bool IsZooming();
    static bool IsPanning();
    
    static Vector2 GetLastMousePosition();
    static void SetLastMousePosition(Vector2 pos);
    
    static float GetZoomLevel();
    static void SetZoomLevel(float zoom);
    
    static Vector2 GetPanOffset();
    static void SetPanOffset(Vector2 offset);
    
    static Vector2 GetRotation();
    static void SetRotation(Vector2 rot);
};

} // namespace visualization 