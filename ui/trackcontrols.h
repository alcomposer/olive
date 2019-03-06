#ifndef TRACKCONTROLS_H
#define TRACKCONTROLS_H

#include "project/sequence.h"
#include "project/clip.h"
#include "project/footage.h"
#include "project/media.h"
#include "project/undo.h"
#include "timelinetools.h"
#include "trackcontrolswidget.h"


#include <QVBoxLayout>
#include <QObject>
#include <QWidget>
#include <QSplitter>

class Timeline;

class TrackControls : public QWidget
{
    Q_OBJECT
public:
    TrackControls(QWidget* parent = nullptr);
    void update();
private:
    void paintEvent(QPaintEvent*);
    QVBoxLayout* track_controls_layout;
    TrackControlsWidget* video_track_controls;
    QSplitter* splitter_;
    TrackControlsWidget* audio_track_controls;
};

#endif // TRACKCONTROLS_H
