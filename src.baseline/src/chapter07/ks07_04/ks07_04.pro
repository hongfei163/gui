include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt

QT			+= widgets

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter05/ks07_04

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/ks07_04

#FORMS 		+= dialogbase.ui 

				
HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks07_04.pro \
				customwidget.h
				   
	
SOURCES    +=  main.cpp  \
			   customwidget.cpp
				
RESOURCES	+= ks07_04.qrc
				
OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {				   
		TARGET = ks07_04_d
	}
	CONFIG(release, debug|release) {			   
		TARGET	= ks07_04
	}
} else {
	debug {		
		TARGET	= ks07_04_d
	}
	release {
		TARGET 	= ks07_04
	}
}