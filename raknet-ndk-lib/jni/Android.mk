# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#



LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := RakNet
MY_PREFIX := $(LOCAL_PATH)/RakNetSources/
MY_SOURCES := $(wildcard $(MY_PREFIX)*.cpp)
LOCAL_SRC_FILES += $(MY_SOURCES:$(MY_PREFIX)%=RakNetSources/%)

LOCAL_SRC_FILES += RakNetJNIWrapper.cpp

LOCAL_CFLAGS := -D_RAKNET_SUPPORT_FileOperations=0
LOCAL_C_INCLUDES := $(LOCAL_PATH)/RakNetSources/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../GMRakNetInterface/


include $(BUILD_SHARED_LIBRARY)