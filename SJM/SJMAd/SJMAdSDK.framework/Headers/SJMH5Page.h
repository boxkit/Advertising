//
//  SJMH5Ad.h
//  SJMAdSDK
//
//  Created by Rare on 2020/10/28.
//  Copyright © 2020 SJM. All rights reserved.
//

#import "SJMAd.h"
#import "SJMUser.h"
#import "SJMH5PageDelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface SJMH5Page : SJMAd
@property(nonatomic,weak) id<SJMH5PageDelegate> delegate;
@property(nonatomic,strong) SJMUser *user;
- (instancetype)initWithPlacementId:(NSString *)placementId user:(SJMUser *)user delegate:(id<SJMH5PageDelegate>) delegate;
-(void) loadH5Page;
-(void) showH5Page:(UIViewController*) rootViewController;
@end

NS_ASSUME_NONNULL_END
