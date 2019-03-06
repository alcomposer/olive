#ifndef TRACKCONTROLSBOX_H
#define TRACKCONTROLSBOX_H

#include "project/sequence.h"
#include "project/clip.h"
#include "project/footage.h"
#include "project/media.h"
#include "project/undo.h"
#include "timelinetools.h"

#include <QObject>
#include <QWidget>
#include <QPainter>

class Timeline;

class TrackControlsBox : public QWidget
{
    Q_OBJECT
public:
    TrackControlsBox(QString text, QWidget* parent = nullptr);
    ~TrackControlsBox();
    void paintEvent(QPaintEvent *);
};

#endif // TRACKCONTROLSBOX_H
