// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0



@protocol WFFavoriteLocationProvider

@property (weak, nonatomic) NSObject<WFFavoriteLocationProviderDelegate> *delegate;

-(NSObject<WFFavoriteLocationProviderDelegate> *)delegate;
-(id)initWithDelegate:(NSObject<WFFavoriteLocationProviderDelegate> *)arg0 persistence:(id)arg1 ;
-(id)locations;
-(void)addLocation:(id)arg0 ;
-(void)removeLocation:(id)arg0 ;
-(void)setDelegate:(NSObject<WFFavoriteLocationProviderDelegate> *)arg0 ;
-(void)setLocations:(id)arg0 ;

@optional
-(id)migrationOperation;
@end

