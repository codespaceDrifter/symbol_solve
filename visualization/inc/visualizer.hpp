#pragma once

#include "../common/defs.hpp"
#include "raylib.h"

namespace visualization {

void InitVisualization();
void StartVisualizationLoop();
void UpdateVisualization();
void RenderScene();
void CloseVisualization();

} // namespace visualization 