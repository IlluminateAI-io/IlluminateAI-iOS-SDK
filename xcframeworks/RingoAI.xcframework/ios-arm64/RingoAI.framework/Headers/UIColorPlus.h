//
//  UIColorPlus.h
//

#import <UIKit/UIKit.h>

@interface UIColor(plus)

+ (UIColor *)colorFromHexString:(NSString *)hexString;
+ (UIColor *)colorWithWebColor:(NSUInteger)webColor alpha:(CGFloat)alpha;
+ (UIColor *)colorWithR:(UInt8)red G:(UInt8)green B:(UInt8)blue alpha:(CGFloat)alpha;

@end
