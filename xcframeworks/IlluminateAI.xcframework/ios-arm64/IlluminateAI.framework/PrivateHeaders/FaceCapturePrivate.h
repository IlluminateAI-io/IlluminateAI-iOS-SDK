//
//  FaceCapturePrivate.h
//  RingoAI
//

#import <IlluminateAI/FaceCapture.h>

typedef NSDictionary<NSString*,NSObject*> NSJSON;

@interface FaceCapture(Private)
- (void)callComplete:(BOOL)success;
- (void)callCompleteCancel;
- (void)callResults:(BOOL)success
			   info:(NSDictionary<NSString*,id>*)info;
- (void)callThermalWarning:(BOOL)abort;
- (void)metadata:(NSDictionary<NSString*,NSObject*>*)meta;
- (void)popUX:(UINavigationController*)navVC animated:(BOOL)animated;
- (void)pop;
// @eng-101
- (void)setNav:(UINavigationController*)nav;

- (void)push:(UIViewController*)vc;

@end

@interface RingoShade ()
- (RingoShade *)initWithJSON:(NSDictionary *)json;
- (NSJSON*)json;
@end
@interface RingoMatch ()
- (RingoMatch *)initWithJSON:(NSArray *)things
				 productName:(NSString *)productName
						grid:(BOOL)grid;
- (NSJSON*)json;
@end
@interface RingoResult ()
- (RingoResult *)initWithJSON:(NSDictionary *)json;
- (NSJSON*)json;
@end

extern BOOL launchedCalled;

#import "PocketSVG.h"
