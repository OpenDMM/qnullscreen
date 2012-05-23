TEMPLATE = lib
CONFIG += qt plugin

TARGET = $$qtLibraryTarget(qscreennull)
contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols

QMAKE_TARGET_COMPANY = Dream Multimedia GmbH
QMAKE_TARGET_PRODUCT = qnullscreen
QMAKE_TARGET_DESCRIPTION = Null Screen Driver Plug-in.
QMAKE_TARGET_COPYRIGHT = Copyright (C) 2012 Dream Multimedia GmbH

target.path = $$[QT_INSTALL_PLUGINS]/gfxdrivers
INSTALLS += target

SOURCES = qscreennull.cpp
