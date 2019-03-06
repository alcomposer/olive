#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T10:31:59
#
#-------------------------------------------------

QT       += core gui multimedia opengl svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

mac {
    TARGET = Olive
}
!mac {
    TARGET = olive-editor
}
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Tries to get the current Git short hash
system("which git") {
    GITPATH = $$PWD

    win32 {
        GITPATH = $$system(cygpath $$PWD)
    }

    GITHASHVAR = $$system(git --git-dir="$$GITPATH/.git" --work-tree="$$GITPATH" log -1 --format=%h)

    # Fallback for Ubuntu/Launchpad (extracts Git hash from debian/changelog rather than Git repo)
    # (see https://answers.launchpad.net/launchpad/+question/678556)
    isEmpty(GITHASHVAR) {
        GITHASHVAR = $$system(sh $$PWD/debian/gitfromlog.sh $$PWD/debian/changelog)
    }

    DEFINES += GITHASH=\\"\"$$GITHASHVAR\\"\"
}

CONFIG += c++11

CONFIG(debug, debug|release) {
    CONFIG += console
}

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    panels/project.cpp \
    panels/effectcontrols.cpp \
    panels/viewer.cpp \
    panels/timeline.cpp \
    ui/sourcetable.cpp \
    dialogs/aboutdialog.cpp \
    ui/timelinewidget.cpp \
    project/media.cpp \
    project/footage.cpp \
    project/sequence.cpp \
    project/clip.cpp \
    io/config.cpp \
    dialogs/newsequencedialog.cpp \
    ui/viewerwidget.cpp \
    ui/viewercontainer.cpp \
    dialogs/exportdialog.cpp \
    ui/collapsiblewidget.cpp \
    panels/panels.cpp \
    io/exportthread.cpp \
    ui/timelineheader.cpp \
    io/previewgenerator.cpp \
    ui/labelslider.cpp \
    dialogs/preferencesdialog.cpp \
    ui/audiomonitor.cpp \
    project/undo.cpp \
    ui/scrollarea.cpp \
    ui/comboboxex.cpp \
    ui/colorbutton.cpp \
    dialogs/replaceclipmediadialog.cpp \
    ui/fontcombobox.cpp \
    ui/checkboxex.cpp \
    ui/keyframeview.cpp \
    ui/texteditex.cpp \
    dialogs/demonotice.cpp \
    project/marker.cpp \
    dialogs/speeddialog.cpp \
    dialogs/mediapropertiesdialog.cpp \
    project/projectmodel.cpp \
    io/loadthread.cpp \
    dialogs/loaddialog.cpp \
    debug.cpp \
    io/path.cpp \
    effects/internal/linearfadetransition.cpp \
    effects/internal/transformeffect.cpp \
    effects/internal/solideffect.cpp \
    effects/internal/texteffect.cpp \
    effects/internal/timecodeeffect.cpp \
    effects/internal/audionoiseeffect.cpp \
    effects/internal/paneffect.cpp \
    effects/internal/toneeffect.cpp \
    effects/internal/volumeeffect.cpp \
    effects/internal/crossdissolvetransition.cpp \
    effects/internal/shakeeffect.cpp \
    effects/internal/exponentialfadetransition.cpp \
    effects/internal/logarithmicfadetransition.cpp \
    effects/internal/cornerpineffect.cpp \
    io/math.cpp \
    io/qpainterwrapper.cpp \
    project/effect.cpp \
    project/transition.cpp \
    project/effectrow.cpp \
    project/effectfield.cpp \
    effects/internal/cubetransition.cpp \
    project/effectgizmo.cpp \
    io/clipboard.cpp \
    ui/resizablescrollbar.cpp \
    ui/sourceiconview.cpp \
    project/sourcescommon.cpp \
    ui/keyframenavigator.cpp \
    panels/grapheditor.cpp \
    ui/graphview.cpp \
    ui/keyframedrawing.cpp \
    ui/clickablelabel.cpp \
    project/keyframe.cpp \
    ui/rectangleselect.cpp \
    dialogs/actionsearch.cpp \
    ui/embeddedfilechooser.cpp \
    effects/internal/fillleftrighteffect.cpp \
    effects/internal/voideffect.cpp \
    dialogs/texteditdialog.cpp \
    dialogs/debugdialog.cpp \
    ui/viewerwindow.cpp \
    project/projectfilter.cpp \
    effects/internal/frei0reffect.cpp \
    project/effectloaders.cpp \
    io/crossplatformlib.cpp \
    effects/internal/vsthost.cpp \
    ui/flowlayout.cpp \
    dialogs/proxydialog.cpp \
    io/proxygenerator.cpp \
    dialogs/advancedvideodialog.cpp \
    ui/cursors.cpp \
    ui/menuhelper.cpp \
    oliveglobal.cpp \
    ui/focusfilter.cpp \
    project/comboaction.cpp \
    ui/mediaiconservice.cpp \
    ui/panel.cpp \
    effects/internal/dropshadoweffect.cpp \
    rendering/renderfunctions.cpp \
    rendering/renderthread.cpp \
    rendering/cacher.cpp \
    rendering/clipqueue.cpp \
    rendering/audio.cpp \
    dialogs/clippropertiesdialog.cpp \
    rendering/framebufferobject.cpp \
    ui/trackcontrols.cpp \
    ui/trackcontrolswidget.cpp \
    ui/trackcontrolsbox.cpp

HEADERS += \
        mainwindow.h \
    panels/project.h \
    panels/effectcontrols.h \
    panels/viewer.h \
    panels/timeline.h \
    ui/sourcetable.h \
    dialogs/aboutdialog.h \
    ui/timelinewidget.h \
    project/media.h \
    project/footage.h \
    project/sequence.h \
    project/clip.h \
    io/config.h \
    dialogs/newsequencedialog.h \
    ui/viewerwidget.h \
    ui/viewercontainer.h \
    dialogs/exportdialog.h \
    ui/collapsiblewidget.h \
    panels/panels.h \
    io/exportthread.h \
    ui/timelinetools.h \
    ui/timelineheader.h \
    io/previewgenerator.h \
    ui/labelslider.h \
    dialogs/preferencesdialog.h \
    ui/audiomonitor.h \
    project/undo.h \
    ui/scrollarea.h \
    ui/comboboxex.h \
    ui/colorbutton.h \
    dialogs/replaceclipmediadialog.h \
    ui/fontcombobox.h \
    ui/checkboxex.h \
    ui/keyframeview.h \
    ui/texteditex.h \
    dialogs/demonotice.h \
    project/marker.h \
    project/selection.h \
    dialogs/speeddialog.h \
    dialogs/mediapropertiesdialog.h \
    project/projectmodel.h \
    io/loadthread.h \
    dialogs/loaddialog.h \
    debug.h \
    io/path.h \
    effects/internal/transformeffect.h \
    effects/internal/solideffect.h \
    effects/internal/texteffect.h \
    effects/internal/timecodeeffect.h \
    effects/internal/audionoiseeffect.h \
    effects/internal/paneffect.h \
    effects/internal/toneeffect.h \
    effects/internal/volumeeffect.h \
    effects/internal/shakeeffect.h \
    effects/internal/linearfadetransition.h \
    effects/internal/crossdissolvetransition.h \
    effects/internal/exponentialfadetransition.h \
    effects/internal/logarithmicfadetransition.h \
    effects/internal/cornerpineffect.h \
    io/math.h \
    io/qpainterwrapper.h \
    project/effect.h \
    project/transition.h \
    project/effectrow.h \
    project/effectfield.h \
    effects/internal/cubetransition.h \
    project/effectgizmo.h \
    io/clipboard.h \
    ui/resizablescrollbar.h \
    ui/sourceiconview.h \
    project/sourcescommon.h \
    ui/keyframenavigator.h \
    panels/grapheditor.h \
    ui/graphview.h \
    ui/keyframedrawing.h \
    ui/clickablelabel.h \
    project/keyframe.h \
    ui/rectangleselect.h \
    dialogs/actionsearch.h \
    ui/embeddedfilechooser.h \
    effects/internal/fillleftrighteffect.h \
    effects/internal/voideffect.h \
    dialogs/texteditdialog.h \
    dialogs/debugdialog.h \
    ui/viewerwindow.h \
    project/projectfilter.h \
    effects/internal/frei0reffect.h \
    project/effectloaders.h \
    io/crossplatformlib.h \
    effects/internal/vsthost.h \
    ui/flowlayout.h \
    dialogs/proxydialog.h \
    io/proxygenerator.h \
    dialogs/advancedvideodialog.h \
    ui/cursors.h \
    ui/menuhelper.h \
    oliveglobal.h \
    project/projectelements.h \
    ui/focusfilter.h \
    project/comboaction.h \
    ui/mediaiconservice.h \
    ui/panel.h \
    effects/internal/dropshadoweffect.h \
    rendering/renderfunctions.h \
    rendering/renderthread.h \
    rendering/clipqueue.h \
    rendering/cacher.h \
    rendering/audio.h \
    dialogs/clippropertiesdialog.h \
    rendering/framebufferobject.h \
    ui/trackcontrols.h \
    ui/trackcontrolswidget.h \
    ui/trackcontrolsbox.h

FORMS +=

TRANSLATIONS += \
    ts/olive_de.ts \
    ts/olive_es.ts \
    ts/olive_fr.ts \
    ts/olive_it.ts \
    ts/olive_cs.ts \
    ts/olive_ar.ts \
    ts/olive_ru.ts \
    ts/olive_bs.ts \
    ts/olive_sr.ts

win32 {
    RC_FILE = packaging/windows/resources.rc
    LIBS += -lavutil -lavformat -lavcodec -lavfilter -lswscale -lswresample -lopengl32 -luser32
    contains(DEFINES, OLIVE_OCIO) {
        LIBS += -lOpenColorIO
    }
}

mac {
    LIBS += -L/usr/local/lib -lavutil -lavformat -lavcodec -lavfilter -lswscale -lswresample -framework CoreFoundation
    ICON = packaging/macos/olive.icns
    INCLUDEPATH = /usr/local/include
}

unix:!mac {
    CONFIG += link_pkgconfig
    PKGCONFIG += libavutil libavformat libavcodec libavfilter libswscale libswresample
}
unix:!mac:!haiku {
    LIBS += -ldl
}

RESOURCES += \
    icons/icons.qrc \
    effects/internal/internalshaders.qrc \
    cursors/cursors.qrc

unix:!mac:isEmpty(PREFIX) {
    PREFIX = /usr/local
}

unix:!mac:target.path = $$PREFIX/bin

effects.files = $$PWD/effects/*.frag $$PWD/effects/*.xml $$PWD/effects/*.vert
unix:!mac:effects.path = $$PREFIX/share/olive-editor/effects

translations.files = $$PWD/ts/*.qm
unix:!mac:translations.path = $$PREFIX/share/olive-editor/ts

unix:!mac {
    metainfo.files = $$PWD/packaging/linux/org.olivevideoeditor.Olive.appdata.xml
    metainfo.path = $$PREFIX/share/metainfo
    desktop.files = $$PWD/packaging/linux/org.olivevideoeditor.Olive.desktop
    desktop.path = $$PREFIX/share/applications
    mime.files = $$PWD/packaging/linux/org.olivevideoeditor.Olive.xml
    mime.path = $$PREFIX/share/mime/packages
    icon16.files = $$PWD/packaging/linux/icons/16x16/org.olivevideoeditor.Olive.png
    icon16.path = $$PREFIX/share/icons/hicolor/16x16/apps
    icon32.files = $$PWD/packaging/linux/icons/32x32/org.olivevideoeditor.Olive.png
    icon32.path = $$PREFIX/share/icons/hicolor/32x32/apps
    icon48.files = $$PWD/packaging/linux/icons/48x48/org.olivevideoeditor.Olive.png
    icon48.path = $$PREFIX/share/icons/hicolor/48x48/apps
    icon64.files = $$PWD/packaging/linux/icons/64x64/org.olivevideoeditor.Olive.png
    icon64.path = $$PREFIX/share/icons/hicolor/64x64/apps
    icon128.files = $$PWD/packaging/linux/icons/128x128/org.olivevideoeditor.Olive.png
    icon128.path = $$PREFIX/share/icons/hicolor/128x128/apps
    icon256.files = $$PWD/packaging/linux/icons/256x256/org.olivevideoeditor.Olive.png
    icon256.path = $$PREFIX/share/icons/hicolor/256x256/apps
    icon512.files = $$PWD/packaging/linux/icons/512x512/org.olivevideoeditor.Olive.png
    icon512.path = $$PREFIX/share/icons/hicolor/512x512/apps
    INSTALLS += target effects translations metainfo desktop mime icon16 icon32 icon48 icon64 icon128 icon256 icon512
}
