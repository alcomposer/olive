#include "trackcontrols.h"

#include <QPainter>

TrackControls::TrackControls(QWidget* parent) :
    QWidget(parent),
    track_controls_layout(new QVBoxLayout()),
    video_track_controls(new TrackControlsWidget()),
    splitter_(new QSplitter()),
    audio_track_controls(new TrackControlsWidget())

{
    setMinimumWidth(100);
    //track_controls_layout->addWidget(video_track_controls);
    //splitter_->setChildrenCollapsible(false);
    //splitter_->setOrientation(Qt::Vertical);
    //track_controls_layout->addWidget(splitter_);
    //track_controls_layout->addWidget(audio_track_controls);
    splitter_->addWidget(video_track_controls);
    splitter_->addWidget(audio_track_controls);
    track_controls_layout->addWidget(splitter_);
    setLayout(track_controls_layout);

    setVisible(false);
}

void TrackControls::paintEvent(QPaintEvent* event)
{
   /* if(olive::ActiveSequence != nullptr){

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
*/
}

void TrackControls::update(){
    if(olive::ActiveSequence != nullptr){
        setVisible(true);
    }else setVisible(false);
}
