#include "trackcontrolsbox.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

TrackControlsBox::TrackControlsBox(QString text, QWidget* parent) :
    QWidget(parent)
{

    //setMinimumHeight(0);
    QLabel* test = new QLabel(text);
    test->setContentsMargins(0,0,0,0);
    test->setMinimumHeight(0);
    QPushButton* buttonTest = new QPushButton();
    buttonTest->setContentsMargins(0,0,0,0);
    buttonTest->setMinimumHeight(0);

    QHBoxLayout * layoutTest = new QHBoxLayout();
    layoutTest->addWidget(test);
    layoutTest->addWidget(buttonTest);

    layoutTest->setContentsMargins(0,0,0,0);
    layoutTest->setMargin(0);
    setContentsMargins(0,0,0,0);
    //setLayout(layoutTest);

}

TrackControlsBox::~TrackControlsBox()
{

}

void TrackControlsBox::paintEvent(QPaintEvent *)
{
            QPainter p(this);
            p.setPen(QColor(255,255,255,255));
            //p.drawLine(this->rect().x(), rect().y(),rect().width(),rect().y() );
            p.drawRect(rect());
}
