//
//  SJMInterstitialAdAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/1/14.
//


#import "SJMAdBaseAdapter.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@class SJMInterstitialAdAdapter;
@protocol SJMInterstitialAdAdapterDelegate <NSObject>
- (void) SJM_interstitialAdAdapterDidLoad:(SJMInterstitialAdAdapter*) adapter;

- (void) SJM_interstitialAdAdapterDidLoadFail:(SJMInterstitialAdAdapter*) adapter error:(NSError * __nullable)error;

- (void) SJM_interstitialAdAdapterDidPresentScreen:(SJMInterstitialAdAdapter*) adapter;

- (void) SJM_interstitialAdAdapterDidClick:(SJMInterstitialAdAdapter*) adapter;

- (void) SJM_interstitialAdAdapterDidClose:(SJMInterstitialAdAdapter*) adapter;

- (void) SJM_interstitialAdAdapterDetailDidClose:(SJMInterstitialAdAdapter*) adapter;

- (void) SJM_interstitialAdAdapterDidFail:(SJMInterstitialAdAdapter*) adapter error:(NSError * __nullable)error;
@end

@interface SJMInterstitialAdAdapter : SJMAdBaseAdapter

@property(nonatomic,weak) id<SJMInterstitialAdAdapterDelegate> delegate;

-(void) loadAd;

-(void)presentAdFromRootViewController:(UIViewController*)  viewController;

- (void) SJM_interstitialAdDidLoad;

- (void) SJM_interstitialAdDidLoadFail:(NSError * __nullable)error;

- (void) SJM_interstitialAdDidPresentScreen;

- (void) SJM_interstitialAdDidClick;

- (void) SJM_interstitialAdDidClose;

- (void) SJM_interstitialAdDetailDidClose;

- (void) SJM_interstitialAdDidFail:(NSError * __nullable)error;

@end

NS_ASSUME_NONNULL_END
