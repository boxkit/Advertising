//
//  SJMAdBaseAdapter.h
//  SJMAdSDK
//
//  Created by Rare on 2021/5/17.
//

#import <Foundation/Foundation.h>
#import "SJMAdItemConfig.h"
NS_ASSUME_NONNULL_BEGIN

@interface SJMAdBaseAdapter : NSObject

@property(nonatomic,copy) NSString *platform;
@property(nonatomic,copy) NSString *placementId;
@property(nonatomic,copy) NSString *sjmAdId;
@property(nonatomic,strong) SJMAdItemConfig *config;


+(void) registerPlatform:(NSString*) platform adType:(NSString*) adType adapterClass:(NSString*) adapterClass;
+(NSString*) getAdapterClass:(NSString*)platform adType:(NSString*) adType;
+ (Class)getAdapterClass:(SJMAdItemConfig *)adItemConfig;
+ (instancetype)createWithAdItemConfig:(SJMAdItemConfig *)adItemConfig;

- (instancetype)initWithAdItemConfig:(SJMAdItemConfig *)adItemConfig;

- (BOOL)hasReady;
- (BOOL)hasInit;

@end

NS_ASSUME_NONNULL_END
