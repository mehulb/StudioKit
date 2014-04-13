//
//  StudioKit.m
//  StudioKit
//
//  Created by Mehul Bhavani on 05/06/12.
//  Copyright (c) 2012 9P Studio. All rights reserved.
//

#import "StudioKit.h"

@implementation StudioKit

+(NSString *)currentDate
{
    NSDate *currDate = [NSDate date];
    NSDateFormatter *currDateFormat = [[NSDateFormatter alloc] init];
    
    [currDateFormat setDateFormat:@"dd.MM.yyyy"];
    return [currDateFormat stringFromDate:currDate];
}
+(NSString *)currentTime
{
    NSDate *currDate = [NSDate date];
    NSDateFormatter *currDateFormat = [[NSDateFormatter alloc] init];

    [currDateFormat setDateFormat:@"HH.mm.ss"];
    return [currDateFormat stringFromDate:currDate];

}
+(NSString *)currentMonthYear
{
    NSDate *currDate = [NSDate date];
    NSDateFormatter *currDateFormat = [[NSDateFormatter alloc] init];
    
    [currDateFormat setDateFormat:@"%.MM.yyyy"];
    return [currDateFormat stringFromDate:currDate];
    
}
+(NSString *)currentYear
{
    NSDate *currDate = [NSDate date];
    NSDateFormatter *currDateFormat = [[NSDateFormatter alloc] init];
    
    [currDateFormat setDateFormat:@".yyyy"];
    return [currDateFormat stringFromDate:currDate];
}
+(NSString *) currentTimeStamp
{
    NSDate *currDate = [NSDate date];
    NSDateFormatter *currDateFormat = [[NSDateFormatter alloc] init];
    
    [currDateFormat setDateFormat:@"HH.mm.ss.SSSS:dd.MM.yyyy"];
    
    return [currDateFormat stringFromDate:currDate];
}

/*
+(const char *) getDBPath
{
    NSArray *dirPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *docsDir = [dirPaths objectAtIndex:0];
    const char *dbpath = [[[NSString alloc] initWithString: [docsDir stringByAppendingPathComponent: WORDS_DB_EXT]] UTF8String];
    
    return dbpath;
}
 */

+(NSString *) durationFrom:(NSString *)fromTime to:(NSString *)toTime
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"HH.mm.ss"];
    
    NSDate *fTime = [formatter dateFromString:fromTime];
    NSDate *tTime = [formatter dateFromString:toTime];
    
    NSDateComponents *durationComponents = [[NSCalendar currentCalendar] components:(NSHourCalendarUnit|NSMinuteCalendarUnit|NSSecondCalendarUnit) fromDate:fTime toDate:tTime options:0];
    
    NSDate *duration = [[NSCalendar currentCalendar] dateFromComponents:durationComponents];
    
    //return [NSString stringWithFormat:@"%d.%d.%d", duration.hour, duration.minute, duration.second];
    return [formatter stringFromDate:duration];
}


#pragma mark - Array = String = Array
+(NSString *) generateStringFromArray:(NSArray *)array andAddString:(NSString *)string
{
    NSString *str = [NSString stringWithFormat:@"%@:\n", [string capitalizedString]];
    //if(array.count == 0)
        //return @"";
    for(NSString *s in array)
        str = [str stringByAppendingString:[NSString stringWithFormat:@">>%@\n", s]]; 
    
    return str;
}
+(NSString *) stringFromArray:(NSArray *)array separator:(NSString *)separator
{
    NSString *str = [[NSString alloc] init];
    for(NSString *s in array)
    {
        str = [str stringByAppendingFormat:@"%@%@",s, separator];
    }
    return str;
}
+(NSArray *) arrayFromString:(NSString *)string separator:(NSString *)separator
{
    NSMutableArray *arr = (NSMutableArray *)[string componentsSeparatedByString:separator];
    for(NSString *s in arr)
    {
        if([s isEqualToString:@""])
            [arr removeObject:s];
    }
    
    return (NSArray *)arr;
}

#pragma mark - Date = String = Date
+(NSDate *) dateFromString:(NSString *)dateString format:(NSString *)format
{
    if([dateString isEqualToString:@"null"])
        return nil;
    return [NSDate dateWithTimeIntervalSince1970:[dateString doubleValue]];
}
+(NSString *) stringFromDate:(NSDate *)date format:(NSString *)format
{
    if(!date)
        return @"null";
    return [NSString stringWithFormat:@"%f", [date timeIntervalSince1970]];
}

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
+ (UIImage*)imageWithBorderFromImage:(UIImage*)source context:(CGContextRef) context;
{
    CGSize size = [source size];
    UIGraphicsBeginImageContext(size);
    CGRect rect = CGRectMake(0, 0, size.width, size.height);
    [source drawInRect:rect blendMode:kCGBlendModeLuminosity alpha:1.0];
    
    //CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetLineWidth(context, 8);
    CGContextSetRGBStrokeColor(context, 0.0, 1.0, 1.0, 1.0);
    CGContextStrokeRect(context, rect);
    UIImage *testImg =  UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return testImg;
}


@end
