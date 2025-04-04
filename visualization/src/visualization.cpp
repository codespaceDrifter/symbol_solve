#include "../inc/visualization.hpp"
#include "../inc/camera.hpp"
#include "../inc/control.hpp"
#include "raylib.h"
#include "raymath.h"

namespace visualization {

void Init() {
    InitWindow(800, 600, "Symbol Solve Visualization");
    SetTargetFPS(60);
    
    Camera::Init();
    Control::Init();
}

void Update() {
    Control::Update();
    Camera::Update();
}

void Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    
    BeginMode3D(Camera::GetCamera());
    
    // Draw infinite grid
    const float gridSize = 100.0f;
    const float gridStep = 1.0f;
    const int gridLines = 100;
    
    // Draw XZ plane grid
    for (int i = -gridLines; i <= gridLines; i++) {
        float pos = i * gridStep;
        // Draw lines parallel to X axis
        DrawLine3D({-gridSize, 0, pos}, {gridSize, 0, pos}, GRAY);
        // Draw lines parallel to Z axis
        DrawLine3D({pos, 0, -gridSize}, {pos, 0, gridSize}, GRAY);
    }
    
    // Draw XY plane grid
    for (int i = -gridLines; i <= gridLines; i++) {
        float pos = i * gridStep;
        // Draw lines parallel to X axis
        DrawLine3D({-gridSize, pos, 0}, {gridSize, pos, 0}, GRAY);
        // Draw lines parallel to Y axis
        DrawLine3D({pos, -gridSize, 0}, {pos, gridSize, 0}, GRAY);
    }
    
    // Draw YZ plane grid
    for (int i = -gridLines; i <= gridLines; i++) {
        float pos = i * gridStep;
        // Draw lines parallel to Y axis
        DrawLine3D({0, -gridSize, pos}, {0, gridSize, pos}, GRAY);
        // Draw lines parallel to Z axis
        DrawLine3D({0, pos, -gridSize}, {0, pos, gridSize}, GRAY);
    }
    
    // Draw coordinate axes
    DrawLine3D({0, 0, 0}, {gridSize, 0, 0}, RED);   // X axis
    DrawLine3D({0, 0, 0}, {0, gridSize, 0}, GREEN); // Y axis
    DrawLine3D({0, 0, 0}, {0, 0, gridSize}, BLUE);  // Z axis
    
    EndMode3D();
    
    // Draw FPS
    DrawFPS(10, 10);
    
    EndDrawing();
}

void Cleanup() {
    CloseWindow();
}

} // namespace visualization 