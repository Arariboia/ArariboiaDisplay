QT       += core gui
QT += serialbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bms_can_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    motor_can_manager.cpp

HEADERS += \
    bms_can_manager.h \
    can_manager.h \
    mainwindow.h \
    mavlink/arariboat/arariboat.h \
    mavlink/arariboat/mavlink.h \
    mavlink/arariboat/mavlink_msg_all_info.h \
    mavlink/arariboat/mavlink_msg_bms.h \
    mavlink/arariboat/mavlink_msg_bms_status.h \
    mavlink/arariboat/mavlink_msg_debug.h \
    mavlink/arariboat/mavlink_msg_ezkontrol_mcu_meter_data_i.h \
    mavlink/arariboat/mavlink_msg_ezkontrol_mcu_meter_data_ii.h \
    mavlink/arariboat/mavlink_msg_gps.h \
    mavlink/arariboat/mavlink_msg_gps_info.h \
    mavlink/arariboat/mavlink_msg_heartbeat.h \
    mavlink/arariboat/mavlink_msg_instrumentation.h \
    mavlink/arariboat/mavlink_msg_mppt.h \
    mavlink/arariboat/mavlink_msg_mppt_state.h \
    mavlink/arariboat/mavlink_msg_named_value_float.h \
    mavlink/arariboat/mavlink_msg_named_value_int.h \
    mavlink/arariboat/mavlink_msg_param_request_read.h \
    mavlink/arariboat/mavlink_msg_param_set.h \
    mavlink/arariboat/mavlink_msg_param_value.h \
    mavlink/arariboat/mavlink_msg_pumps.h \
    mavlink/arariboat/mavlink_msg_radio_status.h \
    mavlink/arariboat/mavlink_msg_rpm_info.h \
    mavlink/arariboat/mavlink_msg_statustext.h \
    mavlink/arariboat/mavlink_msg_temperatures.h \
    mavlink/arariboat/testsuite.h \
    mavlink/arariboat/version.h \
    mavlink/checksum.h \
    mavlink/mavlink_conversions.h \
    mavlink/mavlink_helpers.h \
    mavlink/mavlink_types.h \
    mavlink/protocol.h \
    motor_can_manager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES += \
    mavlink/arariboat.xml \
    mavlink/arariboat.xml:Zone.Identifier
