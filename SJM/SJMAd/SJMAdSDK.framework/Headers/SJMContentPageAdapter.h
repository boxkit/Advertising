//
//  SJMContentPageAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2020/12/22.
//

#import "SJMAdBaseAdapter.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SJMAdapterContentAdapterVideoStateDelegate,SJMContentAdapterStateDelegate;

@interface SJMContentPageAdapter : SJMAdBaseAdapter

@property (nonatomic,strong)UIViewController *viewController;

///  视频状态代理
@property (nonatomic, weak) id<SJMAdapterContentAdapterVideoStateDelegate> SJMAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id<SJMContentAdapterStateDelegate> SJMAdapter_stateDelegate;


-(void)loadContentPageWithDeeplink:(NSString *)deepLink;

- (void)tryToRefresh;


//内容标识
@property (nonatomic,copy)NSString *contentInfoId;
//内容类型
//SJMContentInfoTypeUnknown = 0,         //未知，正常不会出现
// SJMContentInfoTypeNormal = 1,          //普通信息流
// SJMContentInfoTypeAd = 2,              //SDK内部广告
//SJMContentInfoTypeEmbeded = 100    //外部广告
@property (nonatomic,assign)NSInteger contentInfoType;

/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)SJMAdapter_videoDidStartPlay:(SJMContentPageAdapter *)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)SJMAdapter_videoDidPause:(SJMContentPageAdapter *)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)SJMAdapter_videoDidResume:(SJMContentPageAdapter *)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)SJMAdapter_videoDidEndPlay:(SJMContentPageAdapter *)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)SJMAdapter_videoDidFailedToPlay:(SJMContentPageAdapter *)videoContent withError:(NSError *)error;


/**
* 内容展示
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidFullDisplay:(SJMContentPageAdapter *)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidEndDisplay:(SJMContentPageAdapter *)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidPause:(SJMContentPageAdapter *)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidResume:(SJMContentPageAdapter *)content;



-(void)loadAd NS_UNAVAILABLE;

@end



@protocol SJMAdapterContentAdapterVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)SJMAdapter_videoDidStartPlay:(SJMContentPageAdapter *)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)SJMAdapter_videoDidPause:(SJMContentPageAdapter *)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)SJMAdapter_videoDidResume:(SJMContentPageAdapter *)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)SJMAdapter_videoDidEndPlay:(SJMContentPageAdapter *)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)SJMAdapter_videoDidFailedToPlay:(SJMContentPageAdapter *)videoContent withError:(NSError *)error;

@end



@protocol SJMContentAdapterStateDelegate <NSObject>
@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidFullDisplay:(SJMContentPageAdapter *)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidEndDisplay:(SJMContentPageAdapter *)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidPause:(SJMContentPageAdapter *)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)SJMAdapter_contentDidResume:(SJMContentPageAdapter *)content;


@end

NS_ASSUME_NONNULL_END
