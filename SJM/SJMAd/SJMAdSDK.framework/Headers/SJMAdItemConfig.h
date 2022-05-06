//
//  SJMAdItemConfig.h
//  SJMAdSDK
//
//  Created by Rare on 2020/12/22.
//

#import <Foundation/Foundation.h>
extern NSString * _Nonnull  const SJMADType_Splash;
extern NSString * _Nonnull  const SJMADType_Interstitial;
extern NSString * _Nonnull  const SJMADType_RewardVideo;
extern NSString * _Nonnull  const SJMADType_FeedFullVideo;
extern NSString * _Nonnull  const SJMADType_Banner;
extern NSString * _Nonnull  const SJMADType_Feed;
extern NSString * _Nonnull  const SJMADType_Feed1;
extern NSString * _Nonnull  const SJMADType_NativeAd;
extern NSString * _Nonnull  const SJMADType_ContentPage;
extern NSString * _Nonnull  const SJMADType_FullVideoAd;

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger,SJMAdPlatformType){
    SJMAdPlatform_None,
    SJMAdPlatform_CSJ,
    SJMAdPlatform_GDT,
    SJMAdPlatform_MTG,
    SJMAdPlatform_KS,
    SJMAdPlatform_SJM,
};

@interface SJMAdItemConfig : NSObject<NSCoding>
@property(nonatomic,copy) NSString *SJM_appID;
@property(nonatomic,copy) NSString *SJM_adID;
@property(nonatomic,copy) NSString *appId;
@property(nonatomic,copy) NSString *adId;
@property(nonatomic,copy) NSString *adType;
@property(nonatomic,copy) NSString *platform;
@property(nonatomic,assign)SJMAdPlatformType platformType;
@property(nonatomic,strong) NSDictionary *params;

@property(nonatomic,assign)BOOL is_service;

-(instancetype) initWith:(NSDictionary *) dic;
@end

NS_ASSUME_NONNULL_END
