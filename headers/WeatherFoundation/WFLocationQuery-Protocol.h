// Headers generated with ktool v1.4.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 16.0.0 | SDK: 16.0.0



@protocol WFLocationQuery

@property (readonly) WFResponse *response;
@property (retain) WFTaskIdentifier *identifier;

-(WFTaskIdentifier *)identifier;
-(id)response;
-(void)setIdentifier:(WFTaskIdentifier *)arg0 ;
-(void)start;

@end

