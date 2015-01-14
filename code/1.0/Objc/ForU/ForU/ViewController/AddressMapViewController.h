//
//  AddressMapViewController.h
//  ForU
//
//  Created by 孙昕 on 15/1/12.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "ChooseGirlViewController.h"
@interface AddressMapViewController : UIViewController
@property (strong, nonatomic) IBOutlet MKMapView *viewMap;
@property (weak,nonatomic) ChooseGirlViewController *vc;
- (IBAction)onBack:(id)sender;

@end
