//
//  OSETShakeView.h
//  YhsADSProject
//
//  Created by Shens on 10/6/2025.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OSETShakeView : UIView
@property (nonatomic, strong) UILabel * tipsLabel;
@property (nonatomic, strong) UIImageView * shakeImageView;
- (void)startRotationShakeAnimation;
@end

NS_ASSUME_NONNULL_END
