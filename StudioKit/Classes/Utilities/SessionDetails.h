//
//  SessionDetails.h
//  wordu
//
//  Created by Mehul Bhavani on 08/03/14.
//  Copyright (c) 2014 9P Studio. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SessionDetails : NSObject

+(SessionDetails *) sharedDetails;

@property (nonatomic, assign) NSInteger userId;
@property (nonatomic, retain) NSString *sessionHash;
@property (nonatomic, retain) NSString *sessionTime;
@property (nonatomic, assign) NSInteger sessionSequenceId;
@property (nonatomic, retain) NSString *passBaseUrlString;
@property (nonatomic, retain) NSString *lastSyncedTimestamp;

@end
