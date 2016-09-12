//
//  Noteacons.h
//  Noteacon
//
//  Created by Deveryware Iberia SA on 04/11/15.
//  Copyright (c) 2015 Deveryware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTCBeaconResource.h"
#import "NTCCampaignResource.h"
#import "NTCContextResource.h"
#import "NTCGeofenceResource.h"
#import "NTCBaseActionResource.h"
@import UIKit;


/*!
 @typedef NTCSuccessBlock.
 
 @discussion
 Block executed by Noteacons when the response has been a success.
  */
typedef void (^NTCSuccessBlock)();


/*!
 @typedef NTCFailureBlock.
 
 @discussion
 Block executed by Noteacons when an error has happened.
 
 @field error NSError object with information of the failure.
 */
typedef void (^NTCFailureBlock)(NSError *error);


@protocol NTCInitializationDelegate <NSObject>

@optional
- (void)onReady;

@end


@protocol NTCBeaconEventDelegate <NSObject>

@optional
- (void)onEnterBeacon:(NTCBeaconResource *)beacon;
- (void)onExitBeacon:(NTCBeaconResource *)beacon;

@end

@protocol NTCGeoFenceEventDelegate <NSObject>

@optional
- (void)onEnterGeoFence:(NTCGeofenceResource *)geoFence;
- (void)onExitGeoFence:(NTCGeofenceResource *)geoFence;

@end


@protocol NTCCampaignEventDelegate <NSObject>

@optional
- (BOOL)willLaunchCampaign:(NTCContextResource *)context;
- (void)didLaunchCampaign:(NTCContextResource *)context;

@end


@protocol NTCActionEventDelegate <NSObject>

@optional
- (BOOL)onExecuteCustomCallbackAction:(NTCBaseActionResource *)action withFunctionName:(NSString *)functionName withParams:(NSString *)params;
- (BOOL)onExecuteMessageAction:(NTCBaseActionResource *)action withTitle:(NSString *)title withMessage:(NSString *)message;

@end



@interface Noteacons : NSObject

/// Delegate objects that will receive notifications from Noteacons SDK
@property (nonatomic, weak) id<NTCInitializationDelegate> initializationDelegate;
@property (nonatomic, weak) id<NTCBeaconEventDelegate> beaconEventDelegate;
@property (nonatomic, weak) id<NTCCampaignEventDelegate> campaignEventDelegate;
@property (nonatomic, weak) id<NTCActionEventDelegate> actionEventDelegate;
@property (nonatomic, weak) id<NTCGeoFenceEventDelegate> geoFenceEventDelegate;

+(Noteacons *)manager;


#pragma mark - SDK API

-(void)startSDKWithApiKey:(NSString *)apiKey
                apiSecret:(NSString *)apiSecret;

- (void)didReceiveLocalNotification:(UILocalNotification *)notification;


/*!
 @brief instant method for asking the refresh of data
 
 @discussion
 The SDK make use of data downloaded from the backend for knowing which beacons have to be listened, what triggers have to be watch and which campaigns and actions have to be launched.
 refreshData is a way of asking from the client app to reload all that data on demand, to be update with the backend.
 */
- (void)refreshDataOnSuccess:(NTCSuccessBlock)success onFailure:(NTCFailureBlock)failure;


#pragma mark - Delegates´ getters and setters
- (void)setInitializationDelegate:(id<NTCInitializationDelegate>)initializationDelegate;
- (void)setBeaconEventDelegate:(id<NTCBeaconEventDelegate>)beaconEventDelegate;
- (void)setCampaignEventDelegate:(id<NTCCampaignEventDelegate>)campaignEventDelegate;
- (void)setActionEventDelegate:(id<NTCActionEventDelegate>)actionEventDelegate;

/*!
 @brief API method for knowing the id assigned to the device in the platform
 @return id assigned to the device. In case, that this method had been asked before the SDK had notified it is ready, it would return -1
 */
- (NSInteger)getDeviceId;

/*!
 @brief Starts launching campaigns and tracking visits.
 */
- (void)startSDK;

/*!
 @brief Stops launching campaigns and tracking visits.
 */
- (void)stopSDK;


@end
