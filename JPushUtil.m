//
//  MethodsJpushSdk.m
//  App
//
//  Created by Vocinno Mac Mini 1 on 15/8/6.
//
//

#import "JPushUtil.h"
#import "APService.h"

@implementation JPushUtil{
}

 
//jpush
+(void)methodsJpushSDKinit:(NSDictionary *)launchOptions{
    // Required
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0) {
        //可以添加自定义categories
        [APService registerForRemoteNotificationTypes:(UIUserNotificationTypeBadge |
                                                       UIUserNotificationTypeSound |
                                                       UIUserNotificationTypeAlert)
                                           categories:nil];
    } else {
        //categories 必须为nil
        [APService registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge |
                                                       UIRemoteNotificationTypeSound |
                                                       UIRemoteNotificationTypeAlert)
                                           categories:nil];
    }
    
    // Required
    [APService setupWithOption:launchOptions];

}

// 向服务器上报Device Token
+ (void)registerDeviceToken:(NSData *)deviceToken{
    [APService registerDeviceToken:deviceToken];
}
// 处理收到的APNS消息，向服务器上报收到APNS消息
+ (void)handleRemoteNotification:(NSDictionary *)
remoteInfo{
    [APService handleRemoteNotification:remoteInfo];
}
+ (void)resetBadge{
    [APService resetBadge];
}
+(NSString *)registrationID{
    return [APService registrationID];
}
@end
