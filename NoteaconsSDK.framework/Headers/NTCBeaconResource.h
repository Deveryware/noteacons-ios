//
//  NTCBeaconResource.h
//  Noteacon
//
//  Created by Deveryware Iberia SA on 04/11/15.
//  Copyright (c) 2015 Deveryware. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NTCBasicResource.h"
@import CoreLocation;


#if DEBUG
extern NSString * const NTCBeaconUUIDKey;
extern NSString * const NTCBeaconIdKey;
extern NSString * const NTCBeaconNameKey;
extern NSString * const NTCBeaconMajorKey;
extern NSString * const NTCBeaconMinorKey;
extern NSString * const NTCBeaconProximityKey;
#endif





/*
 * Proximity
 *
 * Discussion:
 *    Represents the current proximity of an entity.
 *
 */
typedef NS_ENUM(NSInteger, NTCProximity) {
    NTCProximityUnknown,
    NTCProximityImmediate,
    NTCProximityNear,
    NTCProximityFar
};


@interface NTCBeaconResource : NSObject

@property (nonatomic, strong, readonly) NSNumber *beaconId;
@property (nonatomic, strong, readonly) NSString *uuid;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSNumber *major;
@property (nonatomic, strong, readonly) NSNumber *minor;
@property (nonatomic, readonly) NTCProximity proximity;
@property (nonatomic, readonly) NTCCoordinates coordinates;


- (instancetype) initWithJSON:(NSDictionary *)json uuid:( NSString *)uuid;


- (instancetype) initWithId:(NSNumber *)beaconId
                       uuid:(NSString *)uuid
                       name:(NSString *)name
                      major:(NSNumber *)major
                      minor:(NSNumber *)minor
                  proximity:(NTCProximity)proximity;



- (void)setCLProximity:(CLProximity)proximity;

@end


