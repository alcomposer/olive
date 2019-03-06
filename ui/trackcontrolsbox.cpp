#include "trackcontrolsbox.h"

TrackControlsBox::TrackControlsBox(QWidget* parent) :
    QWidget(parent)
{

}

TrackControlsBox::~TrackControlsBox()
{

}

void TrackControlsBox::paintEvent(QPaintEvent *)
{
            QPainter p(this);
            p.setPen(QColor(255,255,255,255));
            p.drawRect(this->rect());
}
