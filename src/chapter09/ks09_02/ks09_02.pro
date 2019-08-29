include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt

QT			+= widgets

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter09/ks09_02

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/

#FORMS 		+= dialog.ui
				
HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks09_02.pro \
				textedit.h
				   
	
SOURCES    +=  main.cpp \
				textedit.cpp
				
#RESOURCES	+= ks09_02.qrc
				
OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {		
		LIBS += -lbasedll_d
		TARGET = ks09_02_d
	}
	CONFIG(release, debug|release) {			   
		LIBS += -lbasedll
		TARGET	= ks09_02
	}
} else {
	debug {		
		LIBS += -lbasedll_d
		TARGET	= ks09_02_d
	}
	release {
		LIBS += -lbasedll
		TARGET 	= ks09_02
	}
}