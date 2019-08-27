﻿include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++



TEMPDIR		= $$TRAIN_OBJ_PATH/chapter04/ks04_01/exe

DESTDIR     = $$TRAIN_BIN_PATH

#INCLUDEPATH += $$TRAIN_INCLUDE_PATH

HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks04_01_exe.pro 			   
	
SOURCES    +=  main.cpp

OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {
		LIBS	+= -lks04_01_dll_d			
				   
		TARGET = ks04_01_exe_d
	}
	CONFIG(release, debug|release) {
		LIBS	+= -lks04_01_dll				   
				   
		TARGET	= ks04_01_exe
	}
} else {
	debug {
		LIBS	+= -lks04_01_dll_d
		
		TARGET	= ks04_01_exe_d
	}
	release {
		LIBS	+= -lks04_01_dll
		
		TARGET 	= ks04_01_exe
	}
}