// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0



@protocol WFSettings

@property (readonly, nonatomic) NSString *apiVersion;
@property (readonly, nonatomic) NSSet *aqiEnabledCountryCodes;
@property (readonly, nonatomic) NSString *apiVersionFallback;
@property (readonly, nonatomic) NSUInteger networkFailedAttemptsLimit;
@property (readonly, nonatomic) NSUInteger networkSwitchExpirationTimeInSeconds;
@property (readonly, nonatomic) NSUInteger locationNumDecimalsOfPrecision;
@property (readonly, nonatomic) WFWeatherEventsConfig *weatherEventsConfig;
@property (readonly, nonatomic) NSDictionary *widgetRefreshPolicy;
@property (readonly, nonatomic) NSURL *appAnalyticsEndpointUrl;
@property (readonly, nonatomic) float dataSamplingRate;
@property (readonly, nonatomic) float telemetrySamplingRate;
@property (readonly, nonatomic) float locationGeocodingSamplingRate;
@property (readonly, nonatomic) CGFloat userIdentifierResetTimeInterval;
@property (readonly, nonatomic) CGFloat privateUserIdentifierResetTimeInterval;
@property (readonly, nonatomic) CGFloat cachedGeocodeLocationExpirationTimeInterval;
@property (readonly, nonatomic) CGFloat locationUpdateMinTimeInterval;
@property (readonly, nonatomic) CGFloat locationUpdateMinDistance;
@property (readonly, nonatomic) BOOL disableForecastRequestCancelation;
@property (readonly, nonatomic) BOOL disablePriorityForecastRequestQueue;
@property (readonly, nonatomic) BOOL loadSavedCitiesFromKVSOnly;
@property (readonly, nonatomic) BOOL disableLimitReverseGeocoding;

-(BOOL)disableForecastRequestCancelation;
-(BOOL)disableLimitReverseGeocoding;
-(BOOL)disablePriorityForecastRequestQueue;
-(BOOL)loadSavedCitiesFromKVSOnly;
-(CGFloat)cachedGeocodeLocationExpirationTimeInterval;
-(CGFloat)locationUpdateMinDistance;
-(CGFloat)locationUpdateMinTimeInterval;
-(CGFloat)privateUserIdentifierResetTimeInterval;
-(CGFloat)userIdentifierResetTimeInterval;
-(NSUInteger)locationNumDecimalsOfPrecision;
-(NSUInteger)networkFailedAttemptsLimit;
-(NSUInteger)networkSwitchExpirationTimeInSeconds;
-(float)dataSamplingRate;
-(float)locationGeocodingSamplingRate;
-(float)telemetrySamplingRate;
-(id)apiVersion;
-(id)apiVersionFallback;
-(id)appAnalyticsEndpointUrl;
-(id)aqiEnabledCountryCodes;
-(id)weatherEventsConfig;
-(id)widgetRefreshPolicy;

@end

