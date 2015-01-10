//
//  CRUser.h
//  CRUserDefaults
//
//  Created by Carlos Rios on 1/9/15.
//  Copyright (c) 2015 Carlos Rios. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CRUser : NSObject <NSCoding>

@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSString * lastName;
@property (nonatomic, copy) NSString * email;
@property (nonatomic, copy) NSNumber * age;


- (instancetype)initWithName:(NSString *)name
                    lastName:(NSString *)lastName;

@end
