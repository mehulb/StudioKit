//
//  SKColor.h
//  StudioKit
//
//  Created by Mehul Bhavani on 13/04/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import <Foundation/Foundation.h>

//UIColors
#define BLACK_COLOR [UIColor blackColor]
#define DARK_GRAY_COLOR [UIColor darkGrayColor]
#define LIGHT_GRAY_COLOR [UIColor lightGrayColor]
#define WHITE_COLOR [UIColor whiteColor]
#define GRAY_COLOR [UIColor grayColor]
#define RED_COLOR [UIColor redColor]
#define GREEN_COLOR [UIColor greenColor]
#define BLUE_COLOR [UIColor blueColor]
#define CYAN_COLOR [UIColor cyanColor]
#define YELLOW_COLOR [UIColor yellowColor]
#define MAGENTA_COLOR [UIColor magentaColor]
#define ORANGE_COLOR [UIColor orangeColor]
#define PURPLE_COLOR [UIColor purpleColor]
#define BROWN_COLOR [UIColor brownColor]
#define CLEAR_COLOR [UIColor clearColor]
#define LIGHT_TEXT_COLOR [UIColor lightTextColor]
#define DARK_TEXT_COLOR [UIColor darkTextColor]
#define GROUP_TABLEVIEW_BACKGROUND [UIColor groupTableViewBackgroundColor] __depricated
#define VIEW_FLIPSIDE_BACKGROUND [UIColor viewFlipsideBackgroundColor] ____depricated
#define SCROLLVIEW_TEXTURED_BACKGROUND [UIColor scrollViewTexturedBackgroundColor] __depricated
#define UNDER_PAGE_BACKGROUND [UIColor underPageBackgroundColor] __depricated

#define RGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGB(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define RGBHex(hexCode) [StudioKit colorFromHex:hexCode]

@interface SKColor : NSObject

+(UIColor *) colorFromHex:(NSString *)hexString;
+(NSString*) colorToHex:(UIColor*)color;

+(UIColor *) generateRandomLightColor;

@end
