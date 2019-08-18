
TEMPLATE	= app
LANGUAGE	= C++

#CONFIG		+= console

QT			+= widgets

TARGET     	= ks02_03
OBJECTS_DIR = $$(TRAINDEVHOME)/obj/chapter02/ks02_03

DESTDIR     = $$(TRAINDEVHOME)/bin


MOC_DIR		= $$(OBJECTS_DIR)/moc
UI_DIR		= $$(OBJECTS_DIR)/ui

RC_ICONS        = images/my.ico
FORMS		+= dialogbase.ui

RESOURCES 	+= ks02_03.qrc

HEADERS		+= ks02_03.pro \
				dialog.h
	
	
SOURCES    +=  main.cpp \
				dialog.cpp
