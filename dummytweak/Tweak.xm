#import <sys/types.h>
#import <os/log.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#include <unistd.h>

#import "libDCWeather.h"
#import "HBLog.h"

// Use for NSString literals or variables
#define ROOT_PATH_NS(path) ([[NSFileManager defaultManager] fileExistsAtPath:path] ? path : [@"/var/jb" stringByAppendingPathComponent:path])

// Use for C string literals
#define ROOT_PATH_C(cPath) (access(cPath, F_OK) == 0) ? cPath : "/var/jb" cPath

// Use for C string variables
// The string returned by this will get freed when your function exits
// If you want to keep it, use strdup
#define ROOT_PATH_C_VAR(cPath) (ROOT_PATH_NS([NSString stringWithUTF8String:cPath]).fileSystemRepresentation)

#define debug_log(...) ({\
	if (DCDT_DEBUG) {\
		char* str; \
		asprintf(&str, __VA_ARGS__); \
		os_log(OS_LOG_DEFAULT, "[DCDT_DEBUG] %s", str); \
	}\
})


@interface FBSystemService : NSObject
+ (id)sharedInstance;
- (void)exitAndRelaunch:(BOOL)arg1;
@end

// Global variables
BOOL enabled = TRUE;

@interface DCDTHelper : NSObject
- (id)DCDTReadPreferenceValue:(NSString *)key;
- (id)DCDTReadPreferenceValue:(NSString *)key fallbackValue:(id)value;
- (id)DCDTReadArrayPreferenceValue:(NSString *)key;
- (id)DCDTReadDatePreferenceValue:(NSString *)key;
- (BOOL)DCDTReadBooleanPreferenceValue:(NSString *)key fallbackValue:(id)value;
- (id)DCDTReadColorPreferenceValue:(NSString *)key fallbackValue:(id)value;
- (id)DCDTReadStringPreferenceValue:(NSString *)key fallbackValue:(id)value;
- (void)DCDTWritePreferenceValue:(id)object forKey:(NSString *)key;
- (void)DCDTRemovePreferenceValue:(NSString *)key;
- (void)DCDTRemovePreferenceDomain;
- (BOOL)DCDTDoesPreferenceDomainExist; // Don't believe is working
- (BOOL)DCDTDoesPreferenceValueExist:(NSString *)key;
@end

DCDTHelper *helper;

@implementation DCDTHelper
- (id)DCDTReadPreferenceValue:(NSString *)key {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != nil) {
		return [prefsDict objectForKey:key];
	} else {
		return @"0";
	}
}

- (id)DCDTReadPreferenceValue:(NSString *)key fallbackValue:(id)value {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != nil) {
		return [prefsDict objectForKey:key];
	} else {
		return value;
	}
}

- (id)DCDTReadArrayPreferenceValue:(NSString *)key {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != NULL) {
		return [prefsDict objectForKey:key];
	} else {
		return [NSMutableArray array];
	}
}

- (id)DCDTReadDatePreferenceValue:(NSString *)key {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != NULL) {
		return [prefsDict objectForKey:key];
	} else {
		return [NSDate date];
	}
}

- (BOOL)DCDTReadBooleanPreferenceValue:(NSString *)key fallbackValue:(id)value {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != NULL) {
		return [[prefsDict objectForKey:key] boolValue];
	} else {
		return value;
	}
}

- (id)DCDTReadColorPreferenceValue:(NSString *)key fallbackValue:(id)value {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != NULL) {
		return [prefsDict objectForKey:key];
	} else {
		return value;
	}
}

- (id)DCDTReadStringPreferenceValue:(NSString *)key fallbackValue:(id)value {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != NULL) {
		return [prefsDict objectForKey:key];
	} else {
		return value;
	}
}

- (id)DCDTReadIntegerPreferenceValue:(NSString *)key fallbackValue:(id)value {
    NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];

	if ([prefsDict objectForKey:key] != NULL) {
		return [prefsDict objectForKey:key];
	} else {
		return value;
	}
}

- (void)DCDTWritePreferenceValue:(id)object forKey:(NSString *)key {
	NSMutableDictionary *prefsDict = [[[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"] mutableCopy];

	[prefsDict setObject:object forKey:key];

	[[NSUserDefaults standardUserDefaults] setPersistentDomain:prefsDict forName:@"com.dcproducts.dummytweakprefs"];
}

- (void)DCDTRemovePreferenceValue:(NSString *)key {
	NSMutableDictionary *prefsDict = [[[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"] mutableCopy];

	[prefsDict removeObjectForKey:key];

	[[NSUserDefaults standardUserDefaults] setPersistentDomain:prefsDict forName:@"com.dcproducts.dummytweakprefs"];
}

- (void)DCDTRemovePreferenceDomain {
	[[NSUserDefaults standardUserDefaults] removePersistentDomainForName:@"com.dcproducts.dummytweakprefs"];
}

- (BOOL)DCDTDoesPreferenceDomainExist {
	NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];
	if (prefsDict) {
		return TRUE;
	} else {
		return FALSE;
	}
}

- (BOOL)DCDTDoesPreferenceValueExist:(NSString *)key {
	NSDictionary *prefsDict = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"];
	
	if ([prefsDict objectForKey:key] != NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}
@end

static void DCDTReloadPrefs() {
	debug_log("DCDTReloadPrefs called!");
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
		// Global toggle
		enabled = [helper DCDTReadBooleanPreferenceValue:@"isEnabled" fallbackValue:@YES];
		debug_log("enabled --> %i", enabled);

		if (DCDT_DEBUG) {
			debug_log("NSUserDefaults dump: %s", [[NSString stringWithFormat:@"%@", [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.dcproducts.dummytweakprefs"]] UTF8String]);
		}
	});
}

static void DCDTReset() {
	debug_log("DCDTReset called!");
	[helper DCDTWritePreferenceValue:@YES forKey:@"isEnabled"];
}

void DCDTPrefsCheck() {
	debug_log("DCDTPrefsCheck called!");

	if (![helper DCDTDoesPreferenceValueExist:@"isEnabled"]) {
		debug_log("isEnabled = NULL");
		[helper DCDTWritePreferenceValue:@YES forKey:@"isEnabled"];
	}
}

void DCDTRespring() {
	debug_log("DCDTRespring called!");
	[[%c(FBSystemService) sharedInstance] exitAndRelaunch:YES];
}

%ctor {
	helper = [[DCDTHelper alloc] init];

	CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, (CFNotificationCallback)DCDTRespring, CFSTR("com.dcproducts.dummytweak/Respring"), NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
	CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, (CFNotificationCallback)DCDTReloadPrefs, CFSTR("com.dcproducts.dummytweak/ReloadPrefs"), NULL, CFNotificationSuspensionBehaviorCoalesce);
	CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, (CFNotificationCallback)DCDTReset, CFSTR("com.dcproducts.dummytweak/Reset"), NULL, CFNotificationSuspensionBehaviorDeliverImmediately);

	DCDTPrefsCheck();
	DCDTReloadPrefs();

    debug_log("DummyTweak loaded!");

    libDCWeather *weatherLib = [libDCWeather sharedInstance];

    //libDCWeather *weatherLib = [[libDCWeather alloc] init];
    NSLog(@"[DummyTweak] weatherLib: %@", weatherLib);
    //NSLog(@"[DummyTweak] temperatureString: %@", [weatherLib temperatureString]);
    debug_log("temperatureString: %s", [[weatherLib temperatureString] UTF8String]);
    //NSLog(@"[DummyTweak] conditionString: %@", [weatherLib conditionString]);
    debug_log("conditionString: %s", [[weatherLib conditionString] UTF8String]);
    [weatherLib conditionIncludesSevereWeather:YES];
    debug_log("conditionString: %s", [[weatherLib conditionString] UTF8String]);
    debug_log("cityString: %s", [[weatherLib cityString] UTF8String]);
}
