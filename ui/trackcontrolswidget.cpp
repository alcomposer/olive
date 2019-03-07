#include "trackcontrolswidget.h"

#include <QPainter>
#include <QDebug>
#include "timelinetools.h"
#include "timelineheader.h"
#include "timelinewidget.h"
#include "panels/panels.h"

#include <QLabel>
#include <QEvent>

TrackControlsWidget::TrackControlsWidget(olive::tracktype type, QWidget* parent) :
    QWidget(parent)
    ,trackCount(0)
    ,_type(type)
    ,scroll(0)

{
    setMinimumWidth(150);
    setMaximumWidth(150);

    scroll_area = new QScrollArea();
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scroll_area->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    scroll_area->setWidgetResizable(true);
    scroll_area->setAlignment(Qt::AlignBottom);
    scroll_area->setContentsMargins(0,0,0,0);

    track_box_layout = new QVBoxLayout();
    track_box_layout->setContentsMargins(0,0,0,0);
    track_box_layout->setSpacing(0);

    layout_holder = new QWidget();
    layout_holder->setLayout(track_box_layout);
    layout_holder->setContentsMargins(0,0,0,0);

    scroll_area->setWidget(layout_holder);

    final_layout = new QVBoxLayout();
    final_layout->addWidget(scroll_area);
    final_layout->setSpacing(0);
    final_layout->setContentsMargins(0,0,0,0);

    setLayout(final_layout);
    setVisible(false);


}
TrackControlsWidget::~TrackControlsWidget()
{

}

void TrackControlsWidget::paintEvent(QPaintEvent*)
{
    //better to put this into a subclass of QScrollArea? Or do it propperly? FIXME
    if (!_type)scroll_area->verticalScrollBar()->setSliderPosition(scroll_area->verticalScrollBar()->maximum());
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

        QString text;
        if (_type == olive::VideoTrack) {
            track_box_layout->setDirection(QBoxLayout::BottomToTop);
            text = "V";
        } else text = "A";
        int trackLimit = _type == olive::VideoTrack? video_track_limit : audio_track_limit+1;

        bool rebuilding = false;

        if (track_box_layout->count()-1 == track_control_boxes.count() & trackCount != qAbs(trackLimit)){
            track_box_layout->removeWidget(track_box_layout->itemAt(track_box_layout->count()-1)->widget());
            qInfo() << "removing Spacer";
        }

        while (trackCount < qAbs(trackLimit)){
            track_control_boxes.push_back(new TrackControlsBox(QString(text+QString::number(trackCount+1))));
            track_control_boxes.at(trackCount)->setContentsMargins(0,0,0,0);
            track_box_layout->addWidget(track_control_boxes.at(trackCount));
            trackCount++;
            rebuilding = true;
            qInfo() << "adding widgets";
        }
        while (trackCount > qAbs(trackLimit)){
            trackCount--;
            track_box_layout->removeWidget(track_control_boxes.at(trackCount));
            track_control_boxes.at(trackCount)->deleteLater();
            track_control_boxes.pop_back();
            rebuilding = true;
            qInfo() << "removing widgets";
        }
        if(track_box_layout->count() == track_control_boxes.count()){
        track_box_layout->addStretch(1);
        rebuilding = true;
        qInfo() << "adding spacer";
        }

        for (int i = 0; i < track_control_boxes.count(); i++){
            track_box_layout->itemAt(i)->widget()->setMinimumHeight(panel_timeline->GetTrackHeight(_type? i: (i*-1)-1)+(_type?1:1));
    }
        if (rebuilding) qInfo() <<"doing an update";

        setVisible(true);
    }else {
    setVisible(false);
    }
    repaint();
}

void TrackControlsWidget::resizeEvent(QResizeEvent *) {
}
