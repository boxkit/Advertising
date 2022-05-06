//
//  SJMRewardAd.h
//  SJMAdSDK
//
//  Created by Rare on 2020/8/24.
//
#import <UIKit/UIKit.h>
#import "SJMAd.h"
#import "SJMRewardVideoAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN
@class SJMRewardVideoModel;
@interface SJMRewardVideoAd : SJMAd

@property(nonatomic,weak) id<SJMRewardVideoAdDelegate> delegate;

-(instancetype)initWithPlacementId:(NSString *)placementId NS_UNAVAILABLE;

- (instancetype)initWithPlacementId:(NSString *)placementId rewardedVideoModel:(SJMRewardVideoModel *)rewardedVideoModel;


@property (nonatomic,strong)SJMRewardVideoModel *rewardedVideoModel;

//静音设置
@property (nonatomic) BOOL videoMuted;

//交易ID
@property(nonatomic,copy,readonly) NSString *trans_id;
//验证dic
@property(nonatomic,copy,readonly) NSDictionary *validationDictionary;

- (void) loadAd;

- (void) showAdInViewController:(UIViewController*)viewController;

@end



@interface SJMRewardVideoModel : NSObject
/**
 required.
 Third-party game user_id identity.
 Mainly used in the reward issuance, it is the callback pass-through parameter from server-to-server.
 It is the unique identifier of each user.
 In the non-server callback mode, it will also be pass-through when the video is finished playing.
 Only the string can be passed in this case, not nil.
 */
@property(nonatomic,copy) NSString *userId;
/**optional*/
@property(nonatomic,copy) NSString *reward_name;
/**optional*/
@property(nonatomic,assign) NSInteger reward_amount;
/**optional*/
@property(nonatomic,copy) NSString *extra;

@end

NS_ASSUME_NONNULL_END
