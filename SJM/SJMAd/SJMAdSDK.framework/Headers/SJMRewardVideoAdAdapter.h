//
//  SJMRewardVideoAdAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/1/14.
//


#import <UIKit/UIKit.h>
#import "SJMAdBaseAdapter.h"


NS_ASSUME_NONNULL_BEGIN
@class SJMRewardVideoAdAdapter;
@protocol SJMRewardVideoAdAdapterDelegate <NSObject>

- (void)SJM_rewardVideoAdAdapterDidLoad:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapterVideoDidLoad:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapterDidShow:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapterDidClose:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapterDidClicked:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapterDidRewardEffective:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapterDidPlayFinish:(SJMRewardVideoAdAdapter *)adapter;

- (void)SJM_rewardVideoAdAdapter:(SJMRewardVideoAdAdapter *)adapter didFailWithError:(NSError *)error;


@end


@interface SJMRewardVideoAdAdapter : SJMAdBaseAdapter

@property(nonatomic,strong,readonly)UIView *rewardAdapterView;

@property(nonatomic,weak) id<SJMRewardVideoAdAdapterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(SJMAdItemConfig *)adItemConfig userId:(NSString *)userId reward_name:(NSString *_Nullable)reward_name reward_amount:(NSInteger)reward_amount extra:(NSString*_Nullable)extra;

@property(nonatomic,copy) NSString *userId;
@property(nonatomic,copy) NSString *reward_name;
@property(nonatomic,assign) NSInteger reward_amount;
@property(nonatomic,copy) NSString *extra;

//静音设置
@property (nonatomic) BOOL videoMuted;
//交易ID
@property(nonatomic,copy,readonly) NSString *trans_id;
//验证dic
@property(nonatomic,copy,readonly) NSDictionary *validationDictionary;

- (void) loadAd;

- (void) showAdInViewController:(UIViewController*)viewController;



- (void)SJM_rewardVideoAdDidLoad;

- (void)SJM_rewardVideoAdVideoDidLoad;

- (void)SJM_rewardVideoAdDidShow;

- (void)SJM_rewardVideoAdDidClose;

- (void)SJM_rewardVideoAdDidClicked;

- (void)SJM_rewardVideoAdDidRewardEffective;

- (void)SJM_rewardVideoAdDidPlayFinish;

- (void)SJM_rewardVideoAdDidFailWithError:(NSError *)error;

@end



NS_ASSUME_NONNULL_END
