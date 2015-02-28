//
//  FUSoundPlay.m
//  ForU
//
//  Created by 孙昕 on 15/2/26.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "FUSoundPlay.h"
#import "AppDelegate.h"
@interface FUSoundPlay()
{
    AVAudioPlayer *audio;
    NSMutableDictionary *dicMusic;
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
        [[NSNotificationCenter defaultCenter] addObserver:obj selector:@selector(moodChange) name:MSGMOODCHANGE object:nil];
    });
    return obj;
}

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

-(void)moodChange
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    NSURL *url=dicMusic[[APP GetGirlMood]];
    NSError *err;
    audio = [[AVAudioPlayer alloc]  initWithContentsOfURL:url error:&err];
    [audio setNumberOfLoops:-1];
    audio.delegate=self;
    [audio play];

}

-(id)init
{
    if(self=[super init])
    {
        NSArray *arr=@[@"平静",@"开心",@"害羞",@"撒娇",@"伤心",@"生气",@"烦躁",@"紧张"];
        dicMusic=[[NSMutableDictionary alloc] initWithCapacity:30];
        NSString *musicBundle=[[NSBundle mainBundle] pathForResource:@"Sound" ofType:@"bundle"];
        for(int i=0;i<arr.count;i++)
        {
            NSString *str=arr[i];
            NSString *musicPath=[[NSBundle bundleWithPath:musicBundle] pathForResource:str ofType:@"mp3" inDirectory:@"Music"];
            NSURL *musicURL = [NSURL fileURLWithPath:musicPath];
            [dicMusic setObject:musicURL forKey:arr[i]];
        }
        NSString *musicPath=[[NSBundle bundleWithPath:musicBundle] pathForResource:@"标题" ofType:@"mp3" inDirectory:@"Music"];
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
    [self moodChange];
}

-(void)pause
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    [audio pause];
}

-(void)resume
{
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    [audio play];
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
    NSUserDefaults *userDefaults=[NSUserDefaults standardUserDefaults];
    if([userDefaults boolForKey:@"definedbackmusic"])
    {
        return;
    }
    [audio stop];
}
@end









