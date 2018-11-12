//
//  ACTIVE.h
//  HotlineSDK
//
//  Created by Sanjith Kanagavel on 05/10/18.
//  Copyright © 2018 Freshdesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FCSecureStore.h"
#import "FCJWTUtilities.h"
#import "FCRemoteConfig.h"
#import "FCUsers.h"
#import "FCUtilities.h"


#define ACTIVE_EVENT @"com.freshchat.jwt.active_event"
#define JWT_EVENT @"com.freshchat.jwt.event"
#define TOKEN_NOT_SET_EVENT @"com.freshchat.jwt.token_not_set_event"
#define TOKEN_NOT_PROCESSED_EVENT @"com.freshchat.jwt.token_not_processed_event"
#define TOKEN_EXPIRED_EVENT @"com.freshchat.jwt.token_expired_event"
#define TOKEN_INVALID_EVENT @"com.freshchat.jwt.token_invalid_event"

enum JWT_STATE : NSInteger {
    TOKEN_VALID = 1,
    TOKEN_NOT_SET = 2,
    TOKEN_NOT_PROCESSED = 3,
    TOKEN_EXPIRED = 4,
    TOKEN_INVALID = 5
};

enum JWT_UI_STATE {
    LOADING = 1,
    SHOW_ALERT = 2,
    SHOW_CONTENT = 3,
    SHOW_CONTENT_WITH_TIMER = 4,
    NO_CHANGE = 5
};


@interface FCJWTAuthValidator: NSObject

+ (instancetype) sharedInstance;
- (enum JWT_STATE) getDefaultJWTState;
- (void) updateAuthState : (enum JWT_STATE) state;
- (void) resetPrevJWTState;
- (BOOL) canSetStateToNotProcessed;
- (BOOL) canStartLoadingTimer;

-(void) startExpiryTimer;
-(void) stopExpiryTimer;

- (enum JWT_UI_STATE) getUiActionForTokenState: (enum JWT_STATE) apiState;
- (enum JWT_UI_STATE) getUiActionForTransition;

@property (assign, nonatomic) enum JWT_STATE prevState;
@property (nonatomic, strong) NSTimer *expiryTimer;

@end
