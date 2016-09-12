//
//  NTCCampaignResource.h
//  Noteacon
//
//  Created by Deveryware Iberia SA on 04/11/15.
//  Copyright (c) 2015 Deveryware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTCBasicResource.h"


#define NTCCampaignNameKey (@"name")
#define NTCCampaignLeadKey (@"lead")
#define NTCCampaignIdKey (@"id")
#define NTCCampaignStartKey (@"start")
#define NTCCampaignFinishKey (@"finish")
#define NTCCampaignActiveKey (@"active")
#define NTCCampaignDeliverBgKey (@"deliver_bg")
#define NTCCampaignDeliverFgKey (@"deliver_fg")


@interface NTCCampaignResource : NSObject

@property (nonatomic, strong, readonly) NSDate *start;
@property (nonatomic, strong, readonly) NSDate *finish;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *lead;
@property (nonatomic, readonly) BOOL deliverBg;
@property (nonatomic, readonly) BOOL deliverFg;
@property (nonatomic, strong, readonly) NSNumber *campaignId;

- (instancetype)initWithJSON:(NSDictionary *)json;
- (instancetype)initWithName:(NSString *)name
                  campaignId:(NSNumber *)campaignId
                       start:(NSDate *)start
                      finish:(NSDate *)finish
                   deliverBg:(BOOL)deliverBg
                   deliverFg:(BOOL)deliverFg
                        lead:(NSString *)lead;

- (BOOL)isCampaignActiveNow;

@end
