//
//  FUApplication.h
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FUConstHeader.h"
@interface FUApplication : NSObject
-(void)Reset:(GIRLTYPE)girltype girlname:(NSString*)name x:(double)x y:(double)y;
-(void)Update;
-(NSString*)GetPlayerPhysical;
-(NSString*)GetPlayerMoney;
-(NSString*)GetGirlIOI;
-(NSString*)GetGirlMood;
-(BOOL)GetLove;
-(void)Save;
-(void)CreateNotify;
-(void)CreateNotify:(NOTIFYTYPE)type Time:(NSDate *)date DateType:(DATETYPE)datetype;
-(void)RemoveNotify;
-(void)AdjustNotify;
-(void)Exit;
-(NSString*)GetStartStory;
-(NSString*)GetStory;
-(PLAYERSTATE)GetPlayerState;
-(void)ChangePlayerState:(PLAYERSTATE)state;
-(NSString*)GetPlace;
-(GIRLTYPE)GetGirlType;
-(BOOL)HandleActionEye:(ACTIONEYETYPE)type;
-(void)HandleActionBody:(ACTIONBODYTYPE)type;
-(void)HandleActionTalk:(NSString*)type;
-(NSString*)GetGirlMoodDes;
-(CGRect)GetGirlFaceRect;
-(CGRect)GetGirlBreastRect;
-(NSArray*)GetAvalibleBodyAction;
-(NSArray*)GetAvalibleTalkAction;
@end








