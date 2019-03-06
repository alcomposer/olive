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
#include <QScrollBar>

class Timeline;

namespace olive{
enum tracktype {VideoTrack,AudioTrack};
}

class TrackControlsWidget : public QWidget
{
    Q_OBJECT
public:
    TrackControlsWidget(olive::tracktype type = olive::VideoTrack, QWidget* parent = nullptr);
    ~TrackControlsWidget();
    void update();
    void resizeEvent(QResizeEvent *);
    QScrollBar * scrollBar;
private:
    int scroll;
    int trackCount;
    olive::tracktype _type;
    QVBoxLayout* track_box_layout;
    QVector<TrackControlsBox*> track_control_boxes;
public slots:
  void setScroll(int);
};

#endif // TRACKCONTROLSWIDGET_H
