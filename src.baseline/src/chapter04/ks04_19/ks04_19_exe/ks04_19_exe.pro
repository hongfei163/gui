﻿include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++



TEMPDIR		= $$TRAIN_OBJ_PATH/chapter04/ks04_19/exe

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/ks04_19

HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks04_19_exe.pro 			   
	
SOURCES    +=  main.cpp

OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {
		LIBS	+= -lks04_19_dll_d	\
				   -lks04_19_config_dll_d
				   
		TARGET = ks04_19_exe_d
	}
	CONFIG(release, debug|release) {
		LIBS	+= -lks04_19_dll	\
				   -lks04_19_config_dll				   
				   
		TARGET	= ks04_19_exe
	}
} else {
	debug {
		LIBS	+= -lks04_19_dll_d	\
				   -lks04_19_config_dll_d
		
		TARGET	= ks04_19_exe_d
	}
	release {
		LIBS	+= -lks04_19_dll	\
				   -lks04_19_config_dll				   
		
		TARGET 	= ks04_19_exe
	}
}