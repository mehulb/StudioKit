//
//  DeviceDetails.h
//  wordu
//
//  Created by Mehul Bhavani on 08/03/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceDetails : NSObject

// startup api parameters

+(NSString *) UUIDString;
+(NSString *) IDFAString;
+(NSString *) IDFVString;
+(NSString *) MACString;

+(NSString *) buildNumber;
+(NSString *) buildVersion;
+(NSString *) deviceType;
+(NSString *) deviceBrand;
+(NSString *) deviceName;
+(NSString *) deviceOS;
+(NSString *) deviceOSVersion;
+(NSString *) loginMode;
+(NSString *) machineName;

@end
