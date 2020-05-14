#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.reserve(height * width * 3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    if (!rgba.empty()) {
        for (int i = 0; i < rgba.size()/4; i++) {
            std::copy(rgba.begin() + 4 * i,
                      rgba.begin() + 4 * i + 3,
                      std::back_inserter(rgb));
        }
    }
  ////////////////////////////////////////////////////////////////////////////

}

