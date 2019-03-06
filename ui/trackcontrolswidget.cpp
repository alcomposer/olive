#include "trackcontrolswidget.h"

#include <QPainter>
#include <QDebug>

TrackControlsWidget::TrackControlsWidget(QWidget* parent) :
    QWidget(parent)
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
        auto boxes =  this->findChildren<TrackControlsBox*>();
        foreach(auto mywidgets, boxes){
            track_box_layout->removeWidget(mywidgets);
            mywidgets->deleteLater();
            qInfo() << "removing widget: " << mywidgets;
        }
        //QVBoxLayout* track_box_layout = new QVBoxLayout();
        //setLayout(track_box_layout);
        int video_track_limit = 0;
        int audio_track_limit = 0;
        for (int i=0;i<olive::ActiveSequence->clips.size();i++) {
            ClipPtr clip = olive::ActiveSequence->clips.at(i);
            if (clip != nullptr) {
                video_track_limit = qMin(video_track_limit, clip->track());
                audio_track_limit = qMax(audio_track_limit, clip->track());
            }
        }
        qInfo() << "alex track limit is: " << video_track_limit;
            for (int i=-1;i>=video_track_limit;i--) {
                TrackControlsBox* testTrack = new TrackControlsBox();
                testTrack->setMinimumHeight(50);
                track_box_layout->addWidget(testTrack);
        }
        //setLayout(track_box_layout);
        setVisible(true);
    }else setVisible(false);
}
