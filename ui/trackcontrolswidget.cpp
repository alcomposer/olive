#include "trackcontrolswidget.h"

#include <QPainter>

TrackControlsWidget::TrackControlsWidget(QWidget* parent) :
    QWidget(parent)
{

}

void TrackControlsWidget::paintEvent(QPaintEvent *)
{
    if(olive::ActiveSequence != nullptr){

            // get widget width and height
            int video_track_limit = 0;
            int audio_track_limit = 0;
            for (int i=0;i<olive::ActiveSequence->clips.size();i++) {
              ClipPtr clip = olive::ActiveSequence->clips.at(i);
              if (clip != nullptr) {
                video_track_limit = qMin(video_track_limit, clip->track());
                audio_track_limit = qMax(audio_track_limit, clip->track());
              }
            }
            QPainter p(this);
            p.setPen(QColor(255,255,255,255));
            p.drawRect(this->rect());
    }
}
