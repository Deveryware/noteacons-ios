//
//  NTCBaseActionResource.h
//  NoteaconsSDK
//
//  Created by Deveryware Iberia SA on 02/12/15.
//  Copyright © 2015 Deveryware Iberia SA. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NTCBaseActionBuilder <NSObject>
@required

- (void)setCampaignId:(NSNumber *)campaignId;
- (void)setId:(NSNumber *)id;
- (void)setType:(NSString *)type;

@end


@interface NTCBaseActionResource : NSObject <NTCBaseActionBuilder>

@property (nonatomic, strong, readonly) NSNumber *id;
@property (nonatomic, strong, readonly) NSNumber *campaignId;
@property (nonatomic, strong, readonly) NSString *type;
@property (nonatomic, strong) dispatch_block_t completionBlock;


- (void)execute;
- (void)finish;
- (void)dismissWithCompletion:(dispatch_block_t)completionBlock;

+ (NTCBaseActionResource *)build:(void(^)(id<NTCBaseActionBuilder>builder))buildBlock;

@end






