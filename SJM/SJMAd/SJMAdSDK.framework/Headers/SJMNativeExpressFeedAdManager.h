//
//  SJMNativeExpressFeedAdManager.h
//  SJMAdSDK
//
//  Created by Rare on 2021/1/8.
//

#import "SJMAd.h"
#import "SJMNativeExpressFeedAd.h"

@class SJMNativeExpressFeedAdManager;
NS_ASSUME_NONNULL_BEGIN

@protocol SJMNativeExpressFeedAdManagerDelegate <NSObject>
@optional
/**
 模板信息流广告􏳺􏶈􏰃􏴅􏴍􏱊􏳺􏶈􏰃􏴅􏴍􏱊􏳺􏶈􏰃􏴅􏴍􏱊数据加载成功
 */
-(void)SJM_nativeExpressFeedAdManagerSuccessToLoad:(SJMNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<SJMNativeExpressFeedAd *> *_Nullable)feedAdDataArray;

/**
 模板信息流广告􏳺􏶈􏰃􏴅􏴍􏱊􏳺􏶈􏰃􏴅􏴍􏱊􏳺􏶈􏰃􏴅􏴍􏱊数据加载失败
 */
- (void)SJM_nativeExpressFeedAdManager:(SJMNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end


@interface SJMNativeExpressFeedAdManager : SJMAd

@property(nonatomic,weak) id<SJMNativeExpressFeedAdManagerDelegate> delegate;

@property (nonatomic)CGSize adSize;

@property (nonatomic, strong) NSArray<SJMNativeExpressFeedAd *> *data;


-(instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;

/**
 * 加载广告，建议最大个数不超过5个
 */
-(void)loadAdDataWithCount:(NSInteger)count;

@end




NS_ASSUME_NONNULL_END
