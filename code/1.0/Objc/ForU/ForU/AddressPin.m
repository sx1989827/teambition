//
//  AddressPin.m
//  ForU
//
//  Created by 孙昕 on 15/1/13.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "AddressPin.h"

@implementation AddressPin

- (id)initWithAnnotation:(id<MKAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithAnnotation:annotation reuseIdentifier:reuseIdentifier];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        self.frame = CGRectMake(0, 0, 100, 45);
        UIButton *btn=[UIButton buttonWithType:UIButtonTypeCustom];
       // btn.backgroundColor=[UIColor yellowColor];
        [btn setTitle:@"确定住址" forState:UIControlStateNormal];
        [btn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        CGRect frame=self.bounds;
        frame.size.height-=15;
        btn.frame=frame;
        [self addSubview:btn];
        [btn addTarget:self.delegate action:@selector(clickPin) forControlEvents:UIControlEventTouchUpInside];
    }
    
    return self;
}


-(void)drawBackground:(CGContextRef)context
{
    CGContextSetLineWidth(context, 2.0);
    CGContextSetFillColorWithColor(context, [UIColor whiteColor].CGColor);
    [self drawArrowBoundPath:context];
    CGContextFillPath(context);
    
}
- (void)drawArrowBoundPath:(CGContextRef)context
{
    CGRect rrect = self.bounds;
    CGFloat radius = 6.0;
    
    CGFloat minx = CGRectGetMinX(rrect),
    midx = CGRectGetMidX(rrect),
    maxx = CGRectGetMaxX(rrect);
    CGFloat miny = CGRectGetMinY(rrect),
    maxy = CGRectGetMaxY(rrect)-15;
    CGContextMoveToPoint(context, midx+15, maxy);
    CGContextAddLineToPoint(context,midx, maxy+15);
    CGContextAddLineToPoint(context,midx-15, maxy);
    
    CGContextAddArcToPoint(context, minx, maxy, minx, miny, radius);
    CGContextAddArcToPoint(context, minx, minx, maxx, miny, radius);
    CGContextAddArcToPoint(context, maxx, miny, maxx, maxx, radius);
    CGContextAddArcToPoint(context, maxx, maxy, midx, maxy, radius);
    CGContextClosePath(context);
}

- (void)drawRect:(CGRect)rect
{
    [self drawBackground:UIGraphicsGetCurrentContext()];
    
    self.layer.shadowColor = [[UIColor blackColor] CGColor];
    self.layer.shadowOpacity = 1.0;
    self.layer.shadowOffset = CGSizeMake(-0.5f, 0.5f);
}
@end
