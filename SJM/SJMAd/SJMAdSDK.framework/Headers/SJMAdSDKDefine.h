//
//  SJMAdSDKDefine.h
//  SJMAdSDK
//
//  Created by Rare on 2021/5/17.
//

#ifndef SJMAdSDKDefine_h
#define SJMAdSDKDefine_h

typedef NS_ENUM(NSUInteger, SJMMediaPlayerStatus) {
    SJMMediaPlayerStatusDefalt = 0,         // 初始状态
    SJMMediaPlayerStatusLoading = 1,         // 加载中
    SJMMediaPlayerStatusPlaying = 2,         // 开始播放
    SJMMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    SJMMediaPlayerStatusError = 4,           // 播放出错
    SJMMediaPlayerStatusStoped = 5,          // 播放停止
};



#endif /* SJMAdSDKDefine_h */
