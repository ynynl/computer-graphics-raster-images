#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.reserve(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double rw = 0.2126;
    double rg = 0.7152;
    double rb = 0.0722;
    
    for (int i = 0; i < rgb.size(); i += 3) {
        gray.push_back((rw * rgb.at(i) + rg * rgb.at(i + 1) + rb * rgb.at(i + 2)));
    }
    
    
  ////////////////////////////////////////////////////////////////////////////
}


