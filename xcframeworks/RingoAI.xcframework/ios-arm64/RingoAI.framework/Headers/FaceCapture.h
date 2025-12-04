//
//  FaceCapture.h
//  RingoAI
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#define RESULT_CLASS 1

#if RESULT_CLASS
typedef struct {
	UInt8 r,g,b;
} RGBColor;

#define RingoAI_userIDKey @"metatag"
#define RingoAI_familyIDKey @"familyID"

@interface RingoShade : NSObject
@property (nonatomic, strong, nonnull)	NSString* 	shade;
@property (nonatomic, strong, nonnull)	NSString* 	shadeId;
@property (nonatomic, strong, nonnull)	NSString* 	shadeDesc;
@property (nonatomic)					RGBColor	color;
@property (nonatomic)					NSInteger	rank;
@property (nonatomic)					BOOL		grid;
@end
typedef NSArray<RingoShade*>*  						RingoShades;

// key:value	Product Name: RingoShade[]
@interface RingoMatch: NSObject
@property (nonatomic, strong, nonnull) 	NSString* 		family;
@property (nonatomic, strong, nonnull) 	NSString* 		familyId;
@property (nonatomic, strong, nonnull) 	NSString* 		familyDesc;
@property (nonatomic, strong, nonnull) 	RingoShades		shades;
@end
typedef NSArray<RingoMatch*>*  							RingoMatches;

@interface RingoResult : NSObject
@property (nonatomic, strong, nonnull) 	NSString* 		userID;			// passed into SDK
@property (nonatomic, strong, nonnull) 	NSString* 		customerID;		// uniquely generated
@property (nonatomic, strong, nonnull) 	NSString* 		osVersion;		// uniquely generated
@property (nonatomic, strong, nonnull) 	RingoMatches 	matches;
@property (nonatomic, strong, nonnull) 	NSString* 		defaultFamily;
@property (nonatomic, strong, nonnull) 	NSString* 		defaultFamilyId;
@property (nonatomic, strong, nonnull) 	NSString* 		sessionId;
@property (nonatomic)					NSUInteger 		timestamp;
@property (nonatomic)					float			L;
@property (nonatomic)					float			minL, maxL;
@property (nonatomic)					float			H;
@property (nonatomic)					float			minH, maxH;
@property (nonatomic, strong, nonnull)	NSError* 		error;
@property (nonatomic, strong, nonnull)	NSString* 		errorMessage;
@property (nonatomic, strong, nonnull)	NSDictionary*	metadata;
@property (nonatomic, strong, nonnull)	id				devInfo;
@end

#else
typedef NSDictionary<NSString*, id> RingoResult;
#endif

@interface RingoProduct: NSObject
@property (nonatomic, strong, nonnull) 	NSString* 		family;
@property (nonatomic, strong, nonnull) 	NSString* 		familyId;
@property (nonatomic, strong, nonnull) 	NSString* 		desc1;
@property (nonatomic, strong, nonnull) 	NSString* 		desc2;
@property (nonatomic, strong, nonnull) 	NSString* 		desc3;

- (RingoProduct*_Nonnull)init:(NSString*_Nonnull)family
					 familyId:(NSString*_Nonnull)familyId
						desc1:(NSString*_Nonnull)desc1
						desc2:(NSString*_Nonnull)desc2
						desc3:(NSString*_Nonnull)desc3;
@end

@protocol FaceCaptureDelegate <NSObject>

@optional

- (void)processingResults:(BOOL)success result:(RingoResult* _Nonnull)result;
- (void)thermalWarningGiven:(BOOL)abort;

@end

@interface FaceCapture : NSObject
@property (nonatomic, weak) id<FaceCaptureDelegate> delegate;

+ (FaceCapture* _Nonnull)shared;

- (NSError* _Nullable)setLicenseKey:(NSString* _Nonnull)key;
- (void)setUserID:(NSString* _Nonnull)userID;

- (void)pushUX:(UINavigationController* _Nonnull)navVC;
- (void)presentOnVC:(UIViewController* _Nonnull)vc;
- (void)pushRestoreInstructions:(UINavigationController* _Nonnull)navVC;
- (void)popToFaceCapture:(UINavigationController* _Nonnull)navVC;
- (void)abort;	// pops back to customer app

- (void)resultsExited;
- (void)cancelProcessingVC:(BOOL)animated;

- (void)override_localizations:(NSDictionary<NSString*,NSString*>* _Nonnull) table;
- (void)override_help:(NSString* _Nonnull)title message:(NSString* _Nonnull)help;
- (void)metadata:(NSDictionary<NSString*,id>*_Nonnull) meta;
- (BOOL)questionnaire:(NSArray<NSNumber* >* _Nonnull) answers
	   verboseAnswers:(NSArray<NSDictionary<NSString *, id>* > *_Nonnull)verbose_answers
		   preAnswers:(NSArray<NSDictionary<NSString *, id>* > *_Nonnull)pre_answers;

- (void)survey:(NSDictionary*_Nonnull)answers sessionID:(NSString*_Nonnull)sessionID;

- (NSArray<NSString*>*_Nonnull)supportedFamilyIDs;
- (NSArray<NSString*>*_Nonnull)supportedFamilies;
- (NSArray<RingoProduct*>*_Nonnull)supportedProducts;
- (NSDictionary<NSString*,NSDictionary*>*_Nonnull)supportedSKUs;
- (NSString*_Nullable)defaultFamilyID;
- (void)setDefaultFamilyID:(NSString*_Nonnull)fid;
@end
