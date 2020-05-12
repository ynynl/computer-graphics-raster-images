#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.reserve(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    if (!input.empty()) {
        for (int i = width * num_channels; i <= input.size(); i += width * num_channels) {
            for (int j = i; j != i - width * num_channels; j -= num_channels) {
                std::copy(input.begin() + j - num_channels,
                          input.begin() + j,
                          std::back_inserter(reflected));
            }
        }
    }
    
  ////////////////////////////////////////////////////////////////////////////
}
