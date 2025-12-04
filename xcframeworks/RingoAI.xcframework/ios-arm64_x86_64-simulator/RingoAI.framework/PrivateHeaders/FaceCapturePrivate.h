//
//  FaceCapturePrivate.h
//  RingoAI
//

#import <RingoAI/FaceCapture.h>

@interface FaceCapture(Private)
- (void)callComplete:(BOOL)success;
- (void)callCompleteCancel;
- (void)callResults:(BOOL)success
			   info:(NSDictionary<NSString*,id>*)info;
- (void)callThermalWarning:(BOOL)abort;
- (void)metadata:(NSDictionary<NSString*,NSObject*>*)meta;
- (void)popUX:(UINavigationController*)navVC animated:(BOOL)animated;
- (void)pop;
@end

extern BOOL launchedCalled;

#import "PocketSVG.h"
