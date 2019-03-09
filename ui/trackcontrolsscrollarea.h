#ifndef TRACKCONTROLSSCROLLAREA_H
#define TRACKCONTROLSSCROLLAREA_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>

class TrackControlsScrollArea : public QScrollArea
{
    Q_OBJECT
    void wheelEvent(QWheelEvent *) override;
public:
    TrackControlsScrollArea(QWidget* parent = nullptr);
};

#endif // TRACKCONTROLSSCROLLAREA_H
