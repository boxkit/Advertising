//
//  SJMBannerAdView.h
//  SJMAdSDK
//
//  Created by Rare on 2021/1/23.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol SJMBannerAdViewDelegate;
@interface SJMBannerAdView : UIView

@property(nonatomic,copy,readonly) NSString *placementId;

@property (nonatomic,readonly)CGSize adSize;
//interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
@property (nonatomic,readonly)NSInteger interval;

@property (nonatomic, weak, nullable) id<SJMBannerAdViewDelegate> delegate;

/**
   @params
   placementId - 广告位id
   viewController - 视图控制器
   adSize 展示的位置和大小
   interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize
                           interval:(NSInteger)interval;

/**
   @params
   placementId - 广告位id
   viewController - 视图控制器
   adSize 展示的位置和大小
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize;



@property (nonatomic,weak)UIViewController *viewController;

- (void)loadAdAndShow;

@end



@protocol SJMBannerAdViewDelegate <NSObject>
@optional
/**
 banner广告加载成功
 */
- (void)SJM_bannerAdViewDidLoad:(SJMBannerAdView *)bannerAdView;

/**
 banner广告加载失败
 */
- (void)SJM_bannerAdView:(SJMBannerAdView *)bannerAdView didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)SJM_bannerAdViewWillBecomVisible:(SJMBannerAdView *)bannerAdView;

/**
 关闭banner广告回调
 */
- (void)SJM_bannerAdViewDislike:(SJMBannerAdView *)bannerAdView;

/**
 点击banner广告回调
 */
- (void)SJM_bannerAdViewDidClick:(SJMBannerAdView *)bannerAdView;

/**
 关闭banner广告详情页回调
 */
- (void)SJM_bannerAdViewDidCloseOtherController:(SJMBannerAdView *)bannerAdView;

@end

NS_ASSUME_NONNULL_END
