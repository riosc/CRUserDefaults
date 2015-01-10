//
// CRUserDefaults.h
//
// Copyright (c) 2015 Carlos Rios
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "CRUserDefaults.h"
#import "objc/runtime.h"

#define USER_DEFAULTS   [NSUserDefaults standardUserDefaults]

@implementation CRUserDefaults

+ (id)shared
{
    static dispatch_once_t pred;
    __strong static CRUserDefaults *_shared = nil;
    dispatch_once(&pred, ^{
        _shared = [CRUserDefaults new];
    });
    return _shared;
}

+ (void) save
{
    [USER_DEFAULTS synchronize];
}

+ (BOOL) resolveInstanceMethod:(SEL)sel
{
    NSString * selectorName = NSStringFromSelector(sel);
    
    if ([selectorName hasPrefix:@"set"])
        class_addMethod(self , sel, (IMP) dictionarySetter, "v@:@");
    else
        class_addMethod(self, sel, (IMP) dictionaryGetter, "@@:");
    
    return YES;
}

void dictionarySetter(id self, SEL _cmd, id value)
{
    NSString * selectorString   = NSStringFromSelector(_cmd);
    NSMutableString * key       = [selectorString mutableCopy];
    
    //remove : characters from selector key
    [key deleteCharactersInRange:NSMakeRange(key.length - 1, 1)];
    [key deleteCharactersInRange:NSMakeRange(0, 3)];
    
    NSString * lowerCaseFirstChar = [[key substringToIndex:1] lowercaseString];
    [key replaceCharactersInRange:NSMakeRange(0, 1) withString:lowerCaseFirstChar];
    
    id mValue = ([value conformsToProtocol:@protocol(NSCoding)]) ? [NSKeyedArchiver archivedDataWithRootObject:value] : value;
    
    if (value){
        [USER_DEFAULTS setObject:mValue forKey:key];
    }
    else{
        [USER_DEFAULTS removeObjectForKey:key];
    }
    
}

id dictionaryGetter(id self, SEL _cmd)
{
    NSString * key = NSStringFromSelector(_cmd);
    id file = [NSKeyedUnarchiver unarchiveObjectWithData:[USER_DEFAULTS objectForKey:key]];
    return file;
}

@end
