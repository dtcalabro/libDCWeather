// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


#ifndef WFWEATHERSTORESERVICECONFIGURATION_H
#define WFWEATHERSTORESERVICECONFIGURATION_H

@class NSString, NSURL, NWPathEvaluator, NSURLSession;

#import <Foundation/Foundation.h>

#import "WFSettingsManager.h"
#import "NSURLSessionTaskDelegate-Protocol.h"
#import "NSCopying-Protocol.h"

@interface WFWeatherStoreServiceConfiguration : NSObject <NSURLSessionTaskDelegate, NSCopying>



@property (readonly, nonatomic) NSString *apiVersion;
@property (retain, nonatomic) Class cacheClass; // ivar: _cacheClass
@property (copy, nonatomic) NSURL *cacheURL; // ivar: _cacheURL
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly, nonatomic) BOOL isServiceAvailable;
@property (readonly, nonatomic) BOOL isValid;
@property (retain, nonatomic) NSURL *serviceConnectivityEvaluationURL; // ivar: _serviceConnectivityEvaluationURL
@property (nonatomic) os_unfair_lock_s serviceConnectivityEvaluationURLLock; // ivar: _serviceConnectivityEvaluationURLLock
@property (readonly, nonatomic) NWPathEvaluator *serviceConnectivityEvaluator; // ivar: _serviceConnectivityEvaluator
@property (nonatomic) os_unfair_lock_s serviceConnectivityEvaluatorLock; // ivar: _serviceConnectivityEvaluatorLock
@property (retain, nonatomic) NSURLSession *session; // ivar: _session
@property (retain, nonatomic) WFSettingsManager *settingsManager; // ivar: _settingsManager
@property (readonly) Class superclass;


+(id)defaultConfiguration;
+(id)defaultConfigurationWithSourceBundleIdentifier:(id)arg0 ;
+(id)generateUserAgent;
-(id)apiConfiguration;
-(id)apiConfigurationForAPIVersion:(id)arg0 ;
-(id)aqiScaleRequestForScaleNamed:(id)arg0 language:(id)arg1 error:(id*)arg2 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)forecastRequestForTypes:(NSUInteger)arg0 location:(id)arg1 date:(id)arg2 apiVersion:(id)arg3 error:(id*)arg4 ;
-(id)forecastRequestForTypes:(NSUInteger)arg0 location:(id)arg1 date:(id)arg2 error:(id*)arg3 ;
-(id)forecastRequestForTypes:(NSUInteger)arg0 location:(id)arg1 units:(int)arg2 date:(id)arg3 apiVersion:(id)arg4 error:(id*)arg5 ;
-(id)forecastRequestForTypes:(NSUInteger)arg0 location:(id)arg1 units:(int)arg2 date:(id)arg3 apiVersion:(id)arg4 error:(id*)arg5 requestOptions:(id)arg6 ;
-(id)init;
-(id)parseAQIScaleNamed:(id)arg0 data:(id)arg1 apiVersion:(id)arg2 error:(id*)arg3 ;
-(id)parseForecast:(NSUInteger)arg0 data:(id)arg1 location:(id)arg2 units:(int)arg3 locale:(id)arg4 date:(id)arg5 apiVersion:(id)arg6 error:(id*)arg7 ;
-(id)parseForecast:(NSUInteger)arg0 data:(id)arg1 location:(id)arg2 units:(int)arg3 locale:(id)arg4 date:(id)arg5 error:(id*)arg6 ;
-(void)URLSession:(id)arg0 task:(id)arg1 didFinishCollectingMetrics:(id)arg2 ;
-(void)invalidate;


@end


#endif