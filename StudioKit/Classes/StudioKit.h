//
//  StudioKit.h
//  StudioKit
//
//  Created by Mehul Bhavani on 05/06/12.
//  Copyright (c) 2012 9P Studio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Reachability.h"

//#define COINS_IN_USER_DEFAULTS @"userdefaultsCoins" //Key for Coins in App User Defaults
//#define HINTS_IN_USER_DEFAULTS @"userdefaultsCoins" //

// To String converters
#define StringFromInt(int) [[NSNumber numberWithInt:int] stringValue]
#define StringFromFloat(float) [NSString stringWithFormat:@"%d", (int)float];
#define StringFromDouble(double) [NSString stringWithFormat:@"%d", (int)double]

#define DegreesToRadians(x) ((x) * M_PI / 180.0)

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
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
#define RGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGB(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define RGBhex(hexCode) [StudioKit colorFromHex:hexCode]
#define RANDOM_INT(min, max) (arc4random()%(max-min)) + min

#define PRINT_METHOD_NAME printf("%s\n", __PRETTY_FUNCTION__)
#define PRINT_METHOD_NAME_WITH(string) printf("%s %s\n", __PRETTY_FUNCTION__, string)
#define PRINT_METHOD_NAME_WITH_CLASS_NAME printf("%s %s\n", __PRETTY_FUNCTION__, [NSStringFromClass([self class]) UTF8String])
#define PRINT_RECT(object) printf("x:%f y:%f w:%f h:%f\n", object.frame.origin.x, object.frame.origin.y, object.frame.size.width, object.frame.size.height)

#define DEFAULT_IMAGE @"default_border_image.png"
#define ARTICLE_SCROLLER_WIDTH 200
#define ADVIEW_HEIGHT 100

//#define WN_EXT @"wordnet.sqlite"
//#define WN @"wordnet"
//#define WN21_EXT @"wordnet21.sqlite"
//#define WN21 @"wordnet21"
#define FIRST_CHAR(string) [string characterAtIndex:0]
#define LAST_CHAR(string)  [string characterAtIndex:([string length]-1)]  

#define AddShadow(object ,color, x, y, opacity, radius) object.layer.shadowColor=color.CGColor; object.layer.shadowOffset=CGSizeMake(x,y); object.layer.shadowOpacity=opacity; object.layer.shadowRadius=radius; object.layer.shouldRasterize = YES; object.layer.rasterizationScale = [UIScreen mainScreen].scale
#define RemoveShadow(object) object.layer.shadowColor=WHITE_COLOR.CGColor; object.layer.shadowOffset=CGSizeMake(0,0); object.layer.shadowOpacity=0.0; object.layer.shadowRadius=0.0

#define TextAlignLeft() (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) ? NSTextAlignmentLeft : UITextAlignmentLeft
#define TextAlignRight() (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) ? NSTextAlignmentRight : UITextAlignmentRight
#define TextAlignCenter() (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) ? NSTextAlignmentCenter : UITextAlignmentCenter
#define LineBreakModeWordWrap() ((SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) ? NSLineBreakByWordWrapping : UILineBreakModeWordWrap)

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
#define GROUP_TABLEVIEW_BACKGROUND [UIColor groupTableViewBackgroundColor]
#define VIEW_FLIPSIDE_BACKGROUND [UIColor viewFlipsideBackgroundColor]
#define SCROLLVIEW_TEXTURED_BACKGROUND [UIColor scrollViewTexturedBackgroundColor]
#define UNDER_PAGE_BACKGROUND [UIColor underPageBackgroundColor]

// Fonts Supported by IOS
#define AcademyEngravedLetPlain @"AcademyEngravedLetPlain"
#define AmericanTypewriter_CondensedLight @"AmericanTypewriter-CondensedLight"
#define AmericanTypewriter_Light @"AmericanTypewriter-Light"
#define AmericanTypewriter @"AmericanTypewriter"
#define AmericanTypewriter_Condensed @"AmericanTypewriter-Condensed"
#define AmericanTypewriter_Bold @"AmericanTypewriter-Bold"
#define AmericanTypewriter_CondensedBold @"AmericanTypewriter-CondensedBold"
#define AppleColorEmoji @"AppleColorEmoji"
#define AppleSDGothicNeo_Medium @"AppleSDGothicNeo-Medium"
#define AppleSDGothicNeo_Bold @"AppleSDGothicNeo-Bold"
#define ArialMT @"ArialMT"
#define Arial_ItalicMT @"Arial-ItalicMT"
#define Arial_BoldMT @"Arial-BoldMT"
#define Arial_BoldItalicMT @"Arial-BoldItalicMT"
#define ArialHebrew	@"ArialHebrew"
#define ArialHebrew_Bold @"ArialHebrew-Bold"
#define ArialRoundedMTBold	@"ArialRoundedMTBold"
#define BanglaSangamMN_Bold	@"BanglaSangamMN-Bold"
#define BanglaSangamMN @"BanglaSangamMN"
#define Baskerville	@"Baskerville"
#define Baskerville_Italic @"Baskerville-Italic"
#define Baskerville_SemiBold @"Baskerville-SemiBold"
#define Baskerville_SemiBoldItalic @"Baskerville-SemiBoldItalic"
#define Baskerville_Bold @"Baskerville-Bold"
#define Baskerville_BoldItalic @"Baskerville-BoldItalic"
#define BodoniSvtyTwoITCTT_Book	@"BodoniSvtyTwoITCTT-Book"
#define BodoniSvtyTwoITCTT_BookIta	@"BodoniSvtyTwoITCTT-BookIta"
#define BodoniSvtyTwoITCTT_Bold	@"BodoniSvtyTwoITCTT-Bold"
#define BodoniSvtyTwoOSITCTT_Book	@"BodoniSvtyTwoOSITCTT-Book"
#define BodoniSvtyTwoOSITCTT_BookIt	@"BodoniSvtyTwoOSITCTT-BookIt"
#define BodoniSvtyTwoOSITCTT_Bold	@"BodoniSvtyTwoOSITCTT-Bold"
#define BodoniSvtyTwoSCITCTT_Book	@"BodoniSvtyTwoSCITCTT-Book"
#define BradleyHandITCTT_Bold @"BradleyHandITCTT-Bold"
#define ChalkboardSE_Light	@"ChalkboardSE-Light"
#define ChalkboardSE_Regular	@"ChalkboardSE-Regular"
#define ChalkboardSE_Bold	@"ChalkboardSE-Bold"
#define Chalkduster @"Chalkduster"
#define Cochin	@"Cochin"
#define Cochin_Italic	@"Cochin-Italic"
#define Cochin_Bold	@"Cochin-Bold"
#define Cochin_BoldItalic	@"Cochin-BoldItalic"
#define Copperplate_Light	@"Copperplate-Light"
#define Copperplate	@"Copperplate"
#define Copperplate_Bold	@"Copperplate-Bold"
#define Courier	@"Courier"
#define Courier_Oblique	@"Courier-Oblique"
#define Courier_Bold	@"Courier-Bold"
#define Courier_BoldOblique	@"Courier-BoldOblique"
#define CourierNewPSMT	@"CourierNewPSMT"
#define CourierNewPS_BoldMT	@"CourierNewPS-BoldMT"
#define CourierNewPS_BoldItalicMT	@"CourierNewPS-BoldItalicMT"
#define CourierNewPS_ItalicMT	@"CourierNewPS-ItalicMT"
#define DBLCDTempBlack	@"DBLCDTempBlack"
#define DevanagariSangamMN	@"DevanagariSangamMN"
#define DevanagariSangamMN_Bold	@"DevanagariSangamMN-Bold"
#define Didot	@"Didot"
#define Didot_Italic	@"Didot-Italic"
#define Didot_Bold	@"Didot-Bold"
#define EuphemiaUCAS	@"EuphemiaUCAS"
#define EuphemiaUCAS_Italic	@"EuphemiaUCAS-Italic"
#define EuphemiaUCAS_Bold	@"EuphemiaUCAS-Bold"
#define Futura_Medium	@"Futura-Medium"
#define Futura_MediumItalic	@"Futura-MediumItalic"
#define Futura_CondensedMedium	@"Futura-CondensedMedium"
#define Futura_CondensedExtraBold	@"Futura-CondensedExtraBold"
#define GeezaPro	@"GeezaPro"
#define GeezaPro_Bold	@"GeezaPro-Bold"
#define Georgia	@"Georgia"
#define Georgia_Italic	@"Georgia-Italic"
#define Georgia_Bold	@"Georgia-Bold"
#define Georgia_BoldItalic	@"Georgia-BoldItalic"
#define GillSans_Light	@"GillSans-Light"
#define GillSans_LightItalic	@"GillSans-LightItalic"
#define GillSans	@"GillSans"
#define GillSans_Italic	@"GillSans-Italic"
#define GillSans_Bold	@"GillSans-Bold"
#define GillSans_BoldItalic	@"GillSans-BoldItalic"
#define GujaratiSangamMN	@"GujaratiSangamMN"
#define GujaratiSangamMN_Bold	@"GujaratiSangamMN-Bold"
#define GurmukhiMN	@"GurmukhiMN"
#define GurmukhiMN_Bold	@"GurmukhiMN-Bold"
#define STHeitiSC_Light	@"STHeitiSC-Light"
#define STHeitiSC_Medium	@"STHeitiSC-Medium"
#define STHeitiTC_Light	@"STHeitiTC-Light"
#define STHeitiTC_Medium	@"STHeitiTC-Medium"
#define Helvetica_Light	@"Helvetica-Light"
#define Helvetica_LightOblique	@"Helvetica-LightOblique"
#define Helvetica	@"Helvetica"
#define Helvetica_Oblique	@"Helvetica-Oblique"
#define Helvetica_Bold	@"Helvetica-Bold"
#define Helvetica_BoldOblique	@"Helvetica-BoldOblique"
#define HelveticaNeue_UltraLight	@"HelveticaNeue-UltraLight"
#define HelveticaNeue_UltraLightItalic	@"HelveticaNeue-UltraLightItalic"
#define HelveticaNeue_Light	@"HelveticaNeue-Light"
#define HelveticaNeue_LightItalic	@"HelveticaNeue-LightItalic"
#define HelveticaNeue	@"HelveticaNeue"
#define HelveticaNeue_Italic	@"HelveticaNeue-Italic"
#define HelveticaNeue_Medium	@"HelveticaNeue-Medium"
#define HelveticaNeue_Bold	@"HelveticaNeue-Bold"
#define HelveticaNeue_BoldItalic	@"HelveticaNeue-BoldItalic"
#define HelveticaNeue_CondensedBold	@"HelveticaNeue-CondensedBold"
#define HelveticaNeue_CondensedBlack	@"HelveticaNeue-CondensedBlack"
#define HiraKakuProN_W3	@"HiraKakuProN-W3"
#define HiraKakuProN_W6	@"HiraKakuProN-W6"
#define HiraMinProN_W3	@"HiraMinProN-W3"
#define HiraMinProN_W6	@"HiraMinProN-W6"
#define HoeflerText_Regular	@"HoeflerText-Regular"
#define HoeflerText_Italic	@"HoeflerText-Italic"
#define HoeflerText_Black	@"HoeflerText-Black"
#define HoeflerText_BlackItalic	@"HoeflerText-BlackItalic"
#define Kailasa	@"Kailasa"
#define Kailasa_Bold	@"Kailasa-Bold"
#define KannadaSangamMN	@"KannadaSangamMN"
#define KannadaSangamMN_Bold	@"KannadaSangamMN-Bold"
#define MalayalamSangamMN	@"MalayalamSangamMN"
#define MalayalamSangamMN_Bold	@"MalayalamSangamMN-Bold"
#define Marion_Regular	@"Marion-Regular"
#define Marion_Italic	@"Marion-Italic"
#define Marion_Bold	@"Marion-Bold"
#define MarkerFelt_Thin	@"MarkerFelt-Thin"
#define MarkerFelt_Wide	@"MarkerFelt-Wide"
#define Noteworthy_Light	@"Noteworthy-Light"
#define Noteworthy_Bold	@"Noteworthy-Bold"
#define Optima_Italic	@"Optima-Italic"
#define Optima_Regular	@"Optima-Regular"
#define Optima_Bold	@"Optima-Bold"
#define Optima_BoldItalic	@"Optima-BoldItalic"
#define Optima_ExtraBlack	@"Optima-ExtraBlack"
#define OriyaSangamMN	@"OriyaSangamMN"
#define OriyaSangamMN_Bold	@"OriyaSangamMN-Bold"
#define Palatino_Roman	@"Palatino-Roman"
#define Palatino_Italic	@"Palatino-Italic"
#define Palatino_Bold	@"Palatino-Bold"
#define Palatino_BoldItalic	@"Palatino-BoldItalic"
#define Papyrus	@"Papyrus"
#define Papyrus_Condensed	@"Papyrus-Condensed"
#define PartyLetPlain	@"PartyLetPlain"
#define SinhalaSangamMN	@"SinhalaSangamMN"
#define SinhalaSangamMN_Bold	@"SinhalaSangamMN-Bold"
#define SnellRoundhand	@"SnellRoundhand"
#define SnellRoundhand_Bold	@"SnellRoundhand-Bold"
#define SnellRoundhand_Black	@"SnellRoundhand-Black"
#define TamilSangamMN	@"TamilSangamMN"
#define TamilSangamMN_Bold	@"TamilSangamMN-Bold"
#define TeluguSangamMN	@"TeluguSangamMN"
#define TeluguSangamMN_Bold	@"TeluguSangamMN-Bold"
#define Thonburi	@"Thonburi"
#define Thonburi_Bold	@"Thonburi-Bold"
#define TimesNewRomanPSMT	@"TimesNewRomanPSMT"
#define TimesNewRomanPS_ItalicMT	@"TimesNewRomanPS-ItalicMT"
#define TimesNewRomanPS_BoldMT	@"TimesNewRomanPS-BoldMT"
#define TimesNewRomanPS_BoldItalicMT	@"TimesNewRomanPS-BoldItalicMT"
#define TrebuchetMS	@"TrebuchetMS"
#define TrebuchetMS_Italic	@"TrebuchetMS-Italic"
#define TrebuchetMS_Bold	@"TrebuchetMS-Bold"
#define Trebuchet_BoldItalic @"Trebuchet-BoldItalic"
#define Verdana	@"Verdana"
#define Verdana_Italic	@"Verdana-Italic"
#define Verdana_Bold	@"Verdana-Bold"
#define Verdana_BoldItalic	@"Verdana-BoldItalic"
#define ZapfDingbatsITC	@"ZapfDingbatsITC"
#define Zapfino	@"Zapfino"

/*
#define HELVETICA @"Helvetica"
#define HELVETICA_BOLD @"Helvetica-Bold"
#define OPTIMA_REGULAR @"Optima-Regular"
#define OPTIMA_BOLD @"Optima-Bold"
#define TIMESNEWROMAN @"TimesNewRomanPSMT"
#define TIMESNEWROMAN_BOLD @"TimesNewRomanPS-BoldMT"
#define BASKERVILLE_SEMIBOLD @"Baskerville-SemiBold"
#define BASKERVILLE @"Baskerville"
#define GURMUKHI @"GurmukhiMN"
#define GURMUKHI_BOLD @"GurmukhiMN-Bold"
#define GEORGIA @"Georgia"
#define GEORGIA_BOLD @"Georgia-Bold"
 */

#define NULL_TIME @"00.00.00"
#define NULL_STRING @"null"
#define LOGIN @"login"
#define LOGOUT @"logout"

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
+(UIColor *) generateRandomLightColor;

+(NSString *) generateStringFromArray:(NSArray *)array andAddString:(NSString *)string;
+(NSString *) stringFromArray:(NSArray *)array separator:(NSString *)separator;
+(NSArray *) arrayFromString:(NSString *)string separator:(NSString *)separator;

+ (BOOL) checkNetworkStatus;

+(UIColor *) colorFromHex:(NSString *)hexString;
+(NSString*) colorToHex:(UIColor*)color;
+(UIImage*)imageWithBorderFromImage:(UIImage*)source context:(CGContextRef) context;

@end
