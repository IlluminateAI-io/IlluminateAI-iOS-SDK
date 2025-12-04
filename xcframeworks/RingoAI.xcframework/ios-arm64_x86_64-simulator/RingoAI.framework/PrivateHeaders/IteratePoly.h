//
//  IteratePoly.h
//  RingoAI
//
//  Created by roy on 7/11/24.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN
struct C_Histogram {
	integer_t	total;
	integer_t 	pixels[3][256];
	integer_t	fwhm[3];
};
typedef struct C_Histogram C_Histogram;

struct C_RGBFloat {
	float_t red,green,blue;
//	C_RGBFloat() {
//		red = 0.0;
//		green = 0.0;
//		blue = 0.0;
//	}
};
typedef struct C_RGBFloat C_RGBFloat;

#ifdef __cplusplus
extern "C" {
#endif
void C_Histogram_clear(C_Histogram* chist);
bool C_Histogram_validate(C_Histogram* chist);
#ifdef __cplusplus
}
#endif


@interface IteratePoly : NSObject

+ (CGRect)polyBounds:(const NSArray<NSValue*>*) polygon;
+ (void)withinPolygon:(const NSArray<NSValue*>*)polygon process:(void(NS_NOESCAPE ^)(long x, long y))block;
+ (void)withinPolygonBounds:(const NSArray<NSValue*>*)polygon process:(void(NS_NOESCAPE ^)(long x, long y))block;

+ (CGImageRef)polyChurn:(const NSArray<NSValue*>*)polygon
				 pixBuf:(CVPixelBufferRef)pixelBuffer
				  scale:(CGSize)scaleSize
			orientation:(int)orientation
			 whiteLevel:(float)whiteLevel
			 blackLevel:(float)blackLevel
			  histogram:(C_Histogram*)histogram
				average:(C_RGBFloat*)average;

@end

NS_ASSUME_NONNULL_END
