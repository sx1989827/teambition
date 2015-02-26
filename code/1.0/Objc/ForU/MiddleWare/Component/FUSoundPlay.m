//
//  FUSoundPlay.m
//  ForU
//
//  Created by 孙昕 on 15/2/26.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "FUSoundPlay.h"
long g_backMusiccount=3;
@interface FUSoundPlay()
{
    AVAudioPlayer *audio;
    NSMutableArray *arrMusic;
    NSURL *title;
}
@end
@implementation FUSoundPlay


+(FUSoundPlay*)shareInstance
{
    static dispatch_once_t onceToken;
    static FUSoundPlay* obj;
    dispatch_once(&onceToken, ^{
        obj=[[FUSoundPlay alloc] init];
    });
    return obj;
}

-(id)init
{
    if(self=[super init])
    {
        arrMusic=[[NSMutableArray alloc] initWithCapacity:30];
        NSString *musicBundle=[[NSBundle mainBundle] pathForResource:@"Sound" ofType:@"bundle"];
        for(int i=0;i<g_backMusiccount;i++)
        {
            NSString *musicPath=[[NSBundle bundleWithPath:musicBundle] pathForResource:[NSString stringWithFormat:@"%d",i+1] ofType:@"mp3" inDirectory:@"Music"];
            NSURL *musicURL = [NSURL fileURLWithPath:musicPath];
            [arrMusic addObject:musicURL];
        }
        NSString *musicPath=[[NSBundle bundleWithPath:musicBundle] pathForResource:@"title" ofType:@"mp3" inDirectory:@"Music"];
        title = [NSURL fileURLWithPath:musicPath];
    }
    return self;
}

-(void)playTitle
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    audio = [[AVAudioPlayer alloc]  initWithContentsOfURL:title  error:nil];
    [audio setNumberOfLoops:-1];
    [audio play];
}

-(void)playBackMusic
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    audio = [[AVAudioPlayer alloc]  initWithContentsOfURL:arrMusic[random()%g_backMusiccount]  error:nil];
    [audio setNumberOfLoops:-1];
    audio.delegate=self;
    [audio play];
}

-(void)pause
{
    [audio pause];
}

-(void)resume
{
    [audio play];
}

- (void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag
{
    [self playBackMusic];
}

-(void)playEffectSound:(NSString*)name
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedeffectsound"])
    {
        return;
    }
    NSString *musicBundle=[[NSBundle mainBundle] pathForResource:@"Sound" ofType:@"bundle"];
    NSString *musicPath=[[NSBundle bundleWithPath:musicBundle] pathForResource:name ofType:@"wav" inDirectory:@"EffectSound"];
    
    SystemSoundID soundID;
    
    AudioServicesCreateSystemSoundID((__bridge CFURLRef)[NSURL fileURLWithPath:musicPath],&soundID);
    
    AudioServicesPlaySystemSound(soundID);
}

- (void)audioPlayerEndInterruption:(AVAudioPlayer *)player withOptions:(NSUInteger)flags
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    [audio play];
}

-(void)stop
{
    [audio stop];
}
@end









