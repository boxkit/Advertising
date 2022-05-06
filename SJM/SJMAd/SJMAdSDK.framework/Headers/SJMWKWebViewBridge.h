//
//  SJMWKWebViewBridge.h
//  SJMSDK

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "SJMH5PageDelegate.h"
#import "SJMUser.h"
NS_ASSUME_NONNULL_BEGIN

@interface SJMWKWebViewBridge : NSObject

@property (nonatomic, strong) SJMUser *user;


- (void)initWithRootViewController:(UIViewController *)viewController delegate:(id<SJMH5PageDelegate>)delegate;

- (void)buildWKWebView:(WKWebView *)wkWebView;


- (void)releaseWKWebView:(WKWebView *)wkWebView;



@end

NS_ASSUME_NONNULL_END
