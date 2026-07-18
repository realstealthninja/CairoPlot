#pragma once
#include <vector>

namespace CairoGraphConstants {

constexpr double BOX_LINEWIDTH = 1.5;
constexpr double GRID_LINEWIDTH = 0.0005; // in scaled coordinates
constexpr double OFFSET_X = 0.1750;
constexpr double OFFSET_Y = 0.1000;
constexpr double GRAPH_WIDTH = 0.720;
constexpr double GRAPH_HEIGHT = 0.720;
constexpr double TICKS_LENGTH = 0.010;
const std::vector<double> dashes1 { 5.0, 2.5 };
const std::vector<double> dashes2 { 2.5, 2.5 };
const std::vector<double> dashes3 { 0.008, 0.012 }; // in scaled coordinates
constexpr int start_height = 256;
constexpr int start_width = 256;

} // namespace CairoGraphConstants
