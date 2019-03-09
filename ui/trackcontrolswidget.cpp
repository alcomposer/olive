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
    _padding = new QWidget();
    _padding->setMinimumHeight(50); // FIXME hardcode for now, is this even correct value?
    _padding->setContentsMargins(0,0,0,0);
    _padding->setObjectName("padding");

    setMinimumWidth(150); //FIXME hardcode for now
    setMaximumWidth(150);

    scroll_area = new TrackControlsScrollArea();
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

void TrackControlsWidget::setScroll(int value)
{
    scroll = value;
    //scroll_area->verticalScrollBar()->maximum()
    qInfo() << "SCROLL VALUE IS: " << scroll;
    forceRepaint();
}

void TrackControlsWidget::setRange(int min, int max)
{
    qInfo() << "Scroll Range is now: "<< min << " : " << max;
    scroll_max = max;
    scroll_min = min;
}

void TrackControlsWidget::paintEvent(QPaintEvent*)
{
    resetScroll();
}

void TrackControlsWidget::resetScroll()
{
    //better to put this into a subclass of QScrollArea? Or do it propperly? FIXME
    //we set the scroll bar to the bottom when we repaint the tracks


    if (_type == olive::VideoTrack){
        //scroll_area->verticalScrollBar()->setMaximum(scroll_min);
        //scroll_area->verticalScrollBar()->setMinimum(scroll_max);
        scroll_area->verticalScrollBar()->setSliderPosition(scroll_area->verticalScrollBar()->maximum()+scroll); //this inverts the video vertical scroll
    } else {
        scroll_area->verticalScrollBar()->setSliderPosition(scroll);
    }
}

void TrackControlsWidget::forceRepaint()
{
    resetScroll();
    update();
    QWidget::update();
}


void TrackControlsWidget::update(){
    if(olive::ActiveSequence != nullptr){
        resetScroll();
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

        //if track header is being added or taken away remove the padding & stretch widgets first
        if (track_box_layout->count()-2 == trackCount & trackCount != qAbs(trackLimit)){
            track_box_layout->removeWidget(track_box_layout->findChild<QWidget*>("padding"));
            track_box_layout->removeWidget(track_box_layout->itemAt(track_box_layout->count()-1)->widget());
        }

        //add track header widgets untill they have all been added
        while (trackCount < qAbs(trackLimit)){
            track_control_boxes.push_back(new TrackControlsBox(QString(text+QString::number(trackCount+1))));
            track_control_boxes.at(trackCount)->setContentsMargins(0,0,0,0);
            track_box_layout->addWidget(track_control_boxes.at(trackCount));
            trackCount++;
        }
        //reove track header widgets untill all removed
        while (trackCount > qAbs(trackLimit)){
            trackCount--;
            track_box_layout->removeWidget(track_control_boxes.at(trackCount));
            track_control_boxes.at(trackCount)->deleteLater();
            track_control_boxes.pop_back();
        }
        //add back padding widget & stretch
        if(track_box_layout->count() == track_control_boxes.count()){
        track_box_layout->addWidget(_padding);
        track_box_layout->addStretch(1);
        }

        //set height of track header widgets
        for (int i = 0; i < track_control_boxes.count(); i++){
            track_box_layout->itemAt(i)->widget()->setMinimumHeight(panel_timeline->GetTrackHeight(_type? i: (i*-1)-1)+(_type?1:1));
    }

        setVisible(true);
        resetScroll();
    }else {
    setVisible(false);
    }
}


