//
//  NTCGeofenceResource.h
//  NoteaconsSDK
//
//  Created by David Jambrina Argüelles on 16/02/16.
//  Copyright © 2016 Deveryware Iberia SA. All rights reserved.
//

#import "NTCLocationResource.h"

@import CoreLocation;

#define NTCGeofenceIdKey (@"id")
#define NTCRadiusKey (@"radius")
#define NTCCenterKey (@"location")
#define NTCGeofenceNameKey (@"name")
#define NTCNoDistance (99999999) //An imposible value for geofence distances. Ecuador is 40075KM, so 99999KM is an imposible value.

typedef double NTCGeofenceDistance;




@interface NTCGeofenceResource : NTCBasicResource

@property (nonatomic, strong, readonly) NSNumber *geofenceId;
@property (nonatomic, strong, readonly) NSNumber *radius;
@property (nonatomic, strong, readonly) NTCLocationResource *center;
@property (nonatomic, strong, readonly) NSString *name;



- (instancetype) initWithId:(NSNumber *)geofenceId
                     center:(NTCCoordinates)center
                     radius:(NSNumber *)radius
                       name:(NSString *)name;

- (instancetype) initWithJSON:(NSDictionary *)json;


/*!
 @brief calculate the nearest distance of any point of a geofence to a location.
 
 @discussion
 To calculate the nearest distance of any point of a geofence to a location, we perform two steps:
    - distance between the location and the center of the geofence.
    - substracting to that distance, the radius of the geofence
 
 @param location point to which calculate the nearest distance of a geofence.
 */
- (NTCGeofenceDistance) distanceToLocation:(NTCLocationResource *)location;

@end



@interface CLCircularRegion(NTCGeofence)

+ (CLCircularRegion *)circularRegionFromNTCGeofence:(NTCGeofenceResource *)geofence;

@end
