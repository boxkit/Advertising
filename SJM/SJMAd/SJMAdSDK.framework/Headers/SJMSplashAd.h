//
//  SJMSplashAd.h
//  SJMAdSDK
//
//  Created by Rare on 2020/8/21.
//
#import <UIKit/UIKit.h>

#import "SJMAd.h"
#import "SJMSplashAdProtocol.h"
//#import "SJMSplashAdProtocol.h"
#import "SJMSplashAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface SJMSplashAd : SJMAd<SJMSplashAdProtocol>


@property(nonatomic,weak) id<SJMSplashAdDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
