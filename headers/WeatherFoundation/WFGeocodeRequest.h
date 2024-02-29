// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFGEOCODEREQUEST_H
#define WFGEOCODEREQUEST_H

@class MKLocalSearchCompletion, NSString;


#import "WFTask.h"
#import "WFLocation.h"

@interface WFGeocodeRequest : WFTask

@property (retain) MKLocalSearchCompletion *autocompleteSearchResult; // ivar: _autocompleteSearchResult
@property CLLocationCoordinate2D coordinate; // ivar: _coordinate
@property (retain) WFLocation *geocodedResult; // ivar: _geocodedResult
@property (readonly) id resultHandler; // ivar: _resultHandler
@property (retain) NSString *searchString; // ivar: _searchString
@property (readonly) NSString *searchTerm;


-(id)description;
-(id)initWithCoordinate:(struct CLLocationCoordinate2D )arg0 resultHandler:(id)arg1 ;
-(id)initWithSearchCompletion:(id)arg0 resultHandler:(id)arg1 ;
-(id)initWithSearchString:(id)arg0 resultHandler:(id)arg1 ;
-(void)cleanup;
-(void)handleCancellation;
-(void)handleError:(id)arg0 forResponseIdentifier:(id)arg1 ;
-(void)handleResponse:(id)arg0 ;
-(void)startWithService:(id)arg0 ;


@end


#endif