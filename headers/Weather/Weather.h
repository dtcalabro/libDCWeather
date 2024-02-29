

#include "WATodayModel.h"
#include "WATodayAutoupdatingLocationModel.h"
#include "WAAQIScaleView.h"
#include "WAAQIGradient.h"
#include "WeatherWindSpeedFormatter.h"
#include "WeatherCloudMigrator.h"
#include "WeatherView.h"
#include "WeatherUserDefaults.h"
#include "WeatherPrecipitationFormatter.h"
#include "WATodayHourlyForecastView.h"
#include "WALockscreenWidgetViewController.h"
#include "WeatherImageLoader.h"
#include "WeatherLocationManager.h"
#include "WATodayHeaderView.h"
#include "WATodayPadViewStyle.h"
#include "ProgressController.h"
#include "WAAQICategory.h"
#include "WeatherAQIAttribution.h"
#include "City.h"
#include "WeatherCloudPersistence.h"
#include "WAGreetingView.h"
#include "WAAQIGradientStop.h"
#include "WAAQIView.h"
#include "WACurrentForecast.h"
#include "WeatherInMemoryDefaults.h"
#include "WeatherCloudPreferences.h"
#include "WAForecastOperation.h"
#include "CityPersistenceConversions.h"
#include "WeatherInternalPreferences.h"
#include "WeatherVisibilityFormatter.h"
#include "TWCCityUpdater.h"
#include "WASevereWeatherStringBuilder.h"
#include "WeatherPreferences.h"
#include "WAWeatherPlatterViewController.h"
#include "WAGradientProvider.h"
#include "WAForecastModel.h"
#include "WALegibilityLabel.h"
#include "WeatherOpenURLHelper.h"
#include "WAAQIViewStyler.h"
#include "WAForecastModelController.h"
#include "WAAQIAttributionStringBuilder.h"
#include "WAHourlyForecast.h"
#include "WAHourlyForecastParser.h"
#include "WAProviderAttributionManager.h"
#include "WATodayPadView.h"
#include "WADayForecast.h"
#include "WeatherDeviceLookup.h"
#include "TWCLocationUpdater.h"
#include "WeatherPressureFormatter.h"
#include "WAAQIScale.h"
#include "NSObject-Protocol.h"
#include "CLLocationManagerDelegate-Protocol.h"
#include "SynchronizedDefaultsDelegate-Protocol.h"
#include "CityUpdateObserver-Protocol.h"
#include "WeatherPreferencesPersistence-Protocol.h"
#include "WATodayModelObserver-Protocol.h"
#include "NSCopying-Protocol.h"
#include "WeatherApplicationProgressDelegate-Protocol.h"
#include "WAIdentifiable-Protocol.h"
#include "WeatherCloudPersistenceDelegate-Protocol.h"
#include "WFTemperatureUnitObserver-Protocol.h"
#include "NSURLConnectionDelegate-Protocol.h"
