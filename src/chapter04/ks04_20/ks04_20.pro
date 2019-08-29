include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

#CONFIG		+= console
QT			+= xml


TEMPDIR		= $$TRAIN_OBJ_PATH/chapter04/ks04_20

DESTDIR     = $$TRAIN_BIN_PATH

HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks04_20.pro 			   
	
SOURCES    +=  main.cpp

OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {
		LIBS	+= -lbasedll_d		
	
		TARGET = ks04_20_d
	}
	CONFIG(release, debug|release) {
		LIBS	+= -lbasedll				   
				   
		TARGET	= ks04_20
	}
} else {
	debug {
		LIBS	+= -lbasedll_d	
	
		TARGET	= ks04_20_d
	}
	release {
		LIBS	+= -lbasedll
		
		TARGET 	= ks04_20
	}
}