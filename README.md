# IlluminateAI_SDK

### Build 2026.02.01

* built with xcode 26
* analytics bug fixes
* new RingoAI functions
	+ (BOOL)hasHistory;
	+ (NSArray<RingoResult*>* _Nullable)history;
	+ (void)deleteHistory;
	+ (RingoResult* _Nullable)pastMatch:(NSString* _Nonnull)familyID;
