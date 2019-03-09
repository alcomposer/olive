#include "trackcontrolsbox.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>


TrackControlsBox::TrackControlsBox(QString text, bool type, QWidget* parent) :
    QWidget(parent)
    ,track_type(type) //FIXME better to pass in a flag than this bool? Or anther way?
{
    QLabel* test = new QLabel(text);
    test->setContentsMargins(0,0,0,0);
    test->setMinimumHeight(0);
    QPushButton* buttonText = new QPushButton(text);
    buttonText->setMaximumWidth(30);
    QLineEdit* trackName = new QLineEdit();
    trackName->setContentsMargins(0,0,0,0);
    trackName->setMinimumHeight(0);

    QHBoxLayout* firstLine = new QHBoxLayout();
    firstLine->addWidget(buttonText);
    firstLine->addWidget(trackName);
    firstLine->setContentsMargins(5,0,5,0);
    firstLine->setSpacing(0);

    QWidget* containerWidget = new QWidget();
    containerWidget->setContentsMargins(0,0,0,0);
    containerWidget->setMinimumHeight(0);
    containerWidget->setLayout(firstLine);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(containerWidget);
    vLayout->setContentsMargins(0,3,0,0);
    vLayout->setSpacing(0);
    vLayout->addStretch(1);
    setMinimumHeight(0);

    setLayout(vLayout);
}

TrackControlsBox::~TrackControlsBox()
{

}

void TrackControlsBox::paintEvent(QPaintEvent *)
{
            QPainter p(this);
            p.setPen(QColor(0,0,0,96));
            if (!track_type){
                p.drawLine(0,0,width(),0);
            } else {
                p.drawLine(0,height()-2,width(),height()-2);
                //FIXME manually moving the line to align, but buttons wont perfectly
                //align, need to research more why the audio track headers are off by 2px
            }
}
