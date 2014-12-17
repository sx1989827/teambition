//
//  FULoadingView.h
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SvGifView.h"
@interface FULoadingView : UIView
{
    SvGifView* gifView;
    UILabel *lbTitle;
}
-(void)showInView:(UIView*)view;
-(void)remove;
@end
