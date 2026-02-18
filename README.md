# IlluminateAI_SDK

### Build 2026.02.16

* built with xcode 26
* new FindMyShade functions
	+ (BOOL)hasHistory;
	+ (NSArray\<RingoResult\*\>\* _Nullable)history;
	+ (void)deleteHistory;
	+ (RingoResult\* _Nullable)pastMatch:(NSString\* _Nonnull)familyID;
	+ (NSArray\<NSString\*\>  \* _Nonnull)supportedProducts;
	+ (NSArray\<NSString\*\>  \* _Nonnull)supportedFamilyIDs;
