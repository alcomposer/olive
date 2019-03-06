#ifndef TRACKCONTROLS_H
#define TRACKCONTROLS_H

#include "project/sequence.h"
#include "project/clip.h"
#include "project/footage.h"
#include "project/media.h"
#include "project/undo.h"
#include "timelinetools.h"

#include <QObject>
#include <QWidget>

class Timeline;

class TrackControls : public QWidget
{
    Q_OBJECT
public:
    TrackControls(QWidget* parent = nullptr);
    void update();
private:
    void paintEvent(QPaintEvent*);
};

#endif // TRACKCONTROLS_H
