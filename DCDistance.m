// DCDistance.m
#import "DCDistance.h"

@implementation DCDistance

- (instancetype)initWithMeters:(double)distance {
    self = [super init];
    if (self) {
        self.distance = distance;
    }
    return self;
}

- (instancetype)initWithKilometers:(double)distance {
    self = [super init];
    if (self) {
        self.distance = distance * 1000;
    }
    return self;
}

- (instancetype)initWithFeet:(double)distance {
    self = [super init];
    if (self) {
        self.distance = distance * 0.3048;
    }
    return self;
}

- (instancetype)initWithYards:(double)distance {
    self = [super init];
    if (self) {
        self.distance = distance * 0.9144;
    }
    return self;
}

- (instancetype)initWithMiles:(double)distance {
    self = [super init];
    if (self) {
        self.distance = distance * 1609.34;
    }
    return self;
}

+ (double)meters:(double)distance {
    return distance;
}

+ (double)kilometers:(double)distance {
    return distance * 1000;
}

+ (double)feet:(double)distance {
    return distance * 0.3048;
}

+ (double)yards:(double)distance {
    return distance * 0.9144;
}

+ (double)miles:(double)distance {
    return distance * 1609.34;
}

- (double)meters {
    return self.distance;
}

- (double)kilometers {
    return self.distance / 1000;
}

- (double)feet {
    return self.distance / 0.3048;
}

- (double)yards {
    return self.distance / 0.9144;
}

- (double)miles {
    return self.distance / 1609.34;
}

@end