//
//  DeviceDetails.m
//  wordu
//
//  Created by Mehul Bhavani on 08/03/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import "DeviceDetails.h"
#import "KeychainWrapper.h"
#import <AdSupport/AdSupport.h>

#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#import <sys/utsname.h>

#define kMacAddress @"kMacAddress"

@implementation DeviceDetails

+(NSString *)UUIDString
{
    NSString *uuid = nil;
    uuid = [KeychainWrapper keychainStringFromMatchingIdentifier:kKeychainKeyUUID];
    if(!uuid)
    {
        uuid = [[NSUUID UUID] UUIDString];
        [KeychainWrapper deleteKeychainValue:kKeychainKeyUUID];
        [KeychainWrapper createKeychainValue:uuid forIdentifier:kKeychainKeyUUID];
    }
    return uuid;
}

+(NSString *)IDFAString
{
    if(YES)
        return @"";
    
    return [UIDevice currentDevice].identifierForVendor.UUIDString;
}

+(NSString *)IDFVString
{
    if(YES)
        return @"";
    
    return [ASIdentifierManager sharedManager].advertisingIdentifier.UUIDString;
}

+(NSString *)MACString
{
    if(YES)
        return @"";
    
    NSString *macAddressString = nil;
    macAddressString = [[NSUserDefaults standardUserDefaults] stringForKey:kMacAddress];
    
    if(macAddressString)
        return macAddressString;
    
    int                 mgmtInfoBase[6];
    char                *msgBuffer = NULL;
    size_t              length;
    unsigned char       macAddress[6];
    struct if_msghdr    *interfaceMsgStruct;
    struct sockaddr_dl  *socketStruct;
    NSString            *errorFlag = NULL;
    
    // Setup the management Information Base (mib)
    mgmtInfoBase[0] = CTL_NET;        // Request network subsystem
    mgmtInfoBase[1] = AF_ROUTE;       // Routing table info
    mgmtInfoBase[2] = 0;
    mgmtInfoBase[3] = AF_LINK;        // Request link layer information
    mgmtInfoBase[4] = NET_RT_IFLIST;  // Request all configured interfaces
    
    // With all configured interfaces requested, get handle index
    if ((mgmtInfoBase[5] = if_nametoindex("en0")) == 0)
        errorFlag = @"if_nametoindex failure";
    else
    {
        // Get the size of the data available (store in len)
        if (sysctl(mgmtInfoBase, 6, NULL, &length, NULL, 0) < 0)
            errorFlag = @"sysctl mgmtInfoBase failure";
        else
        {
            // Alloc memory based on above call
            if ((msgBuffer = malloc(length)) == NULL)
                errorFlag = @"buffer allocation failure";
            else
            {
                // Get system information, store in buffer
                if (sysctl(mgmtInfoBase, 6, msgBuffer, &length, NULL, 0) < 0)
                    errorFlag = @"sysctl msgBuffer failure";
            }
        }
    }
    
    // Befor going any further...
    if (errorFlag != NULL)
    {
        NSLog(@"Error: %@", errorFlag);
        return errorFlag;
    }
    
    // Map msgbuffer to interface message structure
    interfaceMsgStruct = (struct if_msghdr *) msgBuffer;
    
    // Map to link-level socket structure
    socketStruct = (struct sockaddr_dl *) (interfaceMsgStruct + 1);
    
    // Copy link layer address data in socket structure to an array
    memcpy(&macAddress, socketStruct->sdl_data + socketStruct->sdl_nlen, 6);
    
    // Read from char array into a string object, into traditional Mac address format
    macAddressString = [NSString stringWithFormat:@"%02X:%02X:%02X:%02X:%02X:%02X",
                        macAddress[0], macAddress[1], macAddress[2],
                        macAddress[3], macAddress[4], macAddress[5]];
    //NSLog(@"Mac Address: %@", macAddressString);
    
    // Release the buffer memory
    free(msgBuffer);
    
    [[NSUserDefaults standardUserDefaults] setObject:macAddressString forKey:kMacAddress];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    return macAddressString;
}

+(NSString *)deviceType
{
    return @"iphone"; //[[[UIDevice currentDevice] model] lowercaseString];
}

+ (NSString *)buildVersion
{
    return [[NSBundle mainBundle] objectForInfoDictionaryKey: @"CFBundleShortVersionString"];
}
+ (NSString *)buildNumber
{
    return [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"];
}

+(NSString *)deviceBrand
{
    return @"Apple";
}

+(NSString *)deviceName
{
    return [DeviceDetails machineName];
}

+(NSString *)deviceOS
{
    return [UIDevice currentDevice].systemName;
}
+ (NSString *)deviceOSVersion
{
    return [UIDevice currentDevice].systemVersion;
}

+(NSString *)loginMode
{
    return @"device";
}

+ (NSString *)machineName
{
    struct utsname systemInfo;
    uname(&systemInfo);
    
    return [NSString stringWithCString:systemInfo.machine
                              encoding:NSUTF8StringEncoding];
}

@end

