//
//  SettingView.h
//  ForU
//
//  Created by 孙昕 on 15/1/19.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SettingView : UIView
- (IBAction)onClose:(id)sender;
- (IBAction)onMail:(id)sender;
- (IBAction)onBackMusicChange:(id)sender;
- (IBAction)onSoundChange:(id)sender;
@property (strong, nonatomic) IBOutlet UILabel *lbPeople;


@end
