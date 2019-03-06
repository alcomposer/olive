#ifndef TRACKCONTROLSWIDGET_H
#define TRACKCONTROLSWIDGET_H

#include "project/sequence.h"
#include "project/clip.h"
#include "project/footage.h"
#include "project/media.h"
#include "project/undo.h"
#include "timelinetools.h"
#include "ui/trackcontrolsbox.h"


#include <QObject>
#include <QWidget>
#include <QVector>
#include <QVBoxLayout>

class Timeline;

class TrackControlsWidget : public QWidget
{
    Q_OBJECT
public:
    TrackControlsWidget(QWidget* parent = nullptr);
    ~TrackControlsWidget();
    void update();
private:
    int video_tracks;
    int audio_tracks;
    QVBoxLayout* track_box_layout;
    //QVector<TrackControlsBox*> track_control_boxes;
};

#endif // TRACKCONTROLSWIDGET_H
