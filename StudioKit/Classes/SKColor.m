//
//  SKColor.m
//  StudioKit
//
//  Created by Mehul Bhavani on 13/04/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import "SKColor.h"
#import "StudioKit.h"

@implementation SKColor

#pragma mark - Color Handlers
+(UIColor *) colorFromHex:(NSString *)hexString
{
    NSString *cleanString = [hexString stringByReplacingOccurrencesOfString:@"#" withString:@""];
    if([cleanString length] == 3) {
        cleanString = [NSString stringWithFormat:@"%@%@%@%@%@%@",
                       [cleanString substringWithRange:NSMakeRange(0, 1)],[cleanString substringWithRange:NSMakeRange(0, 1)],
                       [cleanString substringWithRange:NSMakeRange(1, 1)],[cleanString substringWithRange:NSMakeRange(1, 1)],
                       [cleanString substringWithRange:NSMakeRange(2, 1)],[cleanString substringWithRange:NSMakeRange(2, 1)]];
    }
    if([cleanString length] == 6) {
        cleanString = [cleanString stringByAppendingString:@"ff"];
    }
    
    unsigned int baseValue;
    [[NSScanner scannerWithString:cleanString] scanHexInt:&baseValue];
    
    float red = ((baseValue >> 24) & 0xFF)/255.0f;
    float green = ((baseValue >> 16) & 0xFF)/255.0f;
    float blue = ((baseValue >> 8) & 0xFF)/255.0f;
    float alpha = ((baseValue >> 0) & 0xFF)/255.0f;
    
    return [UIColor colorWithRed:red green:green blue:blue alpha:alpha];
}
+(NSString*) colorToHex:(UIColor*)color
{
    CGColorRef colorref = [color CGColor];
    
    const CGFloat *components = CGColorGetComponents(colorref);
    
    NSString *hexString = @"#";
    int hexValue = 0;
    
    for (int i=0; i<3; i++) {
        if (components[i] == 0) {
            hexString = [NSString stringWithFormat:@"%@00", hexString];
        }else{
            hexValue = 0xFF*components[i];
            hexString = [NSString stringWithFormat:@"%@%x", hexString, hexValue];
        }
    }
    return [hexString uppercaseString];
}
+(UIColor *) generateRandomLightColor
{
    int r = RANDOM_INT(200, 250);
    int g = RANDOM_INT(200, 250);
    int b = RANDOM_INT(200, 250);
    
    return RGB(r, g, b);
}

@end
