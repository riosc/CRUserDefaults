//
//  CRCustomDefaults.h
//  CRUserDefaults
//
//  Created by Carlos Rios on 1/9/15.
//  Copyright (c) 2015 Carlos Rios. All rights reserved.
//

#import <CRUserDefaults/CRUserDefaults.h>
#import "CRUser.h"

@interface CRCustomDefaults : CRUserDefaults

@property (nonatomic, strong) CRUser * user;


+ (CRCustomDefaults *) shared;


@end
