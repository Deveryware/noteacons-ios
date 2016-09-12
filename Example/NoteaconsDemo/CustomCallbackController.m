//
//  customCallbackController.m
//  NoteaconD
//
//  Created by Jaume Fm on 15/01/16.
//  Copyright © 2016 Deverware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CustomCallbackController.h"

@interface CustomCallbackController ()

@property (nonatomic, strong) NTCBaseActionResource *action;

@end

@implementation CustomCallbackController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void) setAction:(NTCBaseActionResource *)action {
    _action = action;
}

-(void) viewWillDisappear:(BOOL)animated {
    if ([self.navigationController.viewControllers indexOfObject:self]==NSNotFound) {
        [_action finish];
    }
    [super viewWillDisappear:animated];
}



@end
