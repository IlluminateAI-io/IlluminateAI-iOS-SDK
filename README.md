# IlluminateAI_SDK

### Build 2026.02.18

* built with xcode 26
* new FindMyShade functions
	+ (BOOL)hasHistory;
	+ (NSArray\<RingoResult\*\>\* _Nullable)history;
	+ (void)deleteHistory;
	+ (RingoResult\* _Nullable)pastMatch:(NSString\* _Nonnull)familyID;
* new FaceCapture functions
	- (NSString* _Nullable)familyIDfromProduct:(NSString*_Nonnull)product;
	- (NSString* _Nullable)productFromFamilyID:(NSString*_Nonnull)familyID;
