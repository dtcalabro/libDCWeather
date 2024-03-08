#!/usr/bin/env bash

set -e

./build.sh rootless final
cp -Rv "./.theos/obj/libDCWeather.dylib" "$THEOS/lib/iphone/rootless"

cp -v "./public-headers/libDCWeather.h" "$THEOS/include"

echo "Successfully installed libDCWeather"