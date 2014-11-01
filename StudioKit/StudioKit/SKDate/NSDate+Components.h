//
//  NSDate+Components.h
//  NewsAppDemo
//
//  Created by Mehul Bhavani on 19/03/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (Components)

+(id) dateFromComponentsDay:(NSInteger)day month:(NSInteger)month year:(NSInteger)year;

-(NSInteger) yearComponent;
-(NSInteger) monthComponent;
-(NSInteger) dayComponent;
-(NSInteger) hourComponent;
-(NSInteger) minuteComponent;
-(NSInteger) secondComponent;
-(NSInteger) weekdayComponent;
-(NSDate *) dateComponent;
-(NSDictionary *) allComponents;

@end
