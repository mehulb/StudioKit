//
//  SessionDetails.m
//  wordu
//
//  Created by Mehul Bhavani on 08/03/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import "SessionDetails.h"

#define kUserId @"kUserId"
#define kSessionHash @"kSessionHash"
#define kSessionTime @"kSessionTime"
#define kSessionSequenceId @"kSessionSequenceId"
#define kPassBaseUrlString @"kPassBaseUrlString"
#define kLastSyncedDate @"kLastSyncedDate"

@implementation SessionDetails;

static SessionDetails *staticInstance = nil;

+(SessionDetails *) sharedDetails
{
    if(!staticInstance)
    {
        staticInstance = [[SessionDetails alloc] init];
    }
    return staticInstance;
}

-(NSInteger)userId
{
    NSInteger uid = [[NSUserDefaults standardUserDefaults] integerForKey:kUserId];
    
    return uid;
}

-(void) setUserId:(NSInteger)userId
{
    [[NSUserDefaults standardUserDefaults] setInteger:userId forKey:kUserId];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(NSString *)sessionHash
{
    NSString *hash = nil;
    hash = [[NSUserDefaults standardUserDefaults] stringForKey:kSessionHash];
    
    if(hash)
        return hash;
    
    return (NSString *)[NSNull null];
}

-(void)setSessionHash:(NSString *)sessionHash
{
    [[NSUserDefaults standardUserDefaults] setObject:sessionHash forKey:kSessionHash];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(NSString *)sessionTime
{
    NSString *time = nil;
    time = [[NSUserDefaults standardUserDefaults] stringForKey:kSessionTime];
    
    if(time)
        return time;
    
    return (NSString *)[NSNull null];
}
-(void)setSessionTime:(NSString *)sessionTime
{
    [[NSUserDefaults standardUserDefaults] setObject:sessionTime forKey:kSessionTime];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(NSInteger)sessionSequenceId
{
    NSInteger seqId = [[NSUserDefaults standardUserDefaults] integerForKey:kSessionSequenceId];
    seqId++;
    [self setSessionSequenceId:seqId];
    return seqId;
}

-(void)setSessionSequenceId:(NSInteger)sessionSequenceId
{
    [[NSUserDefaults standardUserDefaults] setInteger:sessionSequenceId forKey:kSessionSequenceId];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)passBaseUrlString
{
    return [[NSUserDefaults standardUserDefaults] stringForKey:kPassBaseUrlString];
}

- (void)setPassBaseUrlString:(NSString *)passBaseUrlString
{
    [[NSUserDefaults standardUserDefaults] setObject:passBaseUrlString forKey:kPassBaseUrlString];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)lastSyncedTimestamp
{
    return [[NSUserDefaults standardUserDefaults] objectForKey:kLastSyncedDate];
}

- (void)setLastSyncedTimestamp:(NSString *)lastSyncedTimestamp
{
    [[NSUserDefaults standardUserDefaults] setObject:lastSyncedTimestamp forKey:kLastSyncedDate];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

@end
