//
//  SJMAd.h
//  SJMAdSDK
//
//  Created by Rare on 2021/5/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface SJMAd : NSObject

@property(nonatomic,copy) NSString *placementId;
/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
