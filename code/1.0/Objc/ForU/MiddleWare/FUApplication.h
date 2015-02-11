//
//  FUApplication.h
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <Foundation/Foundation.h>
enum GIRLTYPE {LOLI,MAID,QUEEN};
enum PERSONTYPE {PLAYER,GIRL};
enum NOTIFYTYPE {CALL,DATEITEMEND,WORKHELPEND,WORKIOI,WORKMEET,WORKHELP,LEISUREIOI,LEISUREDATE,WORKEVENT,LEISUREEVENT,NONE};
enum DATETYPE {EAT,FILM,WALK,PARK};
enum PLAYERSTATE {LEISURE,SLEEP,WORK};
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
@end








