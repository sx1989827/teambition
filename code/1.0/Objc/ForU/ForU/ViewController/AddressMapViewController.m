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
    CLLocationManager *cl;
}

@end

@implementation AddressMapViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    if([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
    {
        cl=[[CLLocationManager alloc] init];
        [cl requestAlwaysAuthorization];
        [cl requestWhenInUseAuthorization];
    }
    _viewMap.showsUserLocation=YES;
    UITapGestureRecognizer *tap=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(addAnnotation:)];
    [self.viewMap addGestureRecognizer:tap];
}

-(void)addAnnotation:(UITapGestureRecognizer*)tap
{
    CGPoint touchPoint = [tap locationInView:_viewMap];
    CLLocationCoordinate2D touchMapCoordinate =[_viewMap convertPoint:touchPoint toCoordinateFromView:_viewMap];
    [_viewMap removeAnnotation:_viewMap.annotations[0]];
    MKPointAnnotation *anno=[[MKPointAnnotation alloc] init];
    anno.coordinate=touchMapCoordinate;
    anno.title=@"确定住址";
    [_viewMap addAnnotation:anno];
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
    _vc.cood=((MKPointAnnotation*)_viewMap.annotations[0]).coordinate;
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
