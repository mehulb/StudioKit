//
//  KeychainWrapper.h
//  railpass
//
//  Created by Mehul Bhavani on 06/02/14.
//  Copyright (c) 2014 Rail Pass / Synapsys Technosolutions Tech. All rights reserved.
//

extern NSString * const kUUIDKeychainKey;

#import <Foundation/Foundation.h>

@interface KeychainWrapper : NSObject

+ (NSMutableDictionary *)newSearchDictionary:(NSString *)identifier;
+ (NSData *)searchKeychainCopyMatching:(NSString *)identifier;
+ (NSString *)keychainStringFromMatchingIdentifier:(NSString *)identifier;
+ (BOOL)createKeychainValue:(NSString *)password forIdentifier:(NSString *)identifier;
+ (BOOL)updateKeychainValue:(NSString *)password forIdentifier:(NSString *)identifier;
+ (BOOL)deleteKeychainValue:(NSString *)identifier;

@end
