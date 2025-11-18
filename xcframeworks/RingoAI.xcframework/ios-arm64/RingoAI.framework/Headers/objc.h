//
//  objc.h
//  MySkin
//
//  Created by roy on 8/26/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Accessibility/Accessibility.h>

@interface NSObject(extras)
@property (nonatomic, readonly) NSUInteger rc;

- (void)set_int:(int)value for_key:(NSString*_Nonnull)key;
- (void)set_value:(id _Nonnull )value for_key:(NSString*_Nonnull)key;
- (id _Nonnull )get_value:(NSString*_Nonnull)key;

- (void)RELEASE;
- (void)RETAIN;

@end

//extern BOOL UIAccessibilityIsAutoBrightnessEnabled(void);

//extern BOOL _UIAccessibilityAutoBrightnessEnabled(void);
//extern BOOL _UIAccessibilityReduceWhitePoint(void);
//extern BOOL _UIAccessibilityIsEnabled(void);
//extern BOOL _UIAccessibilityBoldTextEnabled(void);
extern id MADisplayFilterInversionCompensationForNightShift(void);

//extern UInt16 _AXSAutoBrightnessEnabled(void);
//extern NSString* kAXSAutoBrightnessChangedNotification;

@interface UIScreen(extra)
@end

NS_INLINE NSException * _Nullable ExecuteWithObjCExceptionHandling(void(NS_NOESCAPE^_Nonnull tryBlock)(void)) {
	@try {
		tryBlock();
	}
	@catch (NSException *exception) {
		return exception;
	}
	return nil;
}

@interface NSString(extra)
- (NSString* _Nonnull)sha1Hash;
@end
