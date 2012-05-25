TEMPLATE = app
TARGET = pure
QT += core \
    gui
HEADERS += recorderwidget.h \
    imagelabel.h \
    meanplot.h \
    fftwidget.h \
    signalprocessor.h \
    tracker.h \
    imageprocessor.h \
    grabber.h \
    pure.h
SOURCES += recorderwidget.cpp \
    imagelabel.cpp \
    meanplot.cpp \
    fftwidget.cpp \
    signalprocessor.cpp \
    tracker.cpp \
    imageprocessor.cpp \
    grabber.cpp \
    main.cpp \
    pure.cpp
FORMS += recorderwidget.ui \
    pure.ui
RESOURCES += 
LIBS += /usr/lib/libopencv_core.so \
    /usr/lib/libopencv_highgui.so \
    /usr/lib/libqwt.so \
    /usr/lib/libopencv_objdetect.so \
    /usr/lib/libfftw3f.so \
    /usr/lib/libfftw3.so \
    /usr/lib/libopencv_imgproc.so.2.4
