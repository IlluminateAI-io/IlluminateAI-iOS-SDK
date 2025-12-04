//
//  RingoAIPrivate.h
//  RingoAI
//
//  Created by roy on 5/29/24.
//

#ifndef RingoAIPrivate_h
#define RingoAIPrivate_h

#import <RingoAI/GyroHelper.h>
#import <RingoAI/Goodies.h>
#import <RingoAI/NSAttributedStringPlus.h>
#import <RingoAI/UIColorPlus.h>
#import <RingoAI/CPPUtilsWrapper.h>
#import <RingoAI/BayerConverter.h>
#import <RingoAI/NSDataPlus.h>
#import <RingoAI/FaceCapturePrivate.h>
#import <RingoAI/IteratePoly.h>


extern BOOL preflightCalled;
extern BOOL appLaunchedCalled;
extern NSDictionary* _Nullable cachedPreflight;

extern NSBundle* _Nonnull fwBundle;
extern NSNotificationName _Nonnull fcRequestInstructions;
@interface RingoAI(Private)
+ (void)upateCPPsettings;	// bridging c++ / swift
@end

#endif /* RingoAIPrivate_h */
