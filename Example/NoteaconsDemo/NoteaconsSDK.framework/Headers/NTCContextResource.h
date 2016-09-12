//
//  NTCContextResource.h
//  NoteaconsSDK
//
//  Created by Deveryware Iberia SA on 01/12/15.
//  Copyright © 2015 Deveryware Iberia SA. All rights reserved.
//

#import <Foundation/Foundation.h>


#define kNTCContextCampaignIdKey (@"campaignId")
#define kNTCContextBeaconIdKey (@"beaconId")
#define kNTCContextContextIdKey (@"contextId")
#define kNTCContextGeofenceIdKey (@"geofenceId")
#define kNTCContextCampaignNameKey (@"campaignName")

@interface NTCContextResource : NSObject

@property (nonatomic, strong) NSNumber * contextId;
@property (nonatomic, strong) NSNumber * campaignId;
@property (nonatomic, strong) NSNumber * beaconId;
@property (nonatomic, strong) NSNumber * geofenceId;
@property (nonatomic, strong) NSString * campaignName;

- (instancetype)initWithCampaignId:(NSNumber *)campaignId beaconId:(NSNumber *)beaconId;
- (instancetype)initWithCampaignId:(NSNumber *)campaignId geofenceId:(NSNumber *)geofenceId;
- (instancetype)initWithJSON:(NSDictionary *)json;

- (NSDictionary *)generateJSON;

- (BOOL)isEqualToContext:(NTCContextResource *)context;

@end
