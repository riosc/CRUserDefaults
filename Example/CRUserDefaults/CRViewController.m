//
//  CRViewController.m
//  CRUserDefaults
//
//  Created by Carlos Rios on 01/09/2015.
//  Copyright (c) 2014 Carlos Rios. All rights reserved.
//

#import "CRViewController.h"
#import "CRCustomDefaults.h"

@interface CRViewController ()

@end

@implementation CRViewController

- (void)viewDidLoad
{
    CRUser * userLocal = [[CRUser alloc] initWithName:@"Carlos" lastName:@"Rios"];
    [CRCustomDefaults shared].user = userLocal;
    [[CRUserDefaults class] save];
    
    
    NSLog(@"User Name: %@", [CRCustomDefaults shared].user.name);
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
