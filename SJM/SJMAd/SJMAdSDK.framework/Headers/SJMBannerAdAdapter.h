//
//  SJMBannerAdAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/1/23.
//

#import "SJMAdBaseAdapter.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@class SJMBannerAdAdapter;
@protocol SJMBannerAdAdapterDelegate <NSObject>
/**
 banner广告加载成功
 */
- (void)SJM_bannerAdAdapterViewDidLoad:(SJMBannerAdAdapter *)bannerAd;

/**
 banner广告加载失败
 */
- (void)SJM_bannerAdAdapterView:(SJMBannerAdAdapter *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)SJM_bannerAdAdapterViewWillBecomVisible:(SJMBannerAdAdapter *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)SJM_bannerAdAdapterViewDislike:(SJMBannerAdAdapter *)bannerAd;

/**
 点击banner广告回调
 */
- (void)SJM_bannerAdAdapterViewDidClick:(SJMBannerAdAdapter *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)SJM_bannerAdAdapterViewDidCloseOtherController:(SJMBannerAdAdapter *)bannerAd;

@end

@interface SJMBannerAdAdapter : SJMAdBaseAdapter
@property(nonatomic,weak) id<SJMBannerAdAdapterDelegate> delegate;
@property (nonatomic,weak)UIView *adView;


@property (nonatomic,readonly)CGSize adSize;
//interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
@property (nonatomic,readonly)NSInteger interval;

@property (nonatomic,weak)UIViewController *viewController;


- (void)loadAdAndShow;


- (instancetype)initWithAdItemConfig:(SJMAdItemConfig *)adItemConfig
                      viewController:(UIViewController *)viewController
                              adSize:(CGSize)adSize;

- (instancetype)initWithAdItemConfig:(SJMAdItemConfig *)adItemConfig
                      viewController:(UIViewController *)viewController
                              adSize:(CGSize)adSize
                            interval:(NSInteger)interval;

/**
 banner广告加载成功
 */
- (void)SJM_bannerAdAdapterViewDidLoad:(SJMBannerAdAdapter *)bannerAd;

/**
 banner广告加载失败
 */
- (void)SJM_bannerAdAdapterView:(SJMBannerAdAdapter *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)SJM_bannerAdAdapterViewWillBecomVisible:(SJMBannerAdAdapter *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)SJM_bannerAdAdapterViewDislike:(SJMBannerAdAdapter *)bannerAd;

/**
 点击banner广告回调
 */
- (void)SJM_bannerAdAdapterViewDidClick:(SJMBannerAdAdapter *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)SJM_bannerAdAdapterViewDidCloseOtherController:(SJMBannerAdAdapter *)bannerAd;


@end

NS_ASSUME_NONNULL_END
