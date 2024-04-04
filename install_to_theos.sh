#!/usr/bin/env bash

set -e

./build.sh rootless final
cp -Rv "./.theos/obj/libDCWeather.dylib" "$THEOS/lib/iphone/rootless"

./build.sh final
cp -Rv "./.theos/obj/libDCWeather.dylib" "$THEOS/lib/iphone"

cp -v "./public-headers/libDCWeather.h" "$THEOS/include"

echo "Successfully installed libDCWeather"