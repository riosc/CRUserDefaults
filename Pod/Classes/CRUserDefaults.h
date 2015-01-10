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


#import <Foundation/Foundation.h>
/**
 * CRUserDefaults is helper class that offers a interface to write data on
 * [NSUserDefaults standardUserDefaults]. The distinctive value CRUserDefaults has
 * is allows that standardUserDefaults acts as an object, so you only have to add
 * properties to it, then declare this property as @dynamic and automatically you 
 * a new property in standardUserDefaults.
 *
 * Also you can declare a property of any object type and it will be store too, but 
 * you should implement NSCoding protocol for custom objects.
 *
 * The only concern is all property have to be Object pointers, so if you are going
 * to declare boolean property you must declare it as NSNumber.
 *
 * ## How to use?
 *
 * Simple, implements a subclass of this and add properties to it. Remember declare
 * all properties as @dynamic in the implementation file.
 * 
 * ### Subclasing
 * ```
 * @interface CRCustomDefaults : CRUserDefaults
 *
 * @property (nonatomic, strong) USer * current;
 *
 * + (CRCustomDefaults *) shared;
 *
 * @end
 * 
 * @implementation CRUserDefaults
 * @dynamic current;
 * 
 * + (CRCustomDefaults *) shared
 * {
 *      return [super shared];
 * }
 * @end
 * ```
 *
 * ### User class implementing NSCoding Protocol
 *
 * @interface CRUser : NSObject <NSCoding>
 *
 * @property (nonatomic, copy) NSString * name;
 * @property (nonatomic, copy) NSString * lastName;
 * @property (nonatomic, copy) NSString * email;
 * @property (nonatomic, copy) NSNumber * age;
 *
 *
 * - (instancetype)initWithName:(NSString *)name lastName:(NSString *)lastName;
 *
 * @end
 * 
 * @implementation CRUser
 *
 *
 * - (instancetype)initWithName:(NSString *)name lastName:(NSString *)lastName
 * {
 *  self = [super init];
 *  if (self) {
 *      _name = [name copy];
 *      _lastName = [lastName copy];
 *  }
 *   return self;
 * }
 *
 *
 * -(id) initWithCoder:(NSCoder *) aDecoder
 * {
 *      _name = [aDecoder decodeObjectForKey:knameKey];
 *      _lastName = [aDecoder decodeObjectForKey:klastNameKey];
 *      _email = [aDecoder decodeObjectForKey:kemailKey];
 *      _age = [aDecoder decodeObjectForKey:kageKey];
 *
 *      return self;
 * }
 *
 * -(void) encodeWithCoder:(NSCoder *) encoder
 * {
 *      [encoder encodeObject:_name forKey:knameKey];
 *      [encoder encodeObject:_lastName forKey:klastNameKey];
 *      [encoder encodeObject:_email forKey:kemailKey];
 *      [encoder encodeObject:_age forKey:kageKey];
 * }
 *
 * @end
 *
 *
 */
@interface CRUserDefaults : NSObject

/**
 *  Create a singleton instance of CRUserDefaults
 *
 *  @return A current CRUserDefaults instance
 */
+ (id)shared;

/**
 * Save data on [NSUserDefaults standardUserDefaults] dictionary. Actually, This
 * methods only execute (void)synchronize rutine of NSUserDefaults standardUserDefaults].
 */
+ (void) save;


@end
