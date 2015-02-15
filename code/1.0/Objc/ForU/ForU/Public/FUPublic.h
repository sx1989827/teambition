//
//  FUPublic.h
//  ForU
//
//  Created by 孙昕 on 15/1/19.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface UIImageView (LoadImage)
-(void)setPlaceImg:(NSString*)name;
-(void)setGirlImg:(NSString*)name;
@end
@interface FUPublic : NSObject
+(UIColor*)colorWithRGB:(NSInteger)r G:(NSInteger)g B:(NSInteger)b;
+(void)dispatchAfter:(CGFloat)second Block:(dispatch_block_t)block;
+(void)showChangeView:(NSString*)title Offset:(double)offset View:(UIView*)view Point:(CGPoint)point;
@end
