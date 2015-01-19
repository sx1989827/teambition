//
//  FUPublic.m
//  ForU
//
//  Created by 孙昕 on 15/1/19.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "FUPublic.h"

@implementation FUPublic
+(UIColor*)colorWithRGB:(NSInteger)r G:(NSInteger)g B:(NSInteger)b
{
    return [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:1];
}

+(void)dispatchAfter:(CGFloat)second Block:(dispatch_block_t)block
{
    dispatch_time_t time=dispatch_time(DISPATCH_TIME_NOW, second*NSEC_PER_SEC);
    dispatch_after(time, dispatch_get_main_queue(), block);
}
@end
