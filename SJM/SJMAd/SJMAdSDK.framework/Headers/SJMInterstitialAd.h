//
//  SJMInterstitialAd.h
//  SJMAdSDK
//
//  Created by Rare on 2020/10/16.
//
#import <UIKit/UIKit.h>
#import "SJMAd.h"
NS_ASSUME_NONNULL_BEGIN
@protocol SJMInterstitialAdDelegate;
@interface SJMInterstitialAd : SJMAd

@property(nonatomic,weak) id<SJMInterstitialAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<SJMInterstitialAdDelegate>) delegate;


-(void) loadAd;

-(void)presentAdFromRootViewController:(UIViewController*)  viewController;


@end

@protocol SJMInterstitialAdDelegate <NSObject>
/**
 插屏广告加载成功
 */
- (void) SJM_interstitialAdDidLoad:(SJMInterstitialAd*) ad;

/**
 插屏广告加载失败
 */
- (void) SJM_interstitialAdDidLoadFail:(SJMInterstitialAd*) ad error:(NSError * __nullable)error;

/**
 插屏广告展示成功
 */
- (void) SJM_interstitialAdDidPresentScreen:(SJMInterstitialAd*) ad;

/**
 插屏广告点击
 */
- (void) SJM_interstitialAdDidClick:(SJMInterstitialAd*) ad;

/**
 插屏广告关闭
 */
- (void) SJM_interstitialAdDidClose:(SJMInterstitialAd*) ad;

/**
 插屏广告详情页关闭
 */
- (void) SJM_interstitialAdDetailDidClose:(SJMInterstitialAd*) ad;

/**
 插屏广告其他错误
 */
- (void) SJM_interstitialAdDidFail:(SJMInterstitialAd*) ad error:(NSError * __nullable)error;

@end

NS_ASSUME_NONNULL_END
