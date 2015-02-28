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
#import "FUSoundPlay.h"
@implementation SettingView
-(id)init
{
    self=[[[NSBundle mainBundle] loadNibNamed:@"SettingView" owner:nil options:nil] lastObject];
    if(self)
    {
        self.clipsToBounds=NO;
        self.translatesAutoresizingMaskIntoConstraints=NO;
        self.backgroundColor=[FUPublic colorWithRGB:255 G:230 B:190];
        self.lbPeople.text=@"程序：神圣计划\n\n策划:HJ\n\n美工:夏哥，梁梁梁，小洁，阿落，我们仍未知道那些花的名字，莫名的忧伤";
        NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
        [_switchBackMusic setOn:![userDefaults boolForKey:@"definedbackmusic"]];
        [_switchSound setOn:![userDefaults boolForKey:@"definedeffectsound"]];
    }
    return self;
}




- (IBAction)onClose:(id)sender {
    POPBasicAnimation *ani=[POPBasicAnimation animationWithPropertyNamed:kPOPViewAlpha];
    ani.fromValue=@(1);
    ani.toValue=@(0);
    ani.completionBlock=^(POPAnimation *an,BOOL bFinish)
    {
        if(bFinish)
        {
            self.hidden=YES;
        }
    };
    [self pop_addAnimation:ani forKey:@"SettingHidden"];
}

- (IBAction)onMail:(id)sender
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"mailto://395414574@qq.com"]];
}

- (IBAction)onBackMusicChange:(id)sender
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    UISwitch *backSwitch=(UISwitch*)sender;
    if(backSwitch.isOn)
    {
        
        [userDefaults setBool:NO forKey:@"definedbackmusic"];
        [userDefaults synchronize];
        [[FUSoundPlay shareInstance] playTitle];
    }
    else
    {
        [[FUSoundPlay shareInstance] stop];
        [userDefaults setBool:YES forKey:@"definedbackmusic"];
        [userDefaults synchronize];
       
    }
}

- (IBAction)onSoundChange:(id)sender
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    UISwitch *soundSwitch=(UISwitch*)sender;
    if(soundSwitch.isOn)
    {
        [userDefaults setBool:NO forKey:@"definedeffectsound"];
        [userDefaults synchronize];
    }
    else
    {
        [userDefaults setBool:YES forKey:@"definedeffectsound"];
        [userDefaults synchronize];
    }

}
@end












