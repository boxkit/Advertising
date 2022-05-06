//
//  SJMNativeAdAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/3/29.
//

#import "SJMAdBaseAdapter.h"
#import "SJMNativeAdObject.h"
NS_ASSUME_NONNULL_BEGIN
@protocol SJMNativeAdAdapterDelegate <NSObject>
/**
 广告数据回调

 @param nativeAdObjects 广告数据数组
 @param error 错误信息
 */
- (void)SJMAdapter_nativeAdLoaded:(NSArray<SJMNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;


@end



@interface SJMNativeAdAdapter : SJMAdBaseAdapter

@property (nonatomic,weak)id <SJMNativeAdAdapterDelegate> delegate;


/**
 广告数据回调
 */
- (void)nativeAdLoaded:(NSArray<SJMNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;

-(void)loadAdWithCount:(NSInteger)adCount;

@end

NS_ASSUME_NONNULL_END
