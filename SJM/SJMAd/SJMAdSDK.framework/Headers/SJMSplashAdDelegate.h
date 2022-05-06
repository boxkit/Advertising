//
//  SJMSplashAdDelegate.h
//  SJMAdSDK
//
//  Created by Rare on 2020/8/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class SJMSplashAd;
@protocol SJMSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
-(void)SJM_splashAdDidLoad:(SJMSplashAd *)splashAd;

/**
 *  开屏广告成功展示
 */
-(void)SJM_splashAdSuccessPresentScreen:(SJMSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)SJM_splashAdClicked:(SJMSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)SJM_splashAdClosed:(SJMSplashAd *)splashAd;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)SJM_splashAdApplicationWillEnterBackground:(SJMSplashAd *)splashAd;

/**
 * 开屏广告倒记时结束
 */
- (void)SJM_splashAdCountdownEnd:(SJMSplashAd*)splashAd;

/**
 *  开屏广告错误
 */
- (void)SJM_splashAdError:(SJMSplashAd *)splashAd withError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
