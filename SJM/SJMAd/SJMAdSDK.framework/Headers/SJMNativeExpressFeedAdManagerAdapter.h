//
//  SJMNativeExpressFeedAdManagerAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/3/2.
//

#import "SJMAdBaseAdapter.h"
#import "SJMNativeExpressFeedAd.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@protocol SJMNativeExpressFeedAdManagerApterDelegate;
@interface SJMNativeExpressFeedAdManagerAdapter : SJMAdBaseAdapter
@property (nonatomic)CGSize adSize;

@property (nonatomic, strong) NSArray<SJMNativeExpressFeedAd *> *data;

@property (nonatomic,weak)id<SJMNativeExpressFeedAdManagerApterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(SJMAdItemConfig *)adItemConfig size:(CGSize)size;


-(void)loadAdWithCount:(NSInteger)adCount;

-(void)removeCacheFeedAds;


- (void)SJMFeed_feedAdsManagerSuccessToLoad:(SJMNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<SJMNativeExpressFeedAd *> *_Nullable)feedAdDataArray;
- (void)SJMFeed_feedAdsManager:(SJMNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@protocol SJMNativeExpressFeedAdManagerApterDelegate <NSObject>
@optional
- (void)SJMFeed_feedAdsManagerSuccessToLoad:(SJMNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<SJMNativeExpressFeedAd *> *_Nullable)feedAdDataArray;

- (void)SJMFeed_feedAdsManager:(SJMNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;
@end
NS_ASSUME_NONNULL_END
