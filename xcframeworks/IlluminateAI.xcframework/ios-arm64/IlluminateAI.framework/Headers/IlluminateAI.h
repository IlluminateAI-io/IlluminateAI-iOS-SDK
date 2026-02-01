//
//  RingoAI.h
//  RingoAI
//
//  Created by roy on 12/23/23.
//
#import <Foundation/Foundation.h>

//! Project version number for RingoAI.
FOUNDATION_EXPORT double RingoAIVersionNumber;

//! Project version string for RingoAI.
FOUNDATION_EXPORT const unsigned char RingoAIVersionString[];

#import <IlluminateAI/FaceCapture.h>
#import <IlluminateAI/objc.h>

extern NSString* _Nonnull kRingoNameKey;
extern NSString* _Nonnull kRingoConditionKey;

typedef NS_ENUM(NSInteger, BrightnessMode) {
  BrightnessModeAutomatic = 0,
  BrightnessModeManual = 1,
  BrightnessModeHybrid = 2,
};
typedef NS_ENUM(NSInteger, RingoErrors) {
	noMatchHistory = 700,
	staleMatchHistory = 701
};

@interface RingoAI : NSObject

@property (class, strong) NSString* _Nullable location;

+ (NSDictionary<NSString*, NSString*>* _Nullable)preflightRequirements;	// everything's OK if returns nil
+ (void)appLaunched:(BrightnessMode)mode;

+ (NSString* _Nullable)currentBrandUX;
+ (NSString* _Nullable)currentBrand;

+ (UIImage* _Nullable)imageFor:(NSString* _Nonnull)familyId shadeId:(NSString* _Nonnull)shadeId;
+ (NSDictionary* _Nullable)metaFor:(NSString* _Nonnull)product;

+ (BOOL)hasHistory;
+ (NSArray<RingoResult*>* _Nullable)history;
+ (void)deleteHistory;
+ (RingoResult* _Nullable)pastMatch:(NSString* _Nonnull)familyID;


+ (NSArray<NSString*>* _Nonnull)locationNames;
+ (NSString* _Nullable)locationForGPS:(CLLocationCoordinate2D)gps;

+ (RingoMatch* _Nonnull)filterMatch:(RingoMatch* _Nonnull)match;

+ (NSDictionary* _Nonnull)uploadStatus;

+ (BOOL)hasAdminPage;
+ (void)adminButtonPressed:(UIView* _Nullable)sender from:(UIViewController* _Nonnull)vc;
+ (void)resetGPS;
+ (void)checkLowPower;

@end

