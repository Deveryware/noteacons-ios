//
//  ViewController.m
//  NoteaconD
//
//  Created by Jaume Fm on 13/01/16.
//  Copyright © 2016 Deverware. All rights reserved.
//

#import "ViewController.h"
#import "CustomCallbackController.h"

@interface ViewController ()

@property (strong, nonatomic) NSMutableDictionary *executedCampaigns;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [Noteacons manager].initializationDelegate = self;
    [Noteacons manager].beaconEventDelegate = self;
    [Noteacons manager].campaignEventDelegate = self;
    [Noteacons manager].actionEventDelegate = self;
    [Noteacons manager].geoFenceEventDelegate = self;
    
    _executedCampaigns = [[NSMutableDictionary alloc] init];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)onReady {
    NSLog(@"On Noteacons Ready!");
}

- (void)onEnterBeacon:(NTCBeaconResource *)beacon {
    NSLog(@"onEnterBeacon");
}
- (void)onExitBeacon:(NTCBeaconResource *)beacon {
    NSLog(@"onExitBeacon");
}

- (void)onEnterGeoFence:(NTCGeofenceResource *)geoFence
{
    NSLog(@"onEnterGeofence");
}
- (void)onExitGeoFence:(NTCGeofenceResource *)geoFence
{
    NSLog(@"onExitGeofence");
}

- (IBAction)refreshData:(id)sender {
    NSLog(@"refreshData");
    [[Noteacons manager] refreshDataOnSuccess:^{
        NSLog(@"refresh Data successful");
    } onFailure:^(NSError *error) {
        NSLog(@"refresh data with error: %@", error);
    }];
}

- (BOOL)willLaunchCampaign:(NTCContextResource *)context {
    NSLog(@"willLaunchCampaign");
    return YES;
}

- (void)didLaunchCampaign:(NTCContextResource *)context {
    NSLog(@"didLaunchCampaign");
}
- (BOOL)onExecuteCustomCallbackAction:(NTCBaseActionResource *)action withFunctionName:(NSString *)functionName withParams:(NSString *)params {
    NSLog(@"Custom Callback action with name: %@", functionName);
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle: nil];
    CustomCallbackController * vc = [storyboard instantiateViewControllerWithIdentifier:@"customCallbackView"];
    [vc setAction:action];
    [[self navigationController] showViewController:vc sender:nil];
    return NO;
}

- (BOOL)onExecuteMessageAction:(NTCBaseActionResource *)action withTitle:(NSString *)title withMessage:(NSString *)message {
    NSLog(@"onExecuteMessageAction");
    return YES;
}

@end
