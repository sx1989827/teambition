//
//  SettingView.m
//  ForU
//
//  Created by 孙昕 on 15/1/19.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "SettingView.h"
#import "FUPublic.h"
#import <pop/POP.h>
@implementation SettingView
-(id)init
{
    self=[[[NSBundle mainBundle] loadNibNamed:@"SettingView" owner:nil options:nil] lastObject];
    if(self)
    {
        self.clipsToBounds=NO;
        self.translatesAutoresizingMaskIntoConstraints=NO;
        self.backgroundColor=[FUPublic colorWithRGB:255 G:230 B:190];
    }
    return self;
}




- (IBAction)onClose:(id)sender {
    POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    ani.fromValue=@(1);
    ani.toValue=@(0);
    ani.completionBlock=^(POPAnimation *an,bool bFinish)
    {
        if(bFinish)
        {
            self.hidden=YES;
        }
    };
    [self pop_addAnimation:ani forKey:@"SettingHidden"];
}
@end












