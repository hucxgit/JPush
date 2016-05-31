//
//  README.h
//  JPush
//
//  Created by Vocinno Mac Mini 1 on 15/9/10.
//  Copyright (c) 2015年 VocinnoMacMini. All rights reserved.
//

#ifndef JPush_README_h
#define JPush_README_h
    /*
     1:创建并配置PushConfig.plist文件
     
     在你的工程中创建一个新的Property List文件，并将其命名为PushConfig.plist，填入Portal为你的应用提供的APP_KEY等参数。
     
     {
     "APS_FOR_PRODUCTION" = "0";
     "CHANNEL" = "Publish channel";
     "APP_KEY" = "AppKey copied from JPush Portal application";
     }
     CHANNEL
     指明应用程序包的下载渠道，为方便分渠道统计。根据你的需求自行定义即可。
     APP_KEY
     在管理Portal上创建应用时自动生成的（AppKey）用以标识该应用。请确保应用内配置的 AppKey 与第1步在 Portal 上创建应用时生成的 AppKey 一致，AppKey 可以在应用详情中查询。
     APS_FOR_PRODUCTION
     1.3.1版本新增，表示应用是否采用生产证书发布( Ad_Hoc 或 APP Store )，0 (默认值)表示采用的是开发者证书，1 表示采用生产证书发布应用。
     此处设置的值建议按对应证书来设置值。
     在1.2.2或之前版本的配置文件中，有 TEST_MODE 这个键，新版的SDK不再使用，可以将它删除。
     
     2:在 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions{
       中 add [JPushUtil methodsJpushSDKinit:launchOptions];
     
     3:注册devicetoken 增加下面两个方法
     
     - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
     {
     //5658303674996204209
     NSLog(@"test:%@",deviceToken);
     //[BPush registerDeviceToken:deviceToken];
     // Required
     [APService registerDeviceToken:deviceToken];
     }
     
     // 当 DeviceToken 获取失败时，系统会回调此方法
     - (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
     {
     NSLog(@"DeviceToken 获取失败，原因：%@",error);
     }
     
     4:增加处理通知方法
     
     - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
     {
     
     // // App 收到推送的通知
     // [BPush handleNotification:userInfo];
     // [self handleBaiduMessage:userInfo isPressed:YES];
     
     // Required
     [APService handleRemoteNotification:userInfo];
     }
     
     - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
     
     //    // App 收到推送的通知
     //    [BPush handleNotification:userInfo];
     //    [self handleBaiduMessage:userInfo isPressed:NO];
     //    completionHandler(UIBackgroundFetchResultNewData);
     
     // IOS 7 Support Required
     [APService handleRemoteNotification:userInfo];
     completionHandler(UIBackgroundFetchResultNewData);
     }

     
     5:Background Modes
        选中 Remote notifications
     
     */

    

#endif
