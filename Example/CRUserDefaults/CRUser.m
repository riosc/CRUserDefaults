//
//  CRUser.m
//  CRUserDefaults
//
//  Created by Carlos Rios on 1/9/15.
//  Copyright (c) 2015 Carlos Rios. All rights reserved.
//

#import "CRUser.h"

static NSString * const knameKey = @"name";
static NSString * const klastNameKey = @"lastName";
static NSString * const kemailKey = @"email";
static NSString * const kageKey = @"age";


@implementation CRUser


- (instancetype)initWithName:(NSString *)name lastName:(NSString *)lastName
{
    self = [super init];
    if (self) {
        _name = [name copy];
        _lastName = [lastName copy];
    }
    return self;
}


-(id) initWithCoder:(NSCoder *) aDecoder
{
    _name = [aDecoder decodeObjectForKey:knameKey];
    _lastName = [aDecoder decodeObjectForKey:klastNameKey];
    _email = [aDecoder decodeObjectForKey:kemailKey];
    _age = [aDecoder decodeObjectForKey:kageKey];
    
    return self;
}

-(void) encodeWithCoder:(NSCoder *) encoder
{
    [encoder encodeObject:_name forKey:knameKey];
    [encoder encodeObject:_lastName forKey:klastNameKey];
    [encoder encodeObject:_email forKey:kemailKey];
    [encoder encodeObject:_age forKey:kageKey];
}

@end
