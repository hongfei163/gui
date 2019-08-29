include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt
QT			+= widgets xml

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter11/ks11_02

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/

TRANSLATIONS += $$TRAIN_SRC_PATH/translations/ks11_02.ts

#FORMS 		+= dialog.ui
				
HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks11_02.pro \
				graphview.h \
				mainwindow.h \
				rectitem.h \
				ellipseitem.h \
				itembase.h
				   
	
SOURCES    +=  main.cpp \
				graphview.cpp \
				mainwindow.cpp \
				rectitem.cpp \
				ellipseitem.cpp
				
RESOURCES	+= ks11_02.qrc
				
OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {		
		LIBS += -lbasedll_d
		TARGET = ks11_02_d
	}
	CONFIG(release, debug|release) {			   
		LIBS += -lbasedll
		TARGET	= ks11_02
	}
} else {
	debug {		
		LIBS += -lbasedll_d
		TARGET	= ks11_02_d
	}
	release {
		LIBS += -lbasedll
		TARGET 	= ks11_02
	}
}