#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
      for (int i = 0; i < rgb.size(); i += 3) {
          double h, s, v;
          double r = rgb.at(i) * 1.0;
          double g = rgb.at(i + 1) * 1.0;
          double b = rgb.at(i + 2) * 1.0;
          
          rgb_to_hsv(r, g, b, h, s, v);
          hsv_to_rgb(h, s * (1.0 - factor), v, r, g, b);
          
          desaturated[i] = (int)r;
          desaturated[i + 1] = (int)g;
          desaturated[i + 2] = (int)b;
      }
  ////////////////////////////////////////////////////////////////////////////
}
