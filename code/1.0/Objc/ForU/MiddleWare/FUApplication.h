//
//  FUApplication.h
//  ForU
//
//  Created by 孙昕 on 14/12/16.
//  Copyright (c) 2014年 孙昕. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FUApplication : NSObject
-(void)Reset:(long)girltype;
-(void)Update;
-(NSString*)GetPlayerPhysical;
-(NSString*)GetPlayerMoney;
-(NSString*)GetGirlIOI;
-(NSString*)GetGirlMood;
@end
