//
//  TalkContentView.h
//  ForU
//
//  Created by 孙昕 on 15/2/14.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TalkContentView;
@protocol TalkContentViewDelegate<NSObject>
-(void)TalkContentViewClicked:(TalkContentView*)view Text:(NSString*)text;
@end
@interface TalkContentView : UIView
@property (strong, nonatomic) IBOutlet UIImageView *imgHead;
@property (strong, nonatomic) IBOutlet UILabel *lbName;
@property (strong, nonatomic) IBOutlet UILabel *lbContent;
@property (weak,nonatomic) id<TalkContentViewDelegate> delegate;
-(void)setGirlContentText:(NSString*)text AfterDiss:(double)diss DissCompleteBlock:(void (^)())block;
-(void)setPlayerContentText:(NSString*)text AfterDiss:(double)diss DissCompleteBlock:(void (^)())block;
@end
