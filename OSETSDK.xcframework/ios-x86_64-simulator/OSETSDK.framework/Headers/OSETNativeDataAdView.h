//
//  OSETNativeDataAdView.h
//  YhsADSProject
//
//  Created by Shens on 22/5/2025.
//

#import <UIKit/UIKit.h>
#import "OSETNativeDataAdObject.h"
#import "OSETMediaView.h"
#import "OSETShakeView.h"
NS_ASSUME_NONNULL_BEGIN
@class OSETNativeDataAdView;

@protocol OSETNativeDataAdViewDelegate <NSObject>

@optional
/**
 广告曝光回调

 */
- (void)OSETNativeDataAdViewWillExpose:(OSETNativeDataAdView *)nativeDataAdView;
/**
 广告点击回调

 */
- (void)OSETNativeDataAdViewDidClick:(OSETNativeDataAdView *)nativeDataAdView;

/**
 广告关闭回调

 */
- (void)OSETNativeDataAdViewDidClose:(OSETNativeDataAdView *)nativeDataAdView;

/**
 广告详情页关闭回调
 */
- (void)OSETNativeDataAdDetailViewClosed:(OSETNativeDataAdView *)nativeDataAdView;



@end

@interface OSETNativeDataAdView : UIView
/**
 绑定的数据对象
 */
@property (nonatomic, strong) OSETNativeDataAdObject *dataObject;

/**
 视频广告的媒体View，绑定数据对象后自动生成，可自定义布局
 */
@property (nonatomic, strong) OSETMediaView *mediaView;

@property (nonatomic, strong) OSETShakeView *shakeView;
/**
 广告 View 时间回调对象
 */
@property (nonatomic, weak) id<OSETNativeDataAdViewDelegate> delegate;

/**
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;
- (BOOL)checkVisibility;
/**
 自渲染视图注册方法
 
 @warning 调用方法之前请先判断[dataObject isAdValid]是否为YES，当为NO时调用不生效
 @warning 需要注意的是 -[NativeAdView registerDataObject:clickableViews:]方法需要避免重复多次调用的情况
 @warning 当广告不需要展示并且销毁的时候，需要调用 -[NativeAdView unregisterDataObject]方法，即registerDataObject方法需要与unregisterDataObject方法成对调用
  @param dataObject 数据对象，必传字段
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 */
- (void)registerDataObject:(OSETNativeDataAdObject *_Nonnull)dataObject
            clickableViews:(NSArray<UIView *> *_Nonnull)clickableViews
            closeView:(UIView *)closeView;

///**
// 注册可点击的callToAction视图的方法
// 建议开发者使用GDTUnifiedNativeAdDataObject中的 buttonText 字段来创建视图，并取代自定义的下载或打开等button,
// 调用此方法之前必须先调用registerDataObject:clickableViews
// @param callToActionView CTA视图, 系统自动处理点击事件
// */
- (void)registerClickableCallToActionView:(UIView *_Nonnull)callToActionView;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 GDTUnifiedNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 GDTUnifiedNativeAdView 解绑，具体可参考示例 demo 的 UnifiedNativeAdBaseTableViewCell 类
 */
- (void)unregisterDataObject;



@end

NS_ASSUME_NONNULL_END
