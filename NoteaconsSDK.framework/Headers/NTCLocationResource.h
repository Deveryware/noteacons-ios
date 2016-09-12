//
//  NTCLocationResource.h
//  Noteacon
//
//  Created by Deveryware Iberia SA on 06/11/15.
//  Copyright © 2015 Deveryware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTCBasicResource.h"


/*!
 @typedef NTCLocationDistance
 
 @discussion:
 */
typedef double NTCLocationDistance;

/*!
 @typedef NTCLocationDegrees
 
 @discussion:
 Type used to represent a latitude or longitude coordinate in degrees under the WGS 84 reference frame. The degree can be positive (North and East) or negative (South and West).
 */
typedef double NTCLocationDegrees;

@interface NTCLocationResource : NSObject

@property (nonatomic) double latitude;
@property (nonatomic) double longitude;


- (instancetype)initWithLatitude:(NTCLocationDegrees)latitude longitude:(NTCLocationDegrees)longitude;

/*!
 @brief Returns the distance (in meters) from the receiver’s location to the specified location
 
 @discussion
 This method measures the distance between the two locations by tracing a line between them that follows the curvature of the Earth. The resulting arc is a smooth curve and does not take into account specific altitude changes between the two locations.
 
 It is based on the equal named method of the class CLLocation.
 
 In case of not receiving a valid location, it returns 0.
 
 @params location the other location

 */

- (NTCLocationDistance) distanceFromLocation:(NTCLocationResource *)location;

- (BOOL)isNoLocation;

@end
