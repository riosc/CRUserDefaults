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
 * [NSUserDefaults standardUserDefaults]. The distinctive value CRUserDefaults has,
 * is allows that standardUserDefaults acts as an object, so you only have to add
 * properties to it, then declare this property as @dynamic and automatically you 
 * have a new property in standardUserDefaults.
 *
 * Also you can declare a property of any object type and it will be store too, but 
 * you should implement NSCoding protocol for custom objects.
 *
 * The only concern is all property have to be Object pointers, so if you are going
 * to declare boolean property you must declare it as NSNumber.
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
