#ifndef TRACKCONTROLSWIDGET_H
#define TRACKCONTROLSWIDGET_H

#include "project/sequence.h"
#include "project/clip.h"
#include "project/footage.h"
#include "project/media.h"
#include "project/undo.h"
#include "timelinetools.h"

#include <QObject>
#include <QWidget>

class Timeline;

class TrackControlsWidget : public QWidget
{
    Q_OBJECT
public:
    TrackControlsWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*);
};

#endif // TRACKCONTROLSWIDGET_H
