//
//  RingoAIPrivate.h
//  RingoAI
//
//  Created by roy on 5/29/24.
//

#ifndef RingoAIPrivate_h
#define RingoAIPrivate_h

#import <IlluminateAI/GyroHelper.h>
#import <IlluminateAI/Goodies.h>
#import <IlluminateAI/NSAttributedStringPlus.h>
#import <IlluminateAI/UIColorPlus.h>
#import <IlluminateAI/CPPUtilsWrapper.h>
#import <IlluminateAI/BayerConverter.h>
#import <IlluminateAI/NSDataPlus.h>
#import <IlluminateAI/FaceCapturePrivate.h>
#import <IlluminateAI/IteratePoly.h>
#import <IlluminateAISupport/IlluminateAISupport.h>

extern BOOL preflightCalled;
extern BOOL appLaunchedCalled;
extern NSDictionary* _Nullable cachedPreflight;

extern NSBundle* _Nonnull fwBundle;
extern NSNotificationName _Nonnull fcRequestInstructions;

typedef NS_ENUM(NSInteger, MatchHow) {
	MostRecent = 0,
	MostFrequent = 1,
};


@interface FindMyShade(Private)
+ (void)upateCPPsettings;	// bridging c++ / swift
+ (NSArray<RingoResult*>* _Nullable)complete;
+ (NSArray<RingoResult*>* _Nullable)rawHistory;
+ (NSArray<RingoResult*>* _Nullable)rawHistory:(BOOL)all;
+ (NSArray<RingoResult*>* _Nullable)rawHistory:(BOOL)all count:(size_t)n;
+ (RingoResult* _Nullable)pastMatch:(MatchHow)how
							revised:(BOOL)revised
						   familyID:(NSString* _Nonnull)familyID;

@end

#endif /* RingoAIPrivate_h */
