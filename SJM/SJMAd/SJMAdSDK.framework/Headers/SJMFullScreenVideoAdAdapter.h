//
//  SJMFullScreenVideoAdAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/4/27.
//

#import "SJMAdBaseAdapter.h"
#import <UIKit/UIKit.h>
#import "SJMAdSDKDefine.h"
NS_ASSUME_NONNULL_BEGIN
@class SJMFullScreenVideoAdAdapter;
@protocol SJMfullScreenVideoAdAdapterDelegate <NSObject>


- (void) SJM_fullScreenVideoAdapterDidLoad:(SJMFullScreenVideoAdAdapter*) adapter;

- (void) SJM_fullScreenVideoAdapterDidLoadFail:(SJMFullScreenVideoAdAdapter*) adapter error:(NSError * __nullable)error;

- (void) SJM_fullScreenVideoAdapterDidPresentScreen:(SJMFullScreenVideoAdAdapter*) adapter;

- (void) SJM_fullScreenVideoAdapterDidClick:(SJMFullScreenVideoAdAdapter*) adapter;

- (void) SJM_fullScreenVideoAdapterDidClose:(SJMFullScreenVideoAdAdapter*) adapter;



- (void) SJM_fullScreenVideoAdapterDidFail:(SJMFullScreenVideoAdAdapter*) adapter error:(NSError * __nullable)error;


- (void)SJM_fullScreenVideoAdapter:(SJMFullScreenVideoAdAdapter*)adapter  playerStatus:(SJMMediaPlayerStatus)playerStatus;


- (void) SJM_fullScreenVideoAdapterDetailDidClose:(SJMFullScreenVideoAdAdapter*) adapter;

- (void)SJM_fullScreenVideoAdapterDetailDidPresent:(SJMFullScreenVideoAdAdapter*)adapter;

@end


@interface SJMFullScreenVideoAdAdapter : SJMAdBaseAdapter


@property(nonatomic,weak) id<SJMfullScreenVideoAdAdapterDelegate> delegate;

-(void) loadAd;

-(void)presentAdFromRootViewController:(UIViewController*)viewController;



- (void) SJM_fullScreenVideoDidLoad;

- (void) SJM_fullScreenVideoDidLoadFail:(NSError * __nullable)error;

- (void) SJM_fullScreenVideoDidPresentScreen;

- (void) SJM_fullScreenVideoDidClick;

- (void) SJM_fullScreenVideoDidClose;

- (void) SJM_fullScreenVideoDetailDidClose;

- (void) SJM_fullScreenVideoDidFail:(NSError * __nullable)error;

-(void)SJM_fullScreenVideoPlayerStatus:(SJMMediaPlayerStatus)status;

-(void)SJM_fullScreenVideoDetailDidPresent;
@end

NS_ASSUME_NONNULL_END
