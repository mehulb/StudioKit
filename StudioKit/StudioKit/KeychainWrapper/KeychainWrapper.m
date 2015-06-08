//
//  KeychainWrapper.m
//  railpass
//
//  Created by Mehul Bhavani on 06/02/14.
//  Copyright (c) 2014 Rail Pass / Synapsys Technosolutions Tech. All rights reserved.
//

#warning "CHANGE THE FOLLOWING CONTSTANTS"
NSString * const kUUIDKeychainKey = @"com.company-name.app-name.uuid";
NSString * const kIDFAKeychainKey = @"com.company-name.app-name.idfa";
NSString * const kIDFVKeychainKey = @"com.company-name.app-name.idfv";
NSString * const kMacAddressKeychainKey = @"com.company-name.app-name.macaddress";
NSString * const kKeychainService = @"com.company-name.app-name.keychainservice";

#import "KeychainWrapper.h"

@implementation KeychainWrapper

#pragma mark - KeyChain Handlers
+ (NSMutableDictionary *)newSearchDictionary:(NSString *)identifier
{
    NSMutableDictionary *searchDictionary = [[NSMutableDictionary alloc] init];
    
    [searchDictionary setObject:(__bridge id)kSecClassGenericPassword forKey:(__bridge id)kSecClass];
    
    NSData *encodedIdentifier = [identifier dataUsingEncoding:NSUTF8StringEncoding];
    [searchDictionary setObject:encodedIdentifier forKey:(__bridge id)kSecAttrGeneric];
    [searchDictionary setObject:encodedIdentifier forKey:(__bridge id)kSecAttrAccount];
    [searchDictionary setObject:kKeychainService forKey:(__bridge id)kSecAttrService];
    
    return searchDictionary;
}

+ (NSData *)searchKeychainCopyMatching:(NSString *)identifier
{
    NSMutableDictionary *searchDictionary = [self newSearchDictionary:identifier];
    
    // Add search attributes
    [searchDictionary setObject:(__bridge id)kSecMatchLimitOne forKey:(__bridge id)kSecMatchLimit];
    
    // Add search return types
    [searchDictionary setObject:(id)kCFBooleanTrue forKey:(__bridge id)kSecReturnData];
    
    NSData *result = nil;
    CFTypeRef resultRef = nil;
    OSStatus status;
    status = SecItemCopyMatching((__bridge CFDictionaryRef)searchDictionary, &resultRef);
    if (status != errSecSuccess)
    {
        NSLog(@"Keychain SEARCH Err %zd", status);
    }
    CFDataRef resultCFData = (CFDataRef)resultRef;
    result = (__bridge NSData *)resultCFData;
    
    //[searchDictionary release];
    return result;
}

+(NSString *)keychainStringFromMatchingIdentifier:(NSString *)identifier
{
    NSData *valueData = [self searchKeychainCopyMatching:identifier];
    if (valueData) {
        NSString *value = [[NSString alloc] initWithData:valueData
                                                encoding:NSUTF8StringEncoding];
        return value;
    } else {
        return nil;
    }
}

+ (BOOL)createKeychainValue:(NSString *)password forIdentifier:(NSString *)identifier
{
    NSMutableDictionary *dictionary = [self newSearchDictionary:identifier];
    
    NSData *passwordData = [password dataUsingEncoding:NSUTF8StringEncoding];
    [dictionary setObject:passwordData forKey:(__bridge id)kSecValueData];
    
    OSStatus status = SecItemAdd((__bridge CFDictionaryRef)dictionary, NULL);
    
    
    if (status == errSecSuccess) {
        NSLog(@"keychain created");
        return YES;
    }
    //NSLog(@"CREATE %ld", status);
    return NO;
}
+ (BOOL)updateKeychainValue:(NSString *)password forIdentifier:(NSString *)identifier
{
    
    NSMutableDictionary *searchDictionary = [self newSearchDictionary:identifier];
    NSMutableDictionary *updateDictionary = [[NSMutableDictionary alloc] init];
    NSData *passwordData = [password dataUsingEncoding:NSUTF8StringEncoding];
    [updateDictionary setObject:passwordData forKey:(__bridge id)kSecValueData];
    
    OSStatus status = SecItemUpdate((__bridge CFDictionaryRef)searchDictionary,
                                    (__bridge CFDictionaryRef)updateDictionary);
    
    
    if (status == errSecSuccess) {
        NSLog(@"keychain updated");
        return YES;
    }
    //NSLog(@"UPDATE %ld", status);
    return NO;
}
+ (BOOL)deleteKeychainValue:(NSString *)identifier
{
    NSMutableDictionary *searchDictionary = [self newSearchDictionary:identifier];
    OSStatus status = SecItemDelete((__bridge CFDictionaryRef)searchDictionary);
    //NSLog(@"DELETE %ld", status);
    if (status == errSecSuccess) {
        NSLog(@"keychain deleted");
        return YES;
    }
    return NO;
}

@end
