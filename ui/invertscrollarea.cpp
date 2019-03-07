#include "invertscrollarea.h"

#include <QEvent>
#include <QDebug>
#include <QScrollArea>

InvertScrollArea::InvertScrollArea(QObject* parent) : QObject (parent)
{

}
bool InvertScrollArea::eventFilter(QObject *obj, QEvent* event)
{
    if(event->type() == QEvent::Resize){
        qInfo() << "resizeing graphics scene";
        //QScrollArea * myObject = static_cast<QScrollArea*>(obj);
        return true;
    }
    else {
        return false;//QObject::eventFilter(obj,event);
    }
}
