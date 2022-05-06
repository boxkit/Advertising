//
//  SJMFullScreenVideoAd.h
//  SJMAdSDK
//
//  Created by Rare on 2021/4/27.
//

#import "SJMAd.h"
#import "SJMAdSDKDefine.h"

NS_ASSUME_NONNULL_BEGIN
@protocol SJMFullScreenVideoAdDelegate;
@interface SJMFullScreenVideoAd : SJMAd

@property(nonatomic,weak) id<SJMFullScreenVideoAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<SJMFullScreenVideoAdDelegate>) delegate;

-(void) loadAd;

-(void)presentFullScreenVideoAdFromRootViewController:(UIViewController*)viewController;


@end


@protocol SJMFullScreenVideoAdDelegate <NSObject>

/**
广告加载成功
*/
- (void) SJM_fullScreenVideoAdDidLoad:(SJMFullScreenVideoAd*) ad;

/**
 广告加载失败
 */
- (void) SJM_fullScreenVideoAdDidLoadFail:(SJMFullScreenVideoAd*) ad error:(NSError * __nullable)error;

 /**
  广告展示
  */
- (void) SJM_fullScreenVideoAdDidShow:(SJMFullScreenVideoAd*) ad;
  
 /**
  广告点击
  */
- (void) SJM_fullScreenVideoAdDidClick:(SJMFullScreenVideoAd*) ad;

 /**
  广告关闭
  */
- (void) SJM_fullScreenVideoAdDidClose:(SJMFullScreenVideoAd*) ad;

 /**
  广告错误
  */
- (void) SJM_fullScreenVideoAdDidFail:(SJMFullScreenVideoAd*) ad error:(NSError * __nullable)error;

 /**
  广告播放状态回调
  */
- (void)SJM_fullScreenVideoAd:(SJMFullScreenVideoAd*)ad  playerStatusChanged:(SJMMediaPlayerStatus)playerStatus;

 /**
  广告详情页打开
  */
- (void)SJM_fullScreenVideoAdDetailDidPresent:(SJMFullScreenVideoAd*)ad;

 /**
  广告详情页关闭
  */
- (void) SJM_fullScreenVideoAdDetailDidClose:(SJMFullScreenVideoAd*) ad;

@end

NS_ASSUME_NONNULL_END
