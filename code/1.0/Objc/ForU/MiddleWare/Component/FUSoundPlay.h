//
//  FUSoundPlay.h
//  ForU
//
//  Created by 孙昕 on 15/2/26.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
@interface FUSoundPlay : NSObject<AVAudioPlayerDelegate>
+(FUSoundPlay*)shareInstance;
-(void)playTitle;
-(void)playBackMusic;
-(void)pause;
-(void)resume;
-(void)stop;
-(void)playEffectSound:(NSString*)name;
@end
