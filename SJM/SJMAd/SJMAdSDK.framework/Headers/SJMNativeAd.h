//
//  SJMNativeAd.h
//  SJMAdSDK
//
//  Created by Rare on 2021/3/29.
//

#import "SJMAd.h"
#import "SJMNativeAdObject.h"
#import "SJMNativeAdView.h"
NS_ASSUME_NONNULL_BEGIN

@protocol SJMNativeAdDelegate <NSObject>
@optional
/**
 自渲染广告加载回调
 */
- (void)SJM_nativeAdLoaded:(NSArray<SJMNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;

@end


@interface SJMNativeAd : SJMAd

@property (nonatomic,weak)id <SJMNativeAdDelegate> delegate;

-(void)loadAdWithCount:(NSInteger)adCount;

@end

NS_ASSUME_NONNULL_END
