//
//  SJMSplashAdAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2020/12/22.
//

#import <Foundation/Foundation.h>
#import "SJMAdBaseAdapter.h"
#import "SJMSplashAdProtocol.h"
#import "SJMAdItemConfig.h"
NS_ASSUME_NONNULL_BEGIN

@class SJMSplashAdAdapter;
@protocol SJMSplashAdAdapterDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
-(void)SJM_splashAdAdapterDidLoad:(SJMSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告成功展示
 */
-(void)SJM_splashAdAdapterSuccessPresentScreen:(SJMSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告点击回调
 */
- (void)SJM_splashAdAdapterClicked:(SJMSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告关闭回调
 */
- (void)SJM_splashAdAdapterClosed:(SJMSplashAdAdapter *)splashAdAdapter;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)SJM_splashAdAdapterApplicationWillEnterBackground:(SJMSplashAdAdapter *)splashAdAdapter;

/**
 * 开屏广告倒记时结束
 */
- (void)SJM_splashAdAdapterCountdownEnd:(SJMSplashAdAdapter*)splashAdAdapter;

/**
 *  开屏广告错误
 */
- (void)SJM_splashAdAdapterError:(SJMSplashAdAdapter *)splashAdAdapter withError:(NSError *)error;

@end

@interface SJMSplashAdAdapter : SJMAdBaseAdapter<SJMSplashAdProtocol>

@property(nonatomic,assign) bool hasLoadResult;
@property(nonatomic,assign) bool isTimeOut;
@property(nonatomic,weak) id<SJMSplashAdAdapterDelegate> delegate;

@property(nonatomic,strong,readonly)UIView *splashAdapterView;

-(void) loadSettingWith:(id<SJMSplashAdProtocol>) splashAd;

-(void) handleTimeOut;

/**
 *  开屏广告素材加载成功
 */
-(void)SJM_splashAdDidLoad;

/**
 *  开屏广告成功展示
 */
-(void)SJM_splashAdSuccessPresentScreen;

/**
 *  开屏广告点击回调
 */
- (void)SJM_splashAdClicked;

/**
 *  开屏广告关闭回调
 */
- (void)SJM_splashAdClosed;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)SJM_splashAdApplicationWillEnterBackground;

/**
 * 开屏广告倒记时结束
 */
- (void)SJM_splashAdCountdownEnd;

/**
 *  开屏广告错误
 */
- (void)SJM_splashAdErrorWithError:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
