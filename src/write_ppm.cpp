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
    
    if (!data.empty()) {
        
        assert((data.size()/num_channels == width * height) && "data size does not match image size");

        std::ofstream outfile (filename);
        std::ostringstream vts;
        int P;
        if (num_channels == 3) {P = 3;} else {P = 2;}
        
        std::copy(data.begin(),
                  data.end(),
                  std::ostream_iterator<int>(vts, " "));
        
        outfile << "P" + std::to_string(P) + "\n"
                    + std::to_string(width) + " " + std::to_string(height) + "\n"
                    + std::to_string(255) + "\n"
                    + vts.str() << std::endl;

        outfile.close();
            
        std::cout << "\"" + filename + "\"" + " wrote successfully" << std::endl;
    }
    
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
