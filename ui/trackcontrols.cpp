#include "trackcontrols.h"

#include <QPainter>

TrackControls::TrackControls(QWidget* parent) :
    QWidget(parent)
{
    setMinimumWidth(200);
}

void TrackControls::paintEvent(QPaintEvent* event)
{
        QPainter test(this);
        test.setPen(QColor(255,255,255,255));
        test.drawRect(this->rect());
}
