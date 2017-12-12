//
//  FDUtilities.h
//  FreshdeskSDK
//
//  Created by balaji on 15/05/14.
//  Copyright (c) 2014 Freshdesk. All rights reserved.
//

#ifndef FreshdeskSDK_FDUtilities_h
#define FreshdeskSDK_FDUtilities_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FDStringUtil.h"
#import "Freshchat.h"

@interface FreshchatUser()
    @property (nonatomic) BOOL isRestoring;
    @property (strong, nonatomic, readwrite) NSString *externalID;
    @property (strong, nonatomic, readwrite) NSString *restoreID;
@end


@interface FDUtilities : NSObject

+(NSString *)currentUserAlias;
+(void) removeUUIDWithAppID:(NSString *)appID;
+(void) removeUUID;
+(void) resetAlias;
+(NSString *)getUserAliasWithCreate;
+(NSString *)generateUserAlias;
+(void) resetDataAndRestoreWithExternalID: (NSString *) externalID withRestoreID: (NSString *)restoreID withCompletion:(void (^)())completion;
+ (void) resetNavigationStackWithController:(UIViewController *)controller currentController:(UIViewController *)currentController;

+(UIImage *)imageWithColor:(UIColor *)color;
+(NSString *) getKeyForObject:(NSObject *) object;
+(NSString *)getAdID;
+(NSString *)generateOfflineMessageAlias;
+(NSDictionary *)deviceInfoProperties;
+(void)setActivityIndicator:(BOOL)isVisible;
+(UIViewController*) topMostController;

+(void) AlertView:(NSString *)alertviewstring FromModule:(NSString *)pModule;
+ (BOOL) isPoweredByFooterViewHidden;
+(NSNumber *)getLastUpdatedTimeForKey:(NSString *)key;
+(NSString *)appName;
+(NSString*)deviceModelName;
+(NSString *) getTracker;
+(NSString *) returnLibraryPathForDir : (NSString *) directory;
+(NSDictionary*) filterValidUserPropEntries :(NSDictionary*) userDict;
+(NSArray *) convertTagsArrayToLowerCase : (NSArray *)tags;
+ (BOOL) isIPhoneXView;
+(BOOL)isiOS10;

+ (void)initiatePendingTasks;
+ (BOOL)hasInitConfig;
+ (void)unreadCountInternalHandler:(void (^)(NSInteger count))completion;
+ (void) showAlertViewWithTitle : (NSString *)title message : (NSString *)message andCancelText : (NSString *) cancelText;
+ (BOOL) containsHTMLContent: (NSString *)content;
+ (BOOL) containsString: (NSString *)original andTarget:(NSString *)target;
+ (BOOL) canMakeSessionCall;
+ (BOOL) canMakeDAUCall;
+ (BOOL) canMakeRemoteConfigCall;
+ (BOOL) canMakeTypicallyRepliesCall;
+ (NSString *) typicalRepliesMsgForTime :(NSInteger)timeInSec;
+ (void) updateUserWithExternalID: (NSString *) externalID withRestoreID: (NSString *)restoreID;
+ (void)postUnreadCountNotification;
+ (void) updateUserWithData : (NSDictionary*) userDict;
+ (void) updateUserAlias: (NSString *) userAlias;
+ (NSString *) appendFirstName :(NSString *)firstName withLastName:(NSString *) lastName;
+ (UIColor *) invertColor :(UIColor *)color;

@end

#endif
