//
//  GyroHelper.h
//

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>


@protocol GyroHelperDelegate <NSObject>

@optional

- (void)gyroLevel:(BOOL)isLevel;
- (void)gyroShaking:(BOOL)isShaking;
- (void)gyroOrientation:(UIDeviceOrientation)orientation;
- (void)gyroGravity:(CMAcceleration)gravity;
- (void)gyroExactPitch:(double)pitch roll:(double)roll yaw:(double)yaw;

- (void)rawGyroShaking:(BOOL)isShaking;

@end

@interface GyroHelper : NSObject

+ (GyroHelper*)singleton;

- (void)addDelegate:(id<GyroHelperDelegate>)delegate;
- (void)removeDelegate:(id<GyroHelperDelegate>)delegate;

@end
