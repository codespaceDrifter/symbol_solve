#pragma once

#include "../common/defs.hpp"
#include "raylib.h"

namespace visualization {

void InitCamera();
void UpdateCamera();
Camera& GetCamera();

} // namespace visualization 