//
//  FUPhotoView.h
//  ForU
//
//  Created by 孙昕 on 14/12/18.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FUPhotoView : UIScrollView
-(void)showInView:(UIView*)view;
-(void)addPhoto:(NSString*)dir;
@end
