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
@interface FUApplication : NSObject
-(void)Reset:(GIRLTYPE)girltype;
-(void)Update;
-(NSString*)GetPlayerPhysical;
-(NSString*)GetPlayerMoney;
-(NSString*)GetGirlIOI;
-(NSString*)GetGirlMood;
-(void)Save;
-(void)CreateNotify;
@end








