####################################################################################################

TEMPLATE = app
TARGET = alpine-toolkit

####################################################################################################

CONFIG += c++14
CONFIG += debug console qml_debug
CONFIG += qtquickcompiler

QT += core network
QT += qml quick quickcontrols
QT += sensors
QT += positioning
QT += sql
QT += svg widgets gui # to support SVG
# QT += charts

INCLUDEPATH += src

HEADERS += \
  src/ephemeride/ephemeride.h \
  src/refuge/refuge.h \
  src/satellite_model/satellite_model.h \
  src/sensors/qml_barimeter_altimeter_sensor.h \
  src/sensors/qmlsensor.h \
  src/sensors/qmlsensorrange.h \
  src/international_morse_code_engine/international_morse_code_engine.h \
  src/international_morse_code_engine/international_morse_code_engine_table.cpp \
  src/sql_model/SqlQueryModel.h

SOURCES += \
  src/ephemeride/ephemeride.cpp \
  src/main.cpp \
  src/refuge/refuge.cpp \
  src/satellite_model/satellite_model.cpp \
  src/sensors/qml_barimeter_altimeter_sensor.cpp \
  src/sensors/qmlsensor.cpp \
  src/sensors/qmlsensorrange.cpp \
  src/international_morse_code_engine/international_morse_code_engine.cpp \
  src/sql_model/SqlQueryModel.cpp

lupdate_only{
SOURCES += \
  pages/*.qml
}

# OTHER_FILES += \
#   pages/*.qml

RESOURCES += alpine-toolkit.qrc

TRANSLATIONS = translations/alpine-toolkit.fr_FR.ts
# \ alpine-toolkit-en.ts

####################################################################################################
#
# Android
#

android {
DEFINES += ANDROID

QT += androidextras

HEADERS += \
  src/android_activity/android_activity.h

SOURCES += \
  src/android_activity/android_activity.cpp

# OTHER_FILES += \
#   android/AndroidManifest.xml

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}

####################################################################################################
#
# End
#
####################################################################################################
