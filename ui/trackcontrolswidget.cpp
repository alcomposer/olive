#include "trackcontrolswidget.h"

#include <QPainter>
#include <QDebug>
#include "timelinetools.h"
#include "timelineheader.h"
#include "timelinewidget.h"
#include "panels/panels.h"

#include <QLabel>


TrackControlsWidget::TrackControlsWidget(olive::tracktype type, QWidget* parent) :
    QWidget(parent)
    ,trackCount(0)
    ,_type(type)
    ,scroll(0)
    ,track_box_layout(new QVBoxLayout())

{
    setMinimumWidth(150);
    setMaximumWidth(150);
    setLayout(track_box_layout);

    setVisible(false);
}
TrackControlsWidget::~TrackControlsWidget()
{

}

void TrackControlsWidget::update(){
    if(olive::ActiveSequence != nullptr){
        //find current video track size
        int video_track_limit = 0;
        int audio_track_limit = 0;
        for (int i=0;i<olive::ActiveSequence->clips.size();i++) {
            ClipPtr clip = olive::ActiveSequence->clips.at(i);
            if (clip != nullptr) {
                video_track_limit = qMin(video_track_limit, clip->track());
                audio_track_limit = qMax(audio_track_limit, clip->track());
            }
        }
//---------------------------------

        int panel_height = olive::timeline::kTrackDefaultHeight;

        // loop through tracks for maximum panel height
        if (!_type) {
          for (int i=-1;i>=video_track_limit;i--) {
            panel_height += panel_timeline->GetTrackHeight(i);
          }
        } else {
          for (int i=0;i<=audio_track_limit;i++) {
            panel_height += panel_timeline->GetTrackHeight(i);
          }
        }
       // if (!_type) {
       //   scrollBar->setMinimum(qMin(0, - panel_height + height()));
        //} else {
        //  scrollBar->setMaximum(qMax(0, panel_height - height()));
      //  }

//---------------------------------------
        QString text;
        if (_type == olive::VideoTrack) {
            track_box_layout->setDirection(QBoxLayout::BottomToTop);
            text = "V: ";
        } else text = "A: ";
        //qInfo() << "audio track count: " << audio_track_limit << " video track count: " << video_track_limit;
        int trackLimit = _type == olive::VideoTrack? video_track_limit : audio_track_limit+1;

        while (trackCount < qAbs(trackLimit)){
            track_control_boxes.push_back(new TrackControlsBox(QString(text+QString::number(trackCount+1))));
            track_control_boxes.at(trackCount)->setMinimumHeight(10);
            track_box_layout->addWidget(track_control_boxes.at(trackCount));
            trackCount++;
        }
        while (trackCount > qAbs(trackLimit)){
            trackCount--;
            track_box_layout->removeWidget(track_control_boxes.at(trackCount));
            track_control_boxes.at(trackCount)->deleteLater();
            track_control_boxes.pop_back();
        }
        setVisible(true);
    }else
setVisible(false);
}

void TrackControlsWidget::resizeEvent(QResizeEvent *) {
  //scrollBar->setPageStep(height());
}
