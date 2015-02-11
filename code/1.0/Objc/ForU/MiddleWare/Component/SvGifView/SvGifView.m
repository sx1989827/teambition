//
//  SvGifView.m
//  SvGifSample
//
//  Created by maple on 3/28/13.
//  Copyright (c) 2013 smileEvday. All rights reserved.
//
//  QQ: 1592232964

#import "SvGifView.h"
#import <ImageIO/ImageIO.h>
#import <QuartzCore/CoreAnimation.h>

/*
 * @brief resolving gif information
 */
void getFrameInfo(CFURLRef url, NSMutableArray *frames, NSMutableArray *delayTimes, CGFloat *totalTime,CGFloat *gifWidth, CGFloat *gifHeight)
{
    CGImageSourceRef gifSource = CGImageSourceCreateWithURL(url, NULL);
    
    // get frame count
    size_t frameCount = CGImageSourceGetCount(gifSource);
    for (size_t i = 0; i < frameCount; ++i) {
        // get each frame
        CGImageRef frame = CGImageSourceCreateImageAtIndex(gifSource, i, NULL);
        [frames addObject:(__bridge  id)frame];
        CGImageRelease(frame);
        
        // get gif info with each frame
        NSDictionary *dict = (NSDictionary*)CFBridgingRelease(CGImageSourceCopyPropertiesAtIndex(gifSource, i, NULL));
        
        // get gif size
        if (gifWidth != NULL && gifHeight != NULL) {
            *gifWidth = [[dict valueForKey:(__bridge NSString*)kCGImagePropertyPixelWidth] floatValue];
            *gifHeight = [[dict valueForKey:(__bridge NSString*)kCGImagePropertyPixelHeight] floatValue];
        }
        
        // kCGImagePropertyGIFDictionary中kCGImagePropertyGIFDelayTime，kCGImagePropertyGIFUnclampedDelayTime值是一样的
        NSDictionary *gifDict = [dict valueForKey:(__bridge NSString*)kCGImagePropertyGIFDictionary];
        [delayTimes addObject:[gifDict valueForKey:(__bridge NSString*)kCGImagePropertyGIFDelayTime]];
        
        if (totalTime) {
            *totalTime = *totalTime + [[gifDict valueForKey:(__bridge NSString*)kCGImagePropertyGIFDelayTime] floatValue];
        }
        
       // CFRelease((__bridge CFTypeRef)(dict));
    }
    
    if (gifSource) {
        CFRelease(gifSource);
    }
}

@interface SvGifView() {
    NSMutableArray *_frames;
    NSMutableArray *_frameDelayTimes;
    
    CGFloat _totalTime;         // seconds
    CGFloat _width;
    CGFloat _height;
}

@end

@implementation SvGifView


- (id)initWithCenter:(CGPoint)center fileName:(NSString*)name Bundle:(NSString*)bundle
{
    self = [super init];
    if (self) {
        _frames = [[NSMutableArray alloc] init];
        _frameDelayTimes = [[NSMutableArray alloc] init];
        
        _width = 0;
        _height = 0;
        
        if (name!=nil) {
            NSString *imgPath;
            if(bundle!=nil)
            {
                NSString *imgBundle=[[NSBundle mainBundle] pathForResource:bundle ofType:@"bundle"];
                imgPath=[[NSBundle bundleWithPath:imgBundle] pathForResource:imgBundle ofType:@"gif"];
            }
            else
            {
                imgPath=[[NSBundle mainBundle] pathForResource:name ofType:@"gif"];
            }
            getFrameInfo((__bridge  CFURLRef)[NSURL fileURLWithPath:imgPath], _frames, _frameDelayTimes, &_totalTime, &_width, &_height);
        }
        
        self.frame = CGRectMake(0, 0, _width, _height);
        self.center = center;
    }
    
    return self;
}


+ (NSArray*)framesInGif:(NSURL *)fileURL
{
    NSMutableArray *frames = [NSMutableArray arrayWithCapacity:3];
    NSMutableArray *delays = [NSMutableArray arrayWithCapacity:3];
    
    getFrameInfo((__bridge CFURLRef)fileURL, frames, delays, NULL, NULL, NULL);
    
    return frames;
}

- (void)startGif
{
    CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"contents"];
    
    NSMutableArray *times = [NSMutableArray arrayWithCapacity:3];
    CGFloat currentTime = 0;
    long count = _frameDelayTimes.count;
    for (int i = 0; i < count; ++i) {
        [times addObject:[NSNumber numberWithFloat:(currentTime / _totalTime)]];
        currentTime += [[_frameDelayTimes objectAtIndex:i] floatValue];
    }
    [animation setKeyTimes:times];
    
    NSMutableArray *images = [NSMutableArray arrayWithCapacity:3];
    for (int i = 0; i < count; ++i) {
        [images addObject:[_frames objectAtIndex:i]];
    }
    
    [animation setValues:images];
    [animation setTimingFunction:[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionLinear]];
    animation.duration = _totalTime;
    animation.delegate = self;
    animation.repeatCount = 5;
    animation.removedOnCompletion = NO;
    animation.fillMode = kCAFillModeForwards;
    [self.layer addAnimation:animation forKey:@"gifAnimation"];
}

- (void)stopGif
{
    [self.layer removeAllAnimations];
}

// remove contents when animation end
- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag
{
    self.layer.contents = nil;
    if(flag)
    {
        [self startGif];
    }
}


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}

- (void)dealloc
{
    [self stopGif];
    [_frames removeAllObjects];
    [_frameDelayTimes removeAllObjects];
}

-(void)setGif:(NSString*)name Bundle:(NSString*)bundle
{
    [self stopGif];
    _frames = [[NSMutableArray alloc] init];
    _frameDelayTimes = [[NSMutableArray alloc] init];
    _totalTime=0;
    _width = 0;
    _height = 0;
    
    if (name!=nil) {
        NSString *imgPath;
        if(bundle!=nil)
        {
            NSString *imgBundle=[[NSBundle mainBundle] pathForResource:bundle ofType:@"bundle"];
            imgPath=[[NSBundle bundleWithPath:imgBundle] pathForResource:imgBundle ofType:@"gif"];
        }
        else
        {
            imgPath=[[NSBundle mainBundle] pathForResource:name ofType:@"gif"];
        }
        getFrameInfo((__bridge  CFURLRef)[NSURL fileURLWithPath:imgPath], _frames, _frameDelayTimes, &_totalTime, &_width, &_height);
    }
    
    self.frame = CGRectMake(0, 0, _width, _height);
    [self startGif];
}

@end


