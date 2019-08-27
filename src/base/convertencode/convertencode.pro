﻿include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt

QT		+= widgets

TEMPDIR		= $$TRAIN_OBJ_PATH/base/convertencode

DESTDIR         = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/base

HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
                    convertencode.pro  \
                    fileencodetype.h
	
SOURCES    +=  main.cpp

OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
        CONFIG(debug, debug|release) {
                LIBS += -lbasedll_d

		TARGET = convertencode_d
	}
	CONFIG(release, debug|release) {			   
                LIBS += -lbasedll

		TARGET	= convertencode
	}
} else {
	debug {		
                LIBS += -lbasedll_d

                TARGET	= convertencode_d
	}
	release {
                LIBS += -lbasedll

		TARGET 	= convertencode
	}
}
