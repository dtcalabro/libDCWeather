// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0


@protocol CLLocationManagerDelegate

@optional
-(BOOL)locationManagerShouldDisplayHeadingCalibration:(id)arg0 ;
-(void)locationManager:(id)arg0 didChangeAuthorizationStatus:(int)arg1 ;
-(void)locationManager:(id)arg0 didDetermineState:(NSInteger)arg1 forRegion:(id)arg2 ;
-(void)locationManager:(id)arg0 didEnterRegion:(id)arg1 ;
-(void)locationManager:(id)arg0 didExitRegion:(id)arg1 ;
-(void)locationManager:(id)arg0 didFailRangingBeaconsForConstraint:(id)arg1 error:(id)arg2 ;
-(void)locationManager:(id)arg0 didFailWithError:(id)arg1 ;
-(void)locationManager:(id)arg0 didFinishDeferredUpdatesWithError:(id)arg1 ;
-(void)locationManager:(id)arg0 didRangeBeacons:(id)arg1 inRegion:(id)arg2 ;
-(void)locationManager:(id)arg0 didRangeBeacons:(id)arg1 satisfyingConstraint:(id)arg2 ;
-(void)locationManager:(id)arg0 didStartMonitoringForRegion:(id)arg1 ;
-(void)locationManager:(id)arg0 didUpdateHeading:(id)arg1 ;
-(void)locationManager:(id)arg0 didUpdateLocations:(id)arg1 ;
-(void)locationManager:(id)arg0 didUpdateToLocation:(id)arg1 fromLocation:(id)arg2 ;
-(void)locationManager:(id)arg0 didVisit:(id)arg1 ;
-(void)locationManager:(id)arg0 monitoringDidFailForRegion:(id)arg1 withError:(id)arg2 ;
-(void)locationManager:(id)arg0 rangingBeaconsDidFailForRegion:(id)arg1 withError:(id)arg2 ;
-(void)locationManagerDidChangeAuthorization:(id)arg0 ;
-(void)locationManagerDidPauseLocationUpdates:(id)arg0 ;
-(void)locationManagerDidResumeLocationUpdates:(id)arg0 ;
@end

