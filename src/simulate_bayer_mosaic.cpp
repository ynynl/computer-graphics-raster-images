#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.reserve(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    int row, col;
    for (int i = 0; i < rgb.size() ; i += 3) {
        row = i / (3 * width);
        col = (i / 3) % (width);
        
        if (row % 2 == 0) {
            if (col % 2 == 0) {
                bayer.push_back(rgb.at(i + 1)); //g
            } else {
                bayer.push_back(rgb.at(i + 2)); //b
            }
        } else {
            if (col % 2 == 0) {
                bayer.push_back(rgb.at(i)); //r
            } else {
                bayer.push_back(rgb.at(i + 1)); //g
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
