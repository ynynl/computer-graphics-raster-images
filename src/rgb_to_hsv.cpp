#include "rgb_to_hsv.h"
#include <cmath>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    double r1 = r/255.0;
    double g1 = g/255.0;
    double b1 = b/255.0;
    
    double cmax = std::fmax(r1, g1);
    cmax = std::fmax(cmax, b1);
    
    double cmin = std::fmin(r1, g1);
    cmin = std::fmin(cmin, b1);
    
    double delta = cmax - cmin;
    
    if (delta == 0) {
        h = 0;
    } else if (cmax == r1) {
        h = 60 * (std::fmod((g1 - b1) / delta, 6));
    } else if (cmax == g1) {
        h = 60 * (((b1 - r1) / delta) + 2);
    } else if (cmax == b1) {
        h = 60 * (((r1 - g1) / delta) + 4);
    }
    
    if (cmax == 0) {
        s = 0;
    } else {
        s = delta / cmax;
    }
    
    v = cmax;
  ////////////////////////////////////////////////////////////////////////////
}
