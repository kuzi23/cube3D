#include "cube3d.h"


// Normalize angle to range [0, 2*PI)
double normalize_angle(double angle)
{
    angle = fmod(angle, 2 * PI);
    if (angle < 0)
        angle += 2 * PI;
    return angle;
}

// Compute Euclidean distance between two points (x1,y1) and (x2,y2)
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}