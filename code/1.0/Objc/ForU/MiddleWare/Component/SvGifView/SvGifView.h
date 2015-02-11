//
//  SvGifView.h
//  SvGifSample
//
//  Created by maple on 3/28/13.
//  Copyright (c) 2013 smileEvday. All rights reserved.
//
//  QQ: 1592232964


#import <UIKit/UIKit.h>

@interface SvGifView : UIView


/*
 * @brief desingated initializer
 */
- (id)initWithCenter:(CGPoint)center fileName:(NSString*)name Bundle:(NSString*)bundle;

/*
 * @brief start Gif Animation
 */
- (void)startGif;

/*
 * @brief stop Gif Animation
 */
- (void)stopGif;

/*
 * @brief get frames image(CGImageRef) in Gif
 */
+ (NSArray*)framesInGif:(NSURL*)fileURL;

-(void)setGif:(NSString*)name Bundle:(NSString*)bundle;

@end
