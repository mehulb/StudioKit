//
//  UIButton+Blocks.h
//  WordChain
//
//  Created by Mehul Bhavani on 03/01/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#define kUIButtonBlockTouchUpInside @"TouchInside"

#import <UIKit/UIKit.h>

@interface UIButton (Blocks)

@property (nonatomic, strong) NSMutableDictionary *actions;

- (void) setAction:(NSString*)action withBlock:(void(^)())block;

@end
