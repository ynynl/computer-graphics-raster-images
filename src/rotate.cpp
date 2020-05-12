#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.reserve(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    int n_width = width * num_channels;
    
    for (int i = n_width; i > 0; i -= num_channels) {
        for (int j = i; j != (height) * n_width + i; j += n_width) {
            std::copy(input.begin() + j - num_channels,
                      input.begin() + j,
                      std::back_inserter(rotated));
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
