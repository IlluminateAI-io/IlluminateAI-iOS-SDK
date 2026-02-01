//
//  NSDataPlus.h
//
//  Created by Roy Lovejoy on 6/10/12.
//  Copyright (c) 2012 Amalgamated Coders Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData(Plus)

- (NSString*)utf8String;
- (NSString*)sha1Hash;

@end
