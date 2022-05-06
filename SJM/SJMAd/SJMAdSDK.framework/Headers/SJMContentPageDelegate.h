//
//  SJMContentPageDelegate.h
//  SJMAdSDK
//
//  Created by Rare on 2020/12/22.
//

#ifndef SJMContentPageDelegate_h
#define SJMContentPageDelegate_h

typedef NS_ENUM(NSUInteger, SJMContentInfoType) {
    SJMContentInfoTypeUnknown,         //未知，正常不会出现
    SJMContentInfoTypeNormal,          //普通信息流
    SJMContentInfoTypeAd,              //SDK内部广告
    SJMContentInfoTypeEmbeded = 100    //外部广告
};
@class  SJMContentPage;
NS_ASSUME_NONNULL_BEGIN
@protocol SJMContentPageVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)SJM_videoDidStartPlay:(SJMContentPage *)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)SJM_videoDidPause:(SJMContentPage *)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)SJM_videoDidResume:(SJMContentPage *)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)SJM_videoDidEndPlay:(SJMContentPage *)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)SJM_videoDidFailedToPlay:(SJMContentPage *)videoContent withError:(NSError *)error;

@end



@protocol SJMContentPageStateDelegate <NSObject>
@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)SJM_contentDidFullDisplay:(SJMContentPage *)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)SJM_contentDidEndDisplay:(SJMContentPage *)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)SJM_contentDidPause:(SJMContentPage *)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)SJM_contentDidResume:(SJMContentPage *)content;


@end

NS_ASSUME_NONNULL_END

#endif /* SJMContentPageDelegate_h */
