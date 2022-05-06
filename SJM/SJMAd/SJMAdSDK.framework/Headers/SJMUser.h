//
//  SJMUser.h
//  SJMAdSDK
//
//  Created by Rare on 2021/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SJMUser : NSObject

@property(nonatomic,copy) NSString* userID;
@property(nonatomic,copy) NSString* userName;
@property(nonatomic,copy) NSString*  userAvatar;
@property(nonatomic,assign) NSInteger userIntegral;
@property(nonatomic,copy) NSString* ext;

-(NSString*) toJsonString;
@end

NS_ASSUME_NONNULL_END
