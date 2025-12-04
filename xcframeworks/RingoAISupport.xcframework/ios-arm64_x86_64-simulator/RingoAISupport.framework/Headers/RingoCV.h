//
//  RingoCV.h
//  MySkin
//
//  Created by roy on 1/15/25.
//
#include <TargetConditionals.h> // required in Xcode 8+

#define RINGO_CV 1
typedef void* IMAGE;
typedef void* CGPOINT;
#ifdef __cplusplus
extern "C" {
#endif
bool ringo_glasses(IMAGE ciimg, CGPOINT l_eye, CGPOINT r_eye, double glassesConstant);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#if TARGET_OS_SIMULATOR
#else

typedef void* InputArray_;
typedef void* OutputArray_;
#define SOLVEPNP_ITERATIVE_ 0

void ringo_RQDecomp3x3(InputArray_ src, OutputArray_ mtxR, OutputArray_ mtxQ,
					   OutputArray_ Qx,
					   OutputArray_ Qy,
					   OutputArray_ Qz);

bool ringo_solvePnP(InputArray_ objectPoints, InputArray_ imagePoints,
					InputArray_ cameraMatrix, InputArray_ distCoeffs,
					OutputArray_ rvec, OutputArray_ tvec,
					bool useExtrinsicGuess = false, int flags = SOLVEPNP_ITERATIVE_ );

void ringo_Rodrigues(InputArray_ src, OutputArray_ dst, OutputArray_ jacobian);
void ringo_Rodrigues(InputArray_ src, OutputArray_ dst);
#endif // TARGET_OS_SIMULATOR


#endif
