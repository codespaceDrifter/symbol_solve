#include "../common/defs.hpp"
#include "raylib.h"
#include "camera.hpp"

namespace visualization {

// Configuration
const int screenWidth = 1280;
const int screenHeight = 720;
const char* windowTitle = "Symbol Core";
Color backgroundColor = RAYWHITE;
bool isVisualizationRunning = false;

// Function prototypes
void InitVisualization();
void UpdateVisualization();
void RenderScene();
void CloseVisualization();

void InitVisualization() {
    // Initialize window and OpenGL context
    InitWindow(screenWidth, screenHeight, windowTitle);
    SetTargetFPS(60);
    
    // Initialize camera
    InitCamera();
    
    isVisualizationRunning = true;
}

void StartVisualizationLoop() {
    if (!isVisualizationRunning) {
        InitVisualization();
    }
    
    // Main visualization loop
    while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
        UpdateVisualization();
        
        BeginDrawing();
            ClearBackground(backgroundColor);
            
            BeginMode3D(GetCamera());
                RenderScene();
            EndMode3D();
            
            // Draw UI elements in 2D
            DrawFPS(10, 10);
            DrawText("Use mouse to rotate camera, scroll wheel to zoom", 10, 40, 20, DARKGRAY);
            DrawText("Press ESC to exit", 10, 70, 20, DARKGRAY);
        EndDrawing();
    }
    
    CloseVisualization();
}

void UpdateVisualization() {
    // Update camera based on user input
    UpdateCamera();
    
    // Here you would update physics simulation if needed
    // This function can be extended to handle simulation time steps
}

void RenderScene() {
    // Draw grid for reference
    DrawGrid(10, 1.0f);
    
    // Draw coordinate axes
    DrawLine3D({0, 0, 0}, {2, 0, 0}, RED);    // X-axis
    DrawLine3D({0, 0, 0}, {0, 2, 0}, GREEN);  // Y-axis
    DrawLine3D({0, 0, 0}, {0, 0, 2}, BLUE);   // Z-axis
    
    // Here you would render your physics objects
    // Example: Draw a sphere at the origin
    DrawSphere({0, 1, 0}, 0.5f, GOLD);
    
    // Example: Draw a cube
    DrawCube({2, 0.5f, 2}, 1.0f, 1.0f, 1.0f, PURPLE);
}

void CloseVisualization() {
    // Clean up resources
    CloseWindow();
    isVisualizationRunning = false;
}

} // namespace visualization 