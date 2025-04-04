#include "../inc/control.hpp"
#include "raylib.h"
#include "raymath.h"

namespace visualization {

// Control state
static float zoomSpeed = 0.1f;
static float rotationSpeed = 0.5f;
static float panSpeed = 0.1f;
static bool isDragging = false;
static bool isZooming = false;
static bool isPanning = false;
static Vector2 lastMousePosition = {0, 0};
static float zoomLevel = 1.0f;
static Vector2 panOffset = {0, 0};
static Vector2 rotation = {0, 0};

void Control::Init() {
    lastMousePosition = GetMousePosition();
    zoomLevel = 1.0f;
    panOffset = {0, 0};
    rotation = {0, 0};
}

void Control::Update() {
    HandleMouseInput();
    HandleKeyboardInput();
}

void Control::HandleMouseInput() {
    Vector2 currentMousePos = GetMousePosition();
    
    // Handle mouse wheel zoom
    float wheelMove = GetMouseWheelMove();
    if (wheelMove != 0) {
        zoomLevel += wheelMove * zoomSpeed;
        zoomLevel = Clamp(zoomLevel, 0.1f, 10.0f);
    }
    
    // Handle right click drag for rotation
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        if (!isDragging) {
            isDragging = true;
            lastMousePosition = currentMousePos;
        } else {
            Vector2 delta = {currentMousePos.x - lastMousePosition.x, 
                           currentMousePos.y - lastMousePosition.y};
            rotation.x += delta.x * rotationSpeed * 0.1f;
            rotation.y += delta.y * rotationSpeed * 0.1f;
            lastMousePosition = currentMousePos;
        }
    } else {
        isDragging = false;
    }
    
    // Handle middle click drag for panning
    if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
        if (!isPanning) {
            isPanning = true;
            lastMousePosition = currentMousePos;
        } else {
            Vector2 delta = {currentMousePos.x - lastMousePosition.x,
                           currentMousePos.y - lastMousePosition.y};
            panOffset.x += delta.x * panSpeed * 0.1f;
            panOffset.y += delta.y * panSpeed * 0.1f;
            lastMousePosition = currentMousePos;
        }
    } else {
        isPanning = false;
    }
}

void Control::HandleKeyboardInput() {
    // Add keyboard controls if needed
}

float Control::GetZoomSpeed() { return zoomSpeed; }
float Control::GetRotationSpeed() { return rotationSpeed; }
float Control::GetPanSpeed() { return panSpeed; }

void Control::SetZoomSpeed(float speed) { zoomSpeed = speed; }
void Control::SetRotationSpeed(float speed) { rotationSpeed = speed; }
void Control::SetPanSpeed(float speed) { panSpeed = speed; }

bool Control::IsDragging() { return isDragging; }
bool Control::IsZooming() { return isZooming; }
bool Control::IsPanning() { return isPanning; }

Vector2 Control::GetLastMousePosition() { return lastMousePosition; }
void Control::SetLastMousePosition(Vector2 pos) { lastMousePosition = pos; }

float Control::GetZoomLevel() { return zoomLevel; }
void Control::SetZoomLevel(float zoom) { zoomLevel = zoom; }

Vector2 Control::GetPanOffset() { return panOffset; }
void Control::SetPanOffset(Vector2 offset) { panOffset = offset; }

Vector2 Control::GetRotation() { return rotation; }
void Control::SetRotation(Vector2 rot) { rotation = rot; }

} // namespace visualization 