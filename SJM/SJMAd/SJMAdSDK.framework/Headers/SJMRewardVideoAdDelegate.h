//
//  SJMRewardAdDelegate.h
//  SJMAdSDK
//
//  Created by Rare on 2020/9/14.
//

#import <Foundation/Foundation.h>
@class  SJMRewardVideoAd;
NS_ASSUME_NONNULL_BEGIN

@protocol SJMRewardVideoAdDelegate <NSObject>

@optional
/**
广告数据加载成功回调

@param rewardedVideoAd SJMRewardVideoAd 实例
*/
- (void)SJM_rewardVideoAdDidLoad:(SJMRewardVideoAd *)rewardedVideoAd;
/**
视频数据下载成功回调，已经下载过的视频会直接回调

@param rewardedVideoAd SJMRewardVideoAd 实例
*/
- (void)SJM_rewardVideoAdVideoDidLoad:(SJMRewardVideoAd *)rewardedVideoAd;

/**
 视频广告展示

 @param rewardedVideoAd SJMRewardVideoAd 实例
 */
- (void)SJM_rewardVideoAdDidShow:(SJMRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭

 @param rewardedVideoAd SJMRewardVideoAd 实例
 */
- (void)SJM_rewardVideoAdDidClose:(SJMRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击

 @param rewardedVideoAd SJMRewardVideoAd 实例
 */
- (void)SJM_rewardVideoAdDidClicked:(SJMRewardVideoAd *)rewardedVideoAd;


//奖励触发
- (void)SJM_rewardVideoAdDidRewardEffective:(SJMRewardVideoAd *)rewardedVideoAd;
/**
 视频广告视频播放完成

 @param rewardedVideoAd SJMRewardVideoAd 实例
 */
- (void)SJM_rewardVideoAdDidPlayFinish:(SJMRewardVideoAd *)rewardedVideoAd;


/**
 视频广告各种错误信息回调

 @param rewardedVideoAd SJMRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)SJM_rewardVideoAd:(SJMRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
