#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    // C = A Over B
    for (int i = 0; i < A.size(); i += 4) {
        double alphaA = A[i+3]/255.0;
        double alphaB = B[i+3]/255.0;
        double alphaO = alphaA + (alphaB * (1 - alphaA));
        
        if (C[i+3] == 0) {
            continue;
            
        } else {
            for (int j = i; j < i + 3; j++) {
                C[j] = (A[j] * alphaA + (B[j] * alphaB * (1 - alphaA))) / alphaO;
            }
        C[i+3] = alphaO * 255;
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
