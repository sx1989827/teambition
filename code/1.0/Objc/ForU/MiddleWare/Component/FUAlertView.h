//
//  FUAlertView.h
//  ForU
//
//  Created by 孙昕 on 14/12/17.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FUAlertView : UIView
{
    UIView *viewTitle;
    UILabel *lbTitle;
    UIButton *btnFirst;
    UIButton *btnSecond;
    void (^blockFirst)();
    void (^blockSecond)();
}
-(id)initWithMsg:(NSString*)title;
-(id)initWithMsgBlock:(NSString*)title Block:(void (^)())block;
-(id)initWithChoose:(NSString*)title First:(NSString*)firstbtn Second:(NSString*)secondbtn FirstBlock:(void (^)())firstblock SecondBlock:(void (^)())secondblock;
-(void)showInView:(UIView*)view;
@end
