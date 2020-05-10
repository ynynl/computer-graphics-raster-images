#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

#include <sstream>
#include <string>



bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    std::ofstream outfile (filename);
    std::ostringstream vts;

    if (!data.empty()) {
        std::copy(data.begin(),
                  data.end(),
                  std::ostream_iterator<int>(vts, " "));
    }

    outfile <<
                "P" + std::to_string(num_channels) + "\n"
                + std::to_string(width) + " " + std::to_string(height) + "\n"
                + std::to_string(255) + "\n"
                + vts.str()
    << std::endl;

    outfile.close();
    
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
