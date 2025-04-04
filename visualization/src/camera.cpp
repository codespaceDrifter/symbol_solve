#include "../inc/camera.hpp"
#include "../inc/control.hpp"
#include "raylib.h"
#include "raymath.h"

namespace visualization {

Camera3D Camera::camera = {0};
static Vector3 initialPosition = {10.0f, 10.0f, 10.0f};
static Vector3 initialTarget = {0.0f, 0.0f, 0.0f};

void Camera::Init() {
    camera.position = initialPosition;
    camera.target = initialTarget;
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void Camera::Update() {
    // Get control state
    float zoom = Control::GetZoomLevel();
    Vector2 rotation = Control::GetRotation();
    Vector2 pan = Control::GetPanOffset();
    
    // Reset camera to initial position
    camera.position = initialPosition;
    camera.target = initialTarget;
    
    // Apply zoom
    Vector3 direction = Vector3Subtract(camera.target, camera.position);
    float distance = Vector3Length(direction);
    direction = Vector3Normalize(direction);
    distance *= zoom;
    camera.position = Vector3Subtract(camera.target, Vector3Scale(direction, distance));
    
    // Apply rotation
    Matrix rotationMatrix = MatrixRotateXYZ({rotation.y * DEG2RAD, rotation.x * DEG2RAD, 0});
    Vector3 offset = Vector3Subtract(camera.position, camera.target);
    offset = Vector3Transform(offset, rotationMatrix);
    camera.position = Vector3Add(camera.target, offset);
    
    // Apply pan
    Vector3 right = Vector3Normalize(Vector3CrossProduct(Vector3Subtract(camera.target, camera.position), camera.up));
    Vector3 up = Vector3Normalize(Vector3CrossProduct(right, Vector3Subtract(camera.target, camera.position)));
    
    camera.position = Vector3Add(camera.position, Vector3Scale(right, pan.x));
    camera.position = Vector3Add(camera.position, Vector3Scale(up, pan.y));
    camera.target = Vector3Add(camera.target, Vector3Scale(right, pan.x));
    camera.target = Vector3Add(camera.target, Vector3Scale(up, pan.y));
}

Camera3D Camera::GetCamera() {
    return camera;
}

void Camera::SetPosition(Vector3 pos) {
    camera.position = pos;
}

void Camera::SetTarget(Vector3 target) {
    camera.target = target;
}

void Camera::SetUp(Vector3 up) {
    camera.up = up;
}

void Camera::SetFOV(float fov) {
    camera.fovy = fov;
}

Vector3 Camera::GetPosition() {
    return camera.position;
}

Vector3 Camera::GetTarget() {
    return camera.target;
}

Vector3 Camera::GetUp() {
    return camera.up;
}

float Camera::GetFOV() {
    return camera.fovy;
}

} // namespace visualization
