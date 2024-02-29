// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFLOCATIONQUERYGEOCODE_H
#define WFLOCATIONQUERYGEOCODE_H

@class NSString, CLGeocoder, MKLocalSearch, MKLocalSearchCompletion;

#import <Foundation/Foundation.h>

#import "WFTaskIdentifier.h"
#import "WFResponse.h"
#import "WFLocationQuery-Protocol.h"

@interface WFLocationQueryGeocode : NSObject <WFLocationQuery>

 {
    BOOL _finished;
}


@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (retain) WFTaskIdentifier *identifier; // ivar: identifier
@property (retain) WFResponse *response; // ivar: _response
@property (copy) id resultHandler; // ivar: _resultHandler
@property (retain, nonatomic) CLGeocoder *reverseGeocoder; // ivar: _reverseGeocoder
@property (retain, nonatomic) MKLocalSearch *search; // ivar: _search
@property (readonly) MKLocalSearchCompletion *searchCompletion; // ivar: _searchCompletion
@property (nonatomic) CLLocationCoordinate2D searchCoordinate; // ivar: _searchCoordinate
@property (readonly) NSString *searchString; // ivar: _searchString
@property (readonly) Class superclass;
@property (nonatomic) CLLocationCoordinate2D unshiftedCoordinate; // ivar: _unshiftedCoordinate


+(id)queryWithCoordinate:(struct CLLocationCoordinate2D )arg0 resultHandler:(id)arg1 ;
+(id)queryWithDictionaryRepresentation:(id)arg0 resultHandler:(id)arg1 ;
+(id)queryWithSearchCompletion:(id)arg0 resultHandler:(id)arg1 ;
+(id)queryWithSearchString:(id)arg0 resultHandler:(id)arg1 ;
+(void)invalidateCaches;
-(BOOL)isLocationValid:(id)arg0 ;
-(id)_mkLocalSearchRequest;
-(id)initWithCoordinate:(struct CLLocationCoordinate2D )arg0 resultHandler:(id)arg1 ;
-(id)initWithSearchCompletion:(id)arg0 resultHandler:(id)arg1 ;
-(id)initWithSearchString:(id)arg0 resultHandler:(id)arg1 ;
-(void)_handleErrorResponse:(id)arg0 ;
-(void)_startCLGeocoderReverseGeo;
-(void)_startMKLocalSearch;
-(void)cancel;
-(void)handleSearchResponseWithLocation:(id)arg0 ;
-(void)start;


@end


#endif