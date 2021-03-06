//
//  StudioKit.h
//  StudioKit
//
//  Created by Mehul Bhavani on 05/06/12.
//  Copyright (c) 2012 9P Studio. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SCREEN_BOUNDS [StudioKit currentScreenBoundsDependOnOrientation]

// To String converters
#define IS_IPHONE_5 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#define IS_RETINA ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] && ([UIScreen mainScreen].scale == 2.0))

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define IS_IOS_8_OR_LATER SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")
#define IS_IOS_7_OR_LATER SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")
#define IS_IOS_6_OR_EARLIER SYSTEM_VERSION_LESS_THAN(@"7.0")

// To String converters

#define StringFromInt(int) [[NSNumber numberWithInt:int] stringValue]
#define StringFromFloat(float) [NSString stringWithFormat:@"%d", (int)float];
#define StringFromDouble(double) [NSString stringWithFormat:@"%d", (int)double]

#define DegreesToRadians(x) ((x) * M_PI / 180.0)

#define PAD_L_WIDTH 1024
#define PAD_L_HEIGHT 748
#define PAD_P_WIDTH 768
#define PAD_P_HEIGHT 1004
#define PHONE_L_WIDTH 480
#define PHONE_L_HEIGHT 320
#define PHONE_P_WIDTH 320
#define PHONE_P_HEIGHT 480
#define NAVBAR_HEIGHT 44
#define STATUS_BAR_HEIGHT 20
#define NAVBAR_ITEM_HEIGHT 32

#define KEYPAD_P_HEIGHT 216
#define KEYPAD_L_HEIGHT 162

#define PAD_L_ScrCenter CGPointMake(PAD_L_WIDTH/2, PAD_L_HEIGHT/2)
#define PAD_P_ScrCenter CGPointMake(PAD_P_WIDTH/2, PAD_P_HEIGHT/2)
#define PHONE_L_ScrCenter CGPointMake(PHONE_L_WIDTH/2, PHONE_L_HEIGHT/2)
#define PHONE_P_ScrCenter CGPointMake(PHONE_P_WIDTH/2, PHONE_P_HEIGHT/2)

#define PAD_P_FRAME CGRectMake(0, 0, PAD_P_WIDTH, PAD_P_HEIGHT)
#define PAD_L_FRAME CGRectMake(0, 0, PAD_L_WIDTH, PAD_L_HEIGHT)
#define PHONE_P_FRAME CGRectMake(0, 0, PHONE_P_WIDTH, PHONE_P_HEIGHT)
#define PHONE_L_FRAME CGRectMake(0, 0, PHONE_L_WIDTH, PHONE_L_HEIGHT)

#define V_Pt(x, y) [NSValue valueWithCGPoint:CGPointMake(x, y)]
#define Pt(x, y) CGPoint:CGPointMake(x, y)
#define Dist(Pt1, Pt2) sqrt(pow(fabs(Pt2.x-Pt1.x), 2) + pow(fabs(Pt2.y-Pt1.y), 2))
#define RADIANS(degrees) ((degrees * M_PI)/180.0)

#define RANDOM_INT(min, max) (arc4random()%(max-min)) + min

#define PRINT_METHOD_NAME printf("%s\n", __PRETTY_FUNCTION__)
#define PRINT_METHOD_NAME_WITH(string) printf("%s %s\n", __PRETTY_FUNCTION__, string)
#define PRINT_METHOD_NAME_WITH_CLASS_NAME printf("%s %s\n", __PRETTY_FUNCTION__, [NSStringFromClass([self class]) UTF8String])
#define PRINT_RECT(object) printf("x:%f y:%f w:%f h:%f\n", object.frame.origin.x, object.frame.origin.y, object.frame.size.width, object.frame.size.height)


#define AddShadow(object ,color, x, y, opacity, radius) object.layer.shadowColor=color.CGColor; object.layer.shadowOffset=CGSizeMake(x,y); object.layer.shadowOpacity=opacity; object.layer.shadowRadius=radius; object.layer.shouldRasterize = YES; object.layer.rasterizationScale = [UIScreen mainScreen].scale
#define RemoveShadow(object) object.layer.shadowColor=WHITE_COLOR.CGColor; object.layer.shadowOffset=CGSizeMake(0,0); object.layer.shadowOpacity=0.0; object.layer.shadowRadius=0.0

@interface StudioKit : NSObject

+(NSString *) currentDate;
+(NSString *) currentTime;
+(NSString *) currentMonthYear;
+(NSString *) currentYear;
+(NSString *) currentTimeStamp;
+(NSDate *) dateFromString:(NSString *)dateString format:(NSString *)format;
+(NSString *) stringFromDate:(NSDate *)date format:(NSString *)format;

//+(const char *) getDBPath;

+(NSString *) durationFrom:(NSString *)fromTime to:(NSString *)toTime;

+ (NSDictionary *)durationComponents:(NSTimeInterval)interval;


+(NSString *) generateStringFromArray:(NSArray *)array andAddString:(NSString *)string;
+(NSString *) stringFromArray:(NSArray *)array separator:(NSString *)separator;
+(NSArray *) arrayFromString:(NSString *)string separator:(NSString *)separator;

+(UIImage*)imageWithBorderFromImage:(UIImage*)source context:(CGContextRef) context;

+ (CGRect)currentScreenBoundsDependOnOrientation;

@end

@interface NSDictionary (ToString)
- (NSString *) toString;
@end
@interface NSArray (ToString)
- (NSString *) toString;
@end

