#include "demosaic.h"
#include "numeric"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.reserve(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
      int row, col;
      for (int i = 0; i < bayer.size() ; i ++) {
          row = i / width;
          col = i % width;
          
          if (row % 2 == 0) {
              if (col % 2 == 0) { //g
                  std::vector<int> red;
                  std::vector<int> blue;
                  if (row != 0) {
                      red.push_back(bayer.at(i - width));
                  }
                  if (row != height - 1) {
                      red.push_back(bayer.at(i + width));
                  }
                  if (col != 0) {
                      blue.push_back(bayer.at(i - 1));
                  }
                  if (col != width - 1) {
                      blue.push_back(bayer.at(i + 1));
                  }
                  
                  int a_red = std::accumulate(red.begin(), red.end(), 0.0) / red.size();
                  int a_blue = std::accumulate(blue.begin(), blue.end(), 0.0) / blue.size();

                  rgb.push_back(a_red); //red
                  rgb.push_back(bayer.at(i)); //green
                  rgb.push_back(a_blue); //blue

              } else { //blue
                  std::vector<int> green;
                  std::vector<int> red;

                  if (row != 0) {
                      green.push_back(bayer.at(i - width));
                      if (col != 0) {
                          red.push_back(bayer.at(i - width -1));
                      }
                      if (col != width) {
                          red.push_back(bayer.at(i - width + 1));
                      }
                  }
                  if (row != height -1) {
                      green.push_back(bayer.at(i + width));
                      if (col != 0) {
                          red.push_back(bayer.at(i + width -1));
                      }
                      if (col != width) {
                          red.push_back(bayer.at(i + width + 1));
                      }
                  }
                  if (col != 0) {
                      green.push_back(bayer.at(i - 1));
                  }
                  if (col != width) {
                      green.push_back(bayer.at(i + 1));
                  }
                  
                  int a_green = std::accumulate(green.begin(), green.end(), 0.0) / green.size();
                  int a_red = std::accumulate(red.begin(), red.end(), 0.0) / red.size();

                  rgb.push_back(a_red); //red
                  rgb.push_back(a_green); //green
                  rgb.push_back(bayer.at(i)); //blue
                  
              }
          } else {
              if (col % 2 == 0) { //r
                  std::vector<int> green;
                  std::vector<int> blue;

                  if (row != 0) {
                      green.push_back(bayer.at(i - width));
                      if (col != 0) {
                          blue.push_back(bayer.at(i - width -1));
                      }
                      if (col != width - 1) {
                          blue.push_back(bayer.at(i - width + 1));
                      }
                  }
                  if (row != height - 1) {
                      green.push_back(bayer.at(i + width));
                      if (col != 0) {
                          blue.push_back(bayer.at(i + width - 1));
                      }
                      if (col != width - 1 ) {
                          blue.push_back(bayer.at(i + width + 1));
                      }
                  }
                  if (col != 0) {
                      green.push_back(bayer.at(i - 1));
                  }
                  if (col != width - 1) {
                      green.push_back(bayer.at(i + 1));
                  }
                  
                  int a_green = std::accumulate(green.begin(), green.end(), 0.0) / green.size();
                  int a_blue = std::accumulate(blue.begin(), blue.end(), 0.0) / blue.size();

                  rgb.push_back(bayer.at(i)); //red
                  rgb.push_back(a_green); //green
                  rgb.push_back(a_blue);
                  
              } else { //green
                  std::vector<int> red;
                  std::vector<int> blue;
                  if (row != 0) {
                      blue.push_back(bayer.at(i - width));
                  }
                  if (row != height -1) {
                      blue.push_back(bayer.at(i + width));
                  }
                  if (col != 0) {
                      red.push_back(bayer.at(i - 1));
                  }
                  if (col != width) {
                      red.push_back(bayer.at(i + 1));
                  }
                  
                  int a_red = std::accumulate(red.begin(), red.end(), 0.0) / red.size();
                  int a_blue = std::accumulate(blue.begin(), blue.end(), 0.0) / blue.size();

                  rgb.push_back(a_red); //red
                  rgb.push_back(bayer.at(i)); //green
                  rgb.push_back(a_blue);
              }
          }
      }
  ////////////////////////////////////////////////////////////////////////////
}
