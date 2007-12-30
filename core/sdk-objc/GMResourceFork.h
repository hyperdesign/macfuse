//
//  GMResourceFork.h
//  MacFUSE
//
//  Created by ted on 12/29/07.
//  Copyright 2007 Google, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GMResource;

@interface GMResourceFork : NSObject {
  NSMutableDictionary* resourcesByType_;
}
+ (GMResourceFork *)resourceFork;

- (id)init;
- (void)dealloc;

- (void)addResourceWithType:(ResType)resType
                      resID:(ResID)resID
                       name:(NSString *)name
                       data:(NSData *)data;

- (void)addResource:(GMResource *)resource;

// Constructs the raw data for the resource fork containing all added resources.
- (NSData *)data;

@end

@interface GMResource : NSObject {
  ResType resType_;  // FourCharCode, i.e. 'icns'
  ResID resID_;    // SInt16, i.e. 256 for webloc 'url ' contents.
  NSString* name_;  // Retained: The name of the resource.
  NSData* data_;  // Retained: The raw data for the resource.
}
+ (GMResource *)resourceWithType:(ResType)resType
                           resID:(ResID)resID
                            name:(NSString *)name  // May be nil
                            data:(NSData *)data;

- (id)initWithType:(ResType)resType
             resID:(ResID)resID 
              name:(NSString *)name  // May be nil
              data:(NSData *)data;
- (void)dealloc;

- (ResID)resID;
- (ResType)resType;
- (NSString *)name;
- (NSData *)data;

@end
