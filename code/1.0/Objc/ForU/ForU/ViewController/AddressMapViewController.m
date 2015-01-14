//
//  AddressMapViewController.m
//  ForU
//
//  Created by 孙昕 on 15/1/12.
//  Copyright (c) 2015年 孙昕. All rights reserved.
//

#import "AddressMapViewController.h"
#import "AddressPin.h"
#import "FULoadingView.h"
@interface AddressMapViewController ()<MKMapViewDelegate>
{
    FULoadingView *loadingView;
    CLLocationCoordinate2D *coood;
}

@end

@implementation AddressMapViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _viewMap.showsUserLocation=YES;
}

-(void)mapView:(MKMapView *)mapView didUpdateUserLocation:(MKUserLocation *)userLocation
{
    _viewMap.showsUserLocation = NO;
    MKCoordinateRegion viewRegion = MKCoordinateRegionMakeWithDistance(userLocation.coordinate, 500, 500);
    MKCoordinateRegion adjustedRegion = [_viewMap regionThatFits:viewRegion];
    [_viewMap setRegion:adjustedRegion animated:YES];
    _viewMap.delegate=self;
    MKPointAnnotation *point=[[MKPointAnnotation alloc] init];
    point.coordinate=userLocation.coordinate;
    [_viewMap addAnnotation:point];

}

-(MKAnnotationView*)mapView:(MKMapView *)mapView viewForAnnotation:(id<MKAnnotation>)annotation
{
    static NSString* key=@"AddressKey";
    AddressPin *pin=[[AddressPin alloc] initWithAnnotation:annotation reuseIdentifier:key];
    pin.delegate=self;
    pin.canShowCallout=NO;
    return pin;
}


-(void)clickPin
{
    [_vc.btnAddress setTitle:@"已选择" forState:UIControlStateNormal];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(BOOL)prefersStatusBarHidden
{
    return YES;
}

- (IBAction)onBack:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}
@end
