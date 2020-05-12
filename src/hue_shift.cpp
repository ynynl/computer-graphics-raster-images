#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <cmath>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    for (int i = 0; i < rgb.size(); i += 3) {
        double h, s, v;
        double r = rgb.at(i) * 1.0;
        double g = rgb.at(i + 1) * 1.0;
        double b = rgb.at(i + 2) * 1.0;
        
        rgb_to_hsv(r, g, b, h, s, v);
        hsv_to_rgb(std::fmod(h + shift, 360), s, v, r, g, b);
        
        shifted[i] = (int)r;
        shifted[i + 1] = (int)g;
        shifted[i + 2] = (int)b;
    }
  ////////////////////////////////////////////////////////////////////////////
}
