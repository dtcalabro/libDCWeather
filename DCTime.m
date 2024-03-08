// DCTime.m
#import "DCTime.h"

@implementation DCTime

- (instancetype)initWithSeconds:(double)seconds {
    self = [super init];
    if (self) {
        self.time = seconds;
    }
    return self;
}

- (instancetype)initWithMinutes:(double)minutes {
    self = [super init];
    if (self) {
        self.time = minutes * 60;
    }
    return self;
}

- (instancetype)initWithHours:(double)hours {
    self = [super init];
    if (self) {
        self.time = hours * 3600;
    }
    return self;
}

- (instancetype)initWithDays:(double)days {
    self = [super init];
    if (self) {
        self.time = days * 86400;
    }
    return self;
}

- (instancetype)initWithMonths:(double)months {
    self = [super init];
    if (self) {
        self.time = months * 2628000;
    }
    return self;
}

- (double)seconds {
    return self.time;
}

- (double)minutes {
    return self.time / 60;
}

- (double)hours {
    return self.time / 3600;
}

- (double)days {
    return self.time / 86400;
}

- (double)months {
    return self.time / 2628000;
}

@end