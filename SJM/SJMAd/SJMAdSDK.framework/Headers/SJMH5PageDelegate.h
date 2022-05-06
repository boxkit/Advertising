//
//  SJMH5AdDelegate.h
//  SJMAdSDK
//
//  Created by Robin on 2020/10/28.
//  Copyright © 2020 SJM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class SJMUser;
@protocol SJMH5PageDelegate <NSObject>

@optional

//H5Ad加载完成
-(void) onSJMH5PageLoaded:(SJMUser*) user error:(nullable NSError*) error;

//H5Ad错误
-(void) onSJMH5PageError:(SJMUser*) user error:(NSError*) error;



//H5操作回调
//积分不足
-(void) onIntegralNotEnough:(SJMUser*) user needIntegral:(NSInteger) integral;
//积分消耗
-(void) onIntegralExpend:(SJMUser*) user expendIntegral:(NSInteger) integral;
//积分奖励
-(void) onIntegralReward:(SJMUser*) user rewardIntegral:(NSInteger) integral;

//奖励发放,奖励积分
-(void) onSJMH5PageAdRewardProvide:(SJMUser*) user rewardIntegral:(NSInteger) integral;

//用户页面的行为操作
-(void) onSJMH5PageUserBehavior:(SJMUser*) user behavior:(NSString*) behavior;


//广告回调
//广告激励视频加载成功
-(void) onSJMH5PageAdRewardLoaded:(SJMUser*) user trans_id:(NSString*) trans_id;

//广告激励视频触发激励（观看视频大于一定时长或者视频播放完毕）
-(void) onSJMH5PageAdRewardValid:(SJMUser*) user trans_id:(NSString*) trans_id;

//广告点击
-(void) onSJMH5PageAdRewardClick:(SJMUser*) user ;

//广告加载错误
-(void) onSJMH5PageAdReward:(SJMUser*) user didFailWithError:(NSError*) error;


@end


NS_ASSUME_NONNULL_END
