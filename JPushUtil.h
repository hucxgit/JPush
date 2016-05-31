//
//  MethodsJpushSdk.h
//  App
//
//  Created by Vocinno Mac Mini 1 on 15/8/6.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface JPushUtil : NSObject{
}
//jpush
+(void)methodsJpushSDKinit:(NSDictionary *)lauchDic;
+ (void)registerDeviceToken:(NSData *)deviceToken;  // 向服务器上报Device Token
+ (void)handleRemoteNotification:(NSDictionary *)
remoteInfo;
 
+ (void)resetBadge;
+(NSString *)registrationID;
@end
