//
//  Goodies.h
//  RingoAI
//
//  Created by roy on 3/28/24.
//

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>
#import <CallKit/CallKit.h>


NS_ASSUME_NONNULL_BEGIN
@class AVDepthData;

@interface ObjC : NSObject
+ (nullable NSString*)phoneModel;
+ (NSDictionary<NSString*,NSNumber*>*)nanInROI:(AVDepthData*)depthData roi:(NSDictionary*)points;
+ (AVDepthData*)cleanNaN:(AVDepthData*)depthData totalNaNs:(integer_t*)total;
+ (NSString*)buildDate;
+ (NSString*)buildTime;
+ (NSData*)preprocess:(Float32*)pixelBuffer w:(size_t)w h:(size_t)h pt1:(CGPoint)pt1 pt2:(CGPoint)pt2;
+ (double)grab_depth:(Float32*)pixelBuffer w:(size_t)w h:(size_t)h where:(CGPoint)pt;
@end

//@interface MPPFaceLandmarker(stuff)
//- (BOOL)detect:(MPPImage *)image
// timestampInMS:(NSInteger)ts;
//@end



#if __cplusplus
extern "C" {
#endif
NSArray* getCaveMetadata(CIImage* img,  NSArray* lm);
void getRGBAfromCIImage(CIImage* _Nonnull img, void (^ _Nonnull callback)(UInt32* _Nonnull buffer, size_t width, size_t height, size_t rowbytes));
void getRGBchunk(UInt32* buffer, size_t width, size_t height, size_t stride,
				 size_t x1, size_t y1, size_t x2, size_t y2,
				 UInt8* r, UInt8* g, UInt8* b) ;

#if __cplusplus
}
#endif

NS_ASSUME_NONNULL_END
#else
#endif


#if __cplusplus
#import <vector>

typedef std::vector<float> F32vector;
typedef Float32* F32pointer;


#if MATRIX2D_PTR
void getAVDepthDataBuffer(void* _Nonnull depthData, size_t& width, size_t& height, size_t& span, F32pointer _Nonnull & values);
#else
void getAVDepthDataBuffer(void* _Nonnull depthData, size_t& width, size_t& height, size_t& span, F32vector& values);
#endif

template <typename T> inline const T pin(const T& _min, const T& _val, const T& _max) {
	return ((_val < _min) ? _min : ( (_val > _max) ? _max : _val));
}
#endif

