#include "../common/defs.hpp"
#include "raylib.h"
#include "raymath.h"
#include "camera.hpp"

namespace visualization {

Camera camera = { 0 };
Vector2 previousMousePosition = { 0.0f, 0.0f };
bool isDragging = false;
float zoomIncrement = 0.5f;
float minZoom = 1.0f;
float maxZoom = 20.0f;

void InitCamera() {
    // Alternative Vector3 initialization
    camera.position = Vector3{10.0f, 10.0f, 10.0f};  // C++ style initialization
    camera.target = Vector3{0.0f, 0.0f, 0.0f};       // C++ style initialization
    camera.up = Vector3{0.0f, 1.0f, 0.0f};           // C++ style initialization
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void UpdateCamera() {
    // Handle mouse wheel for zoom
    float wheel = GetMouseWheelMove();
    if (wheel != 0) {
        Vector3 toTarget = Vector3Subtract(camera.target, camera.position);
        float distance = Vector3Length(toTarget);
        
        // Adjust distance based on wheel movement
        distance -= wheel * zoomIncrement;
        distance = Clamp(distance, minZoom, maxZoom);
        
        // Normalize the direction vector
        toTarget = Vector3Normalize(toTarget);
        
        // Set new camera position
        camera.position = Vector3Subtract(camera.target, Vector3Scale(toTarget, distance));
    }
    
    // Handle click and drag for camera rotation
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isDragging = true;
        previousMousePosition = GetMousePosition();
    } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        isDragging = false;
    }
    
    if (isDragging) {
        Vector2 currentMousePosition = GetMousePosition();
        Vector2 mouseDelta = Vector2Subtract(currentMousePosition, previousMousePosition);
        
        // Adjust rotation sensitivity
        float rotationSpeed = 0.003f;
        
        if (Vector2Length(mouseDelta) > 0) {
            // Calculate camera right vector
            Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
            Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, camera.up));
            
            // Rotate around horizontal and vertical axes
            float horizontalAngle = -mouseDelta.x * rotationSpeed;
            float verticalAngle = -mouseDelta.y * rotationSpeed;
            
            // Apply horizontal rotation (around world up vector)
            Matrix rotationMatrixH = MatrixRotate(camera.up, horizontalAngle);
            Vector3 newPosition = Vector3Transform(Vector3Subtract(camera.position, camera.target), rotationMatrixH);
            camera.position = Vector3Add(camera.target, newPosition);
            
            // Apply vertical rotation (around camera right vector)
            Matrix rotationMatrixV = MatrixRotate(right, verticalAngle);
            newPosition = Vector3Transform(Vector3Subtract(camera.position, camera.target), rotationMatrixV);
            camera.position = Vector3Add(camera.target, newPosition);
            
            // Update camera up vector to maintain orientation
            camera.up = Vector3Normalize(Vector3CrossProduct(right, Vector3Normalize(Vector3Subtract(camera.target, camera.position))));
        }
        
        previousMousePosition = currentMousePosition;
    }
}

Camera& GetCamera() {
    return camera;
}

} // namespace visualization
