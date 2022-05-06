//
//  SJMFeedVideoProviderAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/1/14.
//

#import "SJMAdBaseAdapter.h"
#import "SJMFeedVideoAdAdapterView.h"
#import "SJMFeedVideoView.h"
#import "SJMAdSDKDefine.h"
NS_ASSUME_NONNULL_BEGIN

@class SJMFeedVideoProviderAdapter,SJMFeedVideoView;

@protocol SJMFeedVideoProviderAdapterDelegate <NSObject>

/**
 * 广告加载成功
 */
- (void)SJM_feedFullVideoProviderAdapterLoadSuccess:(SJMFeedVideoProviderAdapter *)adapter views:(NSArray<__kindof SJMFeedVideoView *> *)views;

/**
* 广告加载失败
*/
- (void)SJM_feedFullVideoProviderAdapterLoadFail:(SJMFeedVideoProviderAdapter *)adapter error:(NSError *_Nullable)error;

/**
 * 广告渲染成功, SJMFeedVideoView.size.height has been updated
 */
- (void)SJM_feedFullVideoAdViewRenderSuccess:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView;

/**
 * 广告渲染失败
 */
- (void)SJM_feedFullVideoAdViewRenderFail:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView error:(NSError *_Nullable)error;

/**
 * 广告曝光回调
 */
- (void)SJM_feedFullVideoAdViewWillShow:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView;

/**
视频广告播放状态更改回调
*/
- (void)SJM_feedFullVideoAdViewStateDidChanged:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView state:(SJMMediaPlayerStatus)playerState;

- (void)SJM_feedFullVideoAdViewPlayerDidPlayFinish:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView;

/**
 * 广告点击回调
 */
- (void)SJM_feedFullVideoAdViewDidClick:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView;

/**
* 广告详情页面即将展示回调
*/
- (void)SJM_feedFullVideoAdViewDetailViewWillPresentScreen:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView;

/**
 *广告详情页关闭回调
 */
- (void)SJM_feedFullVideoAdViewDetailViewClosed:(SJMFeedVideoProviderAdapter *)adapter view:(SJMFeedVideoView*) adView;

@end

@interface SJMFeedVideoProviderAdapter : SJMAdBaseAdapter

@property(nonatomic,weak) id<SJMFeedVideoProviderAdapterDelegate> delegate;

//请求广告尺寸
@property(nonatomic,assign) CGSize adSize;

-(void) loadAd:(NSInteger) count;


- (void)SJM_feedFullVideoProviderAdapterLoadSuccess:(NSArray<__kindof SJMFeedVideoAdAdapterView *> *)views;

- (void)SJM_feedFullVideoProviderAdapterLoadFail:(NSError *_Nullable)error;

// 广告渲染成功, SJMFeedVideoView.size.height has been updated
- (void)SJM_feedFullVideoAdViewRenderSuccess:(SJMFeedVideoAdAdapterView*) adView;

// 广告渲染失败
- (void)SJM_feedFullVideoAdViewRenderFail:(SJMFeedVideoAdAdapterView*) adView error:(NSError *_Nullable)error;

// 广告曝光回调
- (void)SJM_feedFullVideoAdViewWillShow:(SJMFeedVideoAdAdapterView*) adView;

// 视频广告播放状态更改回调  ????
- (void)SJM_feedFullVideoAdViewStateDidChanged:(SJMFeedVideoAdAdapterView*) adView state:(SJMMediaPlayerStatus)playerState;

// 视频广告播放完成
- (void)SJM_feedFullVideoAdViewPlayerDidPlayFinish:(SJMFeedVideoAdAdapterView*) adView;

// 广告点击回调
- (void)SJM_feedFullVideoAdViewDidClick:(SJMFeedVideoAdAdapterView*) adView;

//  广告详情页面即将展示回调
- (void)SJM_feedFullVideoAdViewDetailViewWillPresentScreen:(SJMFeedVideoAdAdapterView*) adView;

// 广告详情页关闭回调
- (void)SJM_feedFullVideoAdViewDetailViewClosed:(SJMFeedVideoAdAdapterView*) adView;
@end

NS_ASSUME_NONNULL_END
