//
//  OSETMediaView.h
//  YhsADSProject
//
//  Created by Shens on 29/5/2025.
//

#import <UIKit/UIKit.h>
#import "OSETNativeDataAdObject.h"
NS_ASSUME_NONNULL_BEGIN
@class OSETMediaView;
@protocol GDTMediaViewDelegate <NSObject>

@optional

/**
 用户点击 MediaView 回调，当 VideoConfig userControlEnable 设为 YES，用户点击 mediaView 会回调。
 @param mediaView 播放器实例
 */
- (void)OSETMediaViewDidTapped:(OSETMediaView *)mediaView;
/**
 播放完成回调

 @param mediaView 播放器实例
 */
- (void)OSETMediaViewDidPlayFinished:(OSETMediaView *)mediaView;

@end


@interface OSETMediaView : UIView
/**
 绑定的数据对象
 */
@property (nonatomic, strong) OSETNativeDataAdObject * dataObject;

/**
 GDTMediaView 回调对象
 */
@property (nonatomic, weak) id <GDTMediaViewDelegate> delegate;

/**
 * 视频广告时长，单位 ms
 */
- (CGFloat)videoDuration;

/**
 * 视频广告已播放时长，单位 ms
 */
- (CGFloat)videoPlayTime;

/**
 播放视频
 */
- (void)play;

/**
 暂停视频，调用 pause 后，需要被暂停的视频广告对象，不会再自动播放，需要调用 play 才能恢复播放。
 */
- (void)pause;

/**
 停止播放，并展示第一帧
 */
- (void)stop;

/**
 播放静音开关
 @param flag 是否静音
 */
- (void)muteEnable:(BOOL)flag;

/**
 自定义播放按钮

 @param image 自定义播放按钮图片，不设置为默认图
 @param size 自定义播放按钮大小，不设置为默认大小 44 * 44
 */
- (void)setPlayButtonImage:(UIImage *)image size:(CGSize)size;


@end

NS_ASSUME_NONNULL_END
