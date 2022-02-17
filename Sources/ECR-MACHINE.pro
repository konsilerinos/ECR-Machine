QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DeveloperQW.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    DeveloperQW.h \
    MainWindow.h

FORMS += \
    DeveloperQW.ui \
    MainWindow.ui

RC_ICONS = Resources/Icon/Icon.ico

VERSION = 2.2.1.1
QMAKE_TARGET_COMPANY = DKonsilerinos cmp
QMAKE_TARGET_PRODUCT = Encryption Machine
QMAKE_TARGET_DESCRIPTION = ECR-MACHINE
QMAKE_TARGET_COPYRIGHT = Konsilerinos

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
