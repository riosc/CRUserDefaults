# CRUserDefaults

[![CI Status](http://img.shields.io/travis/Carlos Rios/CRUserDefaults.svg?style=flat)](https://travis-ci.org/Carlos Rios/CRUserDefaults)
[![Version](https://img.shields.io/cocoapods/v/CRUserDefaults.svg?style=flat)](http://cocoadocs.org/docsets/CRUserDefaults)
[![License](https://img.shields.io/cocoapods/l/CRUserDefaults.svg?style=flat)](http://cocoadocs.org/docsets/CRUserDefaults)
[![Platform](https://img.shields.io/cocoapods/p/CRUserDefaults.svg?style=flat)](http://cocoadocs.org/docsets/CRUserDefaults)

`CRUserDefaults` is helper class that offers a interface to write data on
 `[NSUserDefaults standardUserDefaults]`. The distinctive value `CRUserDefaults` has,
 is allows that standardUserDefaults acts as an object, so you only have to add
 properties to it, then declare this property as @dynamic and automatically you 
 have a new property in standardUserDefaults.
 
 Also you can declare a property of any object type and it will be store too, but 
 you should implement `NSCoding` protocol for custom objects.
 
 The only concern is all property have to be Object pointers, so if you are going
 to declare boolean property you must declare it as `NSNumber`.

### Why use `CRUserDefaults` 

1. Because with `CRUserDefaults` you can keep encapsulated the data store in NSUserDefault in only one place.
2. Because offers better documentation to other developers what are the Global Variables of your app.
3. Because it acts as interface to store you custom data, and you don't worry about how it store information and how load it.
4. Because you can use this class as caching mechanism,

## Usage

 Simple, implements a subclass of this and add properties to it. Remember declare
 all properties as @dynamic in the implementation file.
 
### Subclasing
 ```Objective-C
 @interface CRCustomDefaults : CRUserDefaults
 
 @property (nonatomic, strong) USer current;
 
 + (CRCustomDefaults *) shared;
 
 @end
 
 @implementation CRUserDefaults
 @dynamic current;
 
 + (CRCustomDefaults *) shared
 {
      return [super shared];
 }
 @end
 ```
 
### User class implementing NSCoding Protocol
 If you want store a custom object in `CRUserDefaults`, you must implement `NSCoding` protocol on it. Look at next example of a `CRUser` class. 
 ```Objective-C
 @interface CRUser : NSObject <NSCoding>
 
 @property (nonatomic, copy) NSString name;
 @property (nonatomic, copy) NSString lastName;
 @property (nonatomic, copy) NSString email;
 @property (nonatomic, copy) NSNumber age;
 
 - (instancetype)initWithName:(NSString *)name lastName:(NSString *)lastName;
 
 @end
 
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
```
To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements
iOS 5 or higher.

## Installation

CRUserDefaults is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

    pod "CRUserDefaults"
    
## Author

Carlos Rios, rioscarlosd@gmail.com

## License

CRUserDefaults is available under the MIT license. See the LICENSE file for more info.

