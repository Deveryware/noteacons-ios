//
//  ViewController.h
//  NoteaconD
//
//  Created by Jaume Fm on 13/01/16.
//  Copyright © 2016 Deverware. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NoteaconsSDK/NoteaconsSDK.h>


@interface ViewController : UIViewController <NTCInitializationDelegate, NTCBeaconEventDelegate, NTCCampaignEventDelegate, NTCActionEventDelegate, NTCGeoFenceEventDelegate>


@end

