//
//  SJMContentPage.h
//  SJMAdSDK
//
//  Created by Rare on 2020/12/21.
//

#import "SJMAd.h"
#import "SJMContentPageDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface SJMContentPage : SJMAd

@property (nonatomic,readonly)UIViewController *viewController;
///  视频状态代理
@property (nonatomic, weak) id<SJMContentPageVideoStateDelegate> videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id<SJMContentPageStateDelegate> stateDelegate;


- (void)tryToRefresh;

//内容标识
@property (nonatomic,copy,readonly)NSString *contentInfoId;
//内容类型
@property (nonatomic,assign,readonly)SJMContentInfoType contentInfoType;

@end







NS_ASSUME_NONNULL_END
