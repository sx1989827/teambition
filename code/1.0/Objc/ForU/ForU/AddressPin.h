//
//  AddressPin.h
//  ForU
//
//  Created by 孙昕 on 15/1/13.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import <MapKit/MapKit.h>

@interface AddressPin : MKPinAnnotationView
@property(weak,nonatomic) id delegate;
- (id)initWithAnnotation:(id<MKAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier;
;

@end
