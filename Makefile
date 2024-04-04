LIBRARY_NAME = libDCWeather

$(LIBRARY_NAME)_FILES = $(wildcard *.m)
$(LIBRARY_NAME)_CFLAGS = -fobjc-arc -I$(THEOS_PROJECT_DIR)/headers
$(LIBRARY_NAME)_FRAMEWORKS = UIKit CoreLocation
$(LIBRARY_NAME)_PRIVATE_FRAMEWORKS = Weather SpringBoard
$(LIBRARY_NAME)_INSTALL_PATH = /usr/lib

ifeq ($(SIM_BUILD), 1)
	SIM_BUILD = 1
	TARGET := simulator:clang::15.0
	ARCHS = arm64
else
	SIM_BUILD = 0
	TARGET := iphone:clang:latest:15.0
	INSTALL_TARGET_PROCESSES = SpringBoard
	SDK_PATH = $(THEOS)/sdks/iPhoneOS16.5.sdk/
	SYSROOT = $(SDK_PATH)

	ifeq ($(ROOTLESS), 1)
		THEOS_PACKAGE_SCHEME = rootless
	endif
endif

export SIM_BUILD
export DEBUG
export FINALPACKAGE
export ROOTLESS

include $(THEOS)/makefiles/common.mk

##################################
##########     NOTE     ##########
################################## \
If the current build is a production build, the LDCW_DEBUG variable will be ignored and just overwritten.\
This way production builds won't get built with debug output enabled by accident. \
If the current build is not a production build, the LDCW_DEBUG variable will be passed to the compiler.
ifeq ($(FINALPACKAGE), 1)
	$(LIBRARY_NAME)_CFLAGS += -DLDCW_DEBUG=0
else
	$(LIBRARY_NAME)_CFLAGS += -DLDCW_DEBUG="$(DEBUG)"
endif

ifeq ($(DEBUG), 1) 
	ifeq ($(FINALPACKAGE), 0)
		$(LIBRARY_NAME)_CFLAGS += -Wno-unused-variable -Wno-unused-function -ferror-limit=0
	endif
endif

include $(THEOS_MAKE_PATH)/library.mk
