//
//  MBNavigationController.m
//  cloudnine
//
//  Created by Mehul Bhavani on 22/08/14.
//  Copyright (c) 2014 PocketMedi Inc. All rights reserved.
//

#import "MBNavigationController.h"

@interface MBNavigationController ()

@end

@implementation MBNavigationController

- (id)init
{
    self = [super init];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)loadView
{
    [super loadView];
    
    //UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(0, 44, SCREEN_BOUNDS.size.width, 1)];
    //lineView.backgroundColor = ThemeColorPrimaryPink;
    
    //[self.navigationBar addSubview:lineView];
}
- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
