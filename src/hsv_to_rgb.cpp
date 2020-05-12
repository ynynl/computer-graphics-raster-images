#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    double c = v * s;
    double x = c * (1 - std::fabs(std::fmod(h / 60, 2) - 1));
    double m = v - c;
    
    double r1, g1, b1;
    
    if (0 <= h and h < 60) {
        r1 = c;
        g1 = x;
        b1 = 0;
    } else if (60 <= h and h < 120) {
        r1 = x;
        g1 = c;
        b1 = 0;
    } else if (120 <= h and h < 180) {
        r1 = 0;
        g1 = c;
        b1 = x;
    } else if (180 <= h and h < 240) {
        r1 = 0;
        g1 = x;
        b1 = c;
    } else if (240 <= h and h < 300) {
        r1 = x;
        g1 = 0;
        b1 = c;
    } else if (300 <= h and h < 360) {
        r1 = c;
        g1 = 0;
        b1 = x;
    } else {
        r1 = 0;
        g1 = 0;
        b1 = 0;
    }
    
    r = 255 * (r1 + m);
    g = 255 * (g1 + m);
    b = 255 * (b1 + m);
  ////////////////////////////////////////////////////////////////////////////
}
