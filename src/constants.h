#ifndef CONSTANTS
#define CONSTANTS

#include <cmath>

namespace constants {
// _________________
// CONFIG FLAGS

// flag -- to turn on the dubins heuristic
static const bool dubins = false;

// flag -- to turn on the dubins lookup
static const bool dubinsLookup = true*dubins;

// flag -- to turn on the 2D heuristic
static const bool twoD = false;

// flag -- switch to false for velodyne data
static const bool manual = true;

// flag -- switch to true to activate obstacle bloating
static const bool obstacleBloating = false;

// _________________
// GENERAL CONSTANTS

// [m] -- uniformly added padding around the vehicle
static const double bloating = 0;

// [m] -- width of the vehicle
static const double width = 1.75 + 2 * bloating;

// [m] -- length of the vehicle
static const double length = 2.65 + 2 * bloating;

// [m] -- minimum turning radius of the vehicle
static const float r = 5;

// [#] -- number of discretizations in heading
static const int headings = 72;

// [°] -- discretization value of heading == goal condition
static const float deltaHeadingDeg = 360 / headings;

// [c*PI] -- discretization value of heading
static const float deltaHeadingRad = 2 * M_PIl / headings;

// [m] -- cell size in [m]
static const float cellSize = 1;

// ___________________
// HEURISTIC CONSTANTS

// [#] -- factor to ensure admissibility
static const float factor2D = sqrt(5) / sqrt(2) + 1;

// [#] -- penalty for turning
static const float penaltyTurning = 1.1;

// ______________________
// DUBINS LOOKUP SPECIFIC

// [m] -- width of the dubinsArea / 2
static const int dubinsWidth = 25;
// [m²] -- area of the dubinsArea
static const int dubinsArea = dubinsWidth*dubinsWidth;


// _________________________
// COLLISION LOOKUP SPECIFIC

// [m] -- bounding box size length/width
static const int bbSize = std::ceil(sqrt(width * width + length* length) + 4 / cellSize);

// [#] -- number of discrete per cell length
static const int positionResolution = 10;
// [#] -- number of discrete points in one square
static const int positions = positionResolution * positionResolution;

// [i] -- relative position from center of the vehicle
struct relPos {
  int x;
  int y;
};

//
struct config {
  int length;
  relPos pos[64];
};

}

#endif // CONSTANTS
