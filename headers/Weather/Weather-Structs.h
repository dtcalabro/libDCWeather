/*
typedef struct CGPoint {
    CGFloat x;
    CGFloat y;
} CGPoint;

typedef struct CGSize {
    CGFloat width;
    CGFloat height;
} CGSize;

typedef struct CGRect {
    CGPoint origin;
    CGSize size;
} CGRect;
*/
/*
typedef struct _NSZone {
}; // Error Processing Struct Fields
*/
/*
typedef struct ct_green_tea_logger_s {
};// Error Processing Struct Fields
*/
/*
typedef struct _NSRange {
    NSUInteger location;
    NSUInteger length;
} _NSRange;
*/
/*
typedef struct __GSEvent {
}; // Error Processing Struct Fields
*/

typedef struct huh {
    BOOL hasOverrideClient;
    BOOL hasOverrideHost;
    BOOL hasInputAssistantItem;
    BOOL suppressSoftwareKeyboard;
    BOOL conformsToUIKeyInputIsSet;
    BOOL conformsToUIKeyInput;
} huh;

/*
typedef struct CGVector {
    CGFloat field0;
    CGFloat field1;
} CGVector;
*/
/*
typedef struct UIEdgeInsets {
    CGFloat top;
    CGFloat left;
    CGFloat bottom;
    CGFloat right;
} UIEdgeInsets;
*/
/*
typedef struct NSDirectionalEdgeInsets {
    CGFloat top;
    CGFloat leading;
    CGFloat bottom;
    CGFloat trailing;
} NSDirectionalEdgeInsets;
*/
/*
typedef struct CGAffineTransform {
    CGFloat field0;
    CGFloat field1;
    CGFloat field2;
    CGFloat field3;
    CGFloat field4;
    CGFloat field5;
} CGAffineTransform;
*/
/*
typedef struct CGContext {
}; // Error Processing Struct Fields
*/
/*
typedef struct CATransform3D {
    CGFloat field0;
    CGFloat field1;
    CGFloat field2;
    CGFloat field3;
    CGFloat field4;
    CGFloat field5;
    CGFloat field6;
    CGFloat field7;
    CGFloat field8;
    CGFloat field9;
    CGFloat field10;
    CGFloat field11;
    CGFloat field12;
    CGFloat field13;
    CGFloat field14;
    CGFloat field15;
} CATransform3D;
*/

typedef struct _UITraitCollectionTraitChanges {
    BOOL field0;
    BOOL field1;
    BOOL field2;
    BOOL field3;
    BOOL field4;
    BOOL field5;
    BOOL field6;
    BOOL field7;
    BOOL field8;
    BOOL field9;
} _UITraitCollectionTraitChanges;

typedef struct _UITraitCollectionChangeDescription {
    id field0;
    id field1;
    BOOL field2;
    _UITraitCollectionTraitChanges field3;
} _UITraitCollectionChangeDescription;

/*
typedef struct CGColor {
}; // Error Processing Struct Fields
*/
/*
typedef struct CGImage {
}; // Error Processing Struct Fields
*/

typedef struct UIRectCornerRadii {
    CGFloat field0;
    CGFloat field1;
    CGFloat field2;
    CGFloat field3;
} UIRectCornerRadii;

/*
typedef struct CAFrameRateRange {
    float field0;
    float field1;
    float field2;
} CAFrameRateRange;
*/

typedef CGFloat CLLocationDegrees;

typedef struct CLLocationCoordinate2D {
    CLLocationDegrees latitude;
    CLLocationDegrees longitude;
} CLLocationCoordinate2D;

/*
typedef struct _opaque_pthread_mutex_t {
    NSInteger __sig;
    char __opaque;
} _opaque_pthread_mutex_t;
*/
/*
typedef struct _opaque_pthread_cond_t {
    NSInteger __sig;
    char __opaque;
} _opaque_pthread_cond_t;
*/

typedef struct os_unfair_lock_s {
    unsigned int _os_unfair_lock_opaque;
} os_unfair_lock_s;

/*
typedef struct __CFString {
}; // Error Processing Struct Fields
*/
/*
typedef struct __CFURL {
}; // Error Processing Struct Fields
*/

typedef struct ct_green_tea_logger_s* ct_green_tea_logger_sRef;

typedef struct {
	float field1;
	float field2;
	float field3;
	float field4;
} SCD_Struct_WA7;

typedef struct {
	SCD_Struct_WA7 field1;
	SCD_Struct_WA7 field2;
	SCD_Struct_WA7 field3;
} SCD_Struct_WA8;