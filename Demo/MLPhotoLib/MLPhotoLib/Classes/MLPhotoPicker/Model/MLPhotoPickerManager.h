//
//  MLPhotoPickerManager.h
//  MLPhotoLib
//
//  Created by leisuro on 16/8/1.
//  Copyright © 2016年 Free. All rights reserved.
//

#import <UIKit/UIKit.h>

#define gtiOS8 ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0)
#define WeakSelf __weak typeof(self)weakSelf = self;

#define MLImagePickerUIScreenScale ([[UIScreen mainScreen] scale])
#define UIScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define MLImagePickerCellWidth ((UIScreenWidth - MLImagePickerCellMargin * (MLShowRowCellCount + 1)) / MLShowRowCellCount)

static NSString *MLNotificationDidChangeSelectUrl = @"MLNotificationDidChangeSelectUrl";
static NSUInteger MLDefaultMaxCount = 9;
static NSInteger MLShowRowCellCount = 3;
static CGFloat MLImagePickerCellMargin = 2;
static NSString *MLMaxCountMessage = @"已经超出图片的最大数咯~";

@interface MLPhotoPickerManager : NSObject
+ (instancetype)manager;
+ (void)clear;

@property (nonatomic, assign) NSInteger maxCount;
/// Support Camera.
@property (nonatomic, assign) BOOL isSupportTakeCamera;
@property (nonatomic, strong) NSMutableArray *selectsUrls;
@property (nonatomic, weak) UIViewController *presentViewController;
@property (nonatomic, strong) UINavigationController *navigationController;

/// Select ThumbImage as @[@{@selectsUrl:@UIImage}, ..]
@property (nonatomic, strong) NSMutableArray *selectsThumbImages;
/// Select OriginalImage as @[@{@selectsUrl:@UIImage}, ..]
@property (nonatomic, strong) NSMutableArray *selectsOriginalImage;

// Ignore _selectsOriginalImage @{@"URL":UIImage} -> @[UIImage, UIImage]
@property (nonatomic, strong, readonly) NSMutableArray *originalImage;
@property (nonatomic, strong, readonly) NSMutableArray *thumbImages;

@end
