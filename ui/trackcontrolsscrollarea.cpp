#include "trackcontrolsscrollarea.h"

TrackControlsScrollArea::TrackControlsScrollArea(QWidget *parent) :
    QScrollArea (parent)
{

}

void TrackControlsScrollArea::wheelEvent(QWheelEvent *)
{
    //currently blocking any wheel events that get sent to the ScrollArea,
    //have to make this work properly with the edit area
    //Or possibly have different functionality?

    //Premiere Pro uses wheel event per track header to resize track, maybe do that?
}
