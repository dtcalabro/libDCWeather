
# Notes

## Condition Codes

    0  - Tornado
    1  - Tropical Storm
    2  - Hurricane
    3  - Severe Thunderstorms
    4  - Thunderstorms
    5  - Mixed Rain and Snow
    6  - Mixed Rain and Sleet
    7  - Mixed Snow and Sleet
    8  - Freezing Drizzle
    9  - Drizzle
    10 - Freezing Rain
    11 - Showers
    12 - Rain
    13 - Snow Flurries
    14 - Light Snow Showers
    15 - Blowing Snow
    16 - Snow
    17 - Hail
    18 - Sleet
    19 - Dust
    20 - Foggy
    21 - Haze
    22 - Smokey
    23 - Breezy
    24 - Windy
    25 - Frigid
    26 - Cloudy
    27 - Mostly Cloudy (Night)
    28 - Mostly Cloudy
    29 - Partly Cloudy (Night)
    30 - Partly Cloudy
    31 - Clear (Night)
    32 - Sunny
    33 - Mostly Sunny (Night)
    34 - Mostly Sunny
    35 - Mixed Rain Fall
    36 - Hot
    37 - Isolated Thunderstorms
    38 - Scattered Thunderstorms
    39 - Scattered Showers
    40 - Heavy Rain
    41 - Scattered Snow Showers
    42 - Heavy Snow
    43 - Blizzard
    44 - Not Available
    45 - Scattered Showers
    46 - Scattered Snow Showers
    47 - Isolated Thundershowers

## Other Findings

- NSStringFromWeatherConditionCode actually works thru index 195, 0-47 are the actual conditions, 48-97 are the system image names for each condition, 98-147 are the system images names without fill for each condition, and I believe 148-195 are the NSImage names for each condition.