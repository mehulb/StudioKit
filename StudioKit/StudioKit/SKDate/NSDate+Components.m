//
//  NSDate+Components.m
//  NewsAppDemo
//
//  Created by Mehul Bhavani on 19/03/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import "NSDate+Components.h"

@implementation NSDate (Components)

+(id) dateFromComponentsDay:(NSInteger)day month:(NSInteger)month year:(NSInteger)year
{
    NSDate *date = [[NSDate alloc] init];
    
    NSCalendar *calender = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    
    NSDateComponents *components = [[NSDateComponents alloc] init];
    components.calendar = calender;
    [components setDay:day];
    [components setMonth:month];
    [components setYear:year];
    [components setHour:0];
    [components setMinute:0];
    [components setSecond:0];
    
    date = [components date];
    
    return date;
}

-(NSInteger)yearComponent
{
    return [[[self allComponents] objectForKey:@"year"] integerValue];
}
-(NSInteger)monthComponent
{
    return [[[self allComponents] objectForKey:@"month"] integerValue];
}
-(NSInteger)dayComponent
{
    return [[[self allComponents] objectForKey:@"day"] integerValue];
}
-(NSInteger)hourComponent
{
    return [[[self allComponents] objectForKey:@"hour"] integerValue];
}
-(NSInteger)minuteComponent
{
    return [[[self allComponents] objectForKey:@"minute"] integerValue];
}
-(NSInteger)secondComponent
{
    return [[[self allComponents] objectForKey:@"second"] integerValue];
}
-(NSInteger)weekdayComponent
{
    return [[[self allComponents] objectForKey:@"weekday"] integerValue];
}
-(NSDate *)dateComponent
{
    return [[self allComponents] objectForKey:@"date"];
}
-(NSDictionary *)allComponents
{
    unsigned int unitFlags = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit | NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit | NSWeekdayCalendarUnit;
    
    NSCalendar *gregorian = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    
    NSDateComponents *components = [gregorian components:unitFlags fromDate:self];
    
    NSDateComponents *components1 = [gregorian components:(NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit) fromDate:self];
    
    return @{
             @"year":[NSNumber numberWithInteger:components.year],
             @"month":[NSNumber numberWithInteger:components.month],
             @"day":[NSNumber numberWithInteger:components.day],
             @"hour":[NSNumber numberWithInteger:components.hour],
             @"minute":[NSNumber numberWithInteger:components.minute],
             @"second":[NSNumber numberWithInteger:components.second],
             @"date":[[NSCalendar currentCalendar] dateFromComponents:components1],
             @"weekday":[NSNumber numberWithInteger:components.weekday]
             };
}

@end
