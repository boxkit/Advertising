//
//  SJMNativeExpressFeedAd.h
//  SJMAdSDK
//
//  Created by Rare on 2021/3/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@class SJMNativeExpressFeedAd;
@protocol SJMNativeExpressFeedAdDelegate <NSObject>
@optional
/**
 * 广告渲染成功
 */
- (void)SJM_nativeExpressFeedAdRenderSuccess:(SJMNativeExpressFeedAd *)feedAd;
/**
 * 广告渲染失败
 */
- (void)SJM_nativeExpressFeedAdRenderFail:(SJMNativeExpressFeedAd *)feedAd;

/**
 *广告即将展示
 */
- (void)SJM_nativeExpressFeedAdViewWillShow:(SJMNativeExpressFeedAd *)feedAd;
/**
 *广告点击
 */
- (void)SJM_nativeExpressFeedAdDidClick:(SJMNativeExpressFeedAd *)feedAd;
/**
 *不喜欢该广告
 */
- (void)SJM_nativeExpressFeedAdDislike:(SJMNativeExpressFeedAd *)feedAd;
/**
 *展示落地页
 */
- (void)SJM_nativeExpressFeedAdDidShowOtherController:(SJMNativeExpressFeedAd *)nativeAd;
/**
 *关闭落地页
 */
- (void)SJM_nativeExpressFeedAdDidCloseOtherController:(SJMNativeExpressFeedAd *)nativeAd;

@end


@interface SJMNativeExpressFeedAd : NSObject

@property (nonatomic,strong,readonly) UIView *feedView;

/**
 * Whether render is ready
 */
@property (nonatomic, assign,readonly) BOOL isReady;


@property(nonatomic,weak) id<SJMNativeExpressFeedAdDelegate> delegate;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/*
 *required [必选]
 *原生模板广告渲染
 */
- (void)render;

@end

NS_ASSUME_NONNULL_END
