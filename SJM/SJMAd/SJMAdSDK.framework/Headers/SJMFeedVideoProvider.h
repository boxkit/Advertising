//
//  SJMFeedVideoProvider.h
//  SJMAdSDK
//
//  Created by Rare on 2021/5/9.
//

#import <Foundation/Foundation.h>
#import "SJMAd.h"
#import "SJMAdSDKDefine.h"
#import "SJMFeedVideoView.h"
NS_ASSUME_NONNULL_BEGIN

@protocol SJMFeedVideoProviderDelegate;
@interface SJMFeedVideoProvider : SJMAd

@property(nonatomic,weak) id<SJMFeedVideoProviderDelegate> delegate;

-(instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<SJMFeedVideoProviderDelegate>) delegate;

//广告尺寸
@property(nonatomic,assign) CGSize adSize;

-(void)loadAd:(NSInteger) count;

@end



@protocol SJMFeedVideoProviderDelegate <NSObject>
@optional
/**
 * 广告加载成功
 */
-(void)SJM_feedVideoProviderLoadSuccess:(SJMFeedVideoProvider *)provider views:(NSArray<__kindof SJMFeedVideoView *> *)views;

/**
* 广告加载失败
*/
-(void)SJM_feedVideoProviderLoadFail:(SJMFeedVideoProvider *)provider error:(NSError *_Nullable)error;

/**
 * 广告渲染成功
 */
-(void)SJM_feedVideoAdViewRenderSuccess:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView;

/**
 * 广告渲染失败
 */
-(void)SJM_feedVideoAdViewRenderFail:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView error:(NSError *_Nullable)error;

/**
 * 广告曝光回调
 */
-(void)SJM_feedVideoAdViewWillShow:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView;

/**
视频广告播放状态更改回调
*/
-(void)SJM_feedVideoAdViewStateDidChanged:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView state:(SJMMediaPlayerStatus)playerState;
/**
视频广告播放完毕
*/
-(void)SJM_feedVideoAdViewPlayerDidPlayFinish:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView;

/**
 * 广告点击回调
 */
-(void)SJM_feedVideoAdViewDidClick:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView;

/**
* 广告详情页面即将展示回调
*/
-(void)SJM_feedVideoAdViewDetailViewWillPresentScreen:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView;

/**
 *广告详情页关闭回调
 */
-(void)SJM_feedVideoAdViewDetailViewClosed:(SJMFeedVideoProvider *)provider view:(SJMFeedVideoView*)adView;


@end


NS_ASSUME_NONNULL_END
