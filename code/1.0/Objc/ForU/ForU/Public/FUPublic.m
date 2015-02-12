
//  FUPublic.m
//  ForU
//
//  Created by 孙昕 on 15/1/19.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "FUPublic.h"
#import <objc/runtime.h>
#import <objc/objc.h>
#import "AppDelegate.h"
@implementation UILabel (CustomeFont)
+(void)load
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class cls = [UILabel class];
        
        // When swizzling a class method, use the following:
        // Class class = object_getClass((id)self);
        
        SEL originalSelector = @selector(willMoveToSuperview:);
        SEL swizzledSelector = @selector(myWillMoveToSuperview:);
        
        Method originalMethod = class_getInstanceMethod(cls, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(cls, swizzledSelector);
        
        BOOL didAddMethod =
        class_addMethod(cls,
                        originalSelector,
                        method_getImplementation(swizzledMethod),
                        method_getTypeEncoding(swizzledMethod));
        
        if (didAddMethod) {
            class_replaceMethod(cls,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}

-(void)myWillMoveToSuperview:(UIView *)newSuperview
{
    [self myWillMoveToSuperview:newSuperview];
    if(newSuperview!=nil)
    [self setFont:[UIFont fontWithName:@"RTWS YueRoundedGothic Demo" size:self.font.pointSize]];
}

@end
@implementation UIButton (CustomeFont)
+(void)load
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class cls = [UIButton class];
        
        // When swizzling a class method, use the following:
        // Class class = object_getClass((id)self);
        
        SEL originalSelector = @selector(willMoveToSuperview:);
        SEL swizzledSelector = @selector(myWillMoveToSuperview:);
        
        Method originalMethod = class_getInstanceMethod(cls, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(cls, swizzledSelector);
        
        BOOL didAddMethod =
        class_addMethod(cls,
                        originalSelector,
                        method_getImplementation(swizzledMethod),
                        method_getTypeEncoding(swizzledMethod));
        
        if (didAddMethod) {
            class_replaceMethod(cls,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}
-(void)myWillMoveToSuperview:(UIView *)newSuperview
{
    [self myWillMoveToSuperview:newSuperview];
    if(newSuperview!=nil)
    [self.titleLabel setFont:[UIFont fontWithName:@"RTWS YueRoundedGothic Demo" size:self.titleLabel.font.pointSize]];
}

@end
@implementation UIImageView (LoadImage)


-(void)setPlaceImg:(NSString*)name
{
    NSMutableDictionary* dic=[[NSMutableDictionary alloc] initWithCapacity:30];
    [dic setObject:@3 forKey:@"餐厅"];
    [dic setObject:@4 forKey:@"公园"];
    [dic setObject:@3 forKey:@"游乐场"];
    [dic setObject:@2 forKey:@"电影院"];
    [dic setObject:@4 forKey:@"家"];
    [dic setObject:@3 forKey:@"公司"];
    NSString *strBundle=[[NSBundle mainBundle] pathForResource:@"Image" ofType:@"bundle"];
    NSString* strImg=[[NSBundle bundleWithPath:strBundle] pathForResource:[NSString stringWithFormat:@"%@%ld",name,random()%[dic[name] integerValue]+1] ofType:@"jpg" inDirectory:@"scene"];
    UIImage *img=[UIImage imageWithContentsOfFile:strImg];
    self.image=img;
}

-(void)setGirlImg:(NSString*)name
{
    GIRLTYPE type=[APP GetGirlType];
    NSString *strType;
    switch(type)
    {
        case LOLI:
        {
            strType=@"loli";
            break;
        }
        case MAID:
        {
            strType=@"maid";
            break;
        }
        case QUEEN:
        {
            strType=@"queen";
            break;
        }
    }
    NSString *strBundle=[[NSBundle mainBundle] pathForResource:@"Image" ofType:@"bundle"];
    NSString* strImg=[[NSBundle bundleWithPath:strBundle] pathForResource:name ofType:@"png" inDirectory:[NSString stringWithFormat:@"girl/%@",strType]];
    UIImage *img=[UIImage imageWithContentsOfFile:strImg];
    self.image=img;
}

@end

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
