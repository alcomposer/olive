#include "trackcontrols.h"

#include <QPainter>

TrackControls::TrackControls(QWidget* parent) :
    QWidget(parent)
{
    setMinimumWidth(100);
    setVisible(false);
}

void TrackControls::paintEvent(QPaintEvent* event)
{
    if(olive::ActiveSequence != nullptr){
        QPainter test(this);
        test.setPen(QColor(255,255,255,255));
        test.drawRect(this->rect());
    }
}

void TrackControls::update(){
    if(olive::ActiveSequence != nullptr){
        setVisible(true);
    }else setVisible(false);
}
