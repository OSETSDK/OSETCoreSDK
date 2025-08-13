//
//  OSETBaseView.h
//  YhsADSProject
//
//  Created by Shens on 7/11/2024.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class Sort;
@interface OSETBaseView : UIView

@property(nonatomic,readonly,assign)NSInteger eCPM;
@property(nonatomic,strong)Sort * sort;

@end

NS_ASSUME_NONNULL_END
