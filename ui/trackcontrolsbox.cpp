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
    QPushButton* buttonText = new QPushButton(text);
    buttonText->setMaximumWidth(30);
    //buttonText->setContentsMargins(5,0,0,5);
    QPushButton* buttonTest = new QPushButton();
    buttonTest->setContentsMargins(0,0,0,0);
    buttonTest->setMinimumHeight(0);

    QHBoxLayout * layoutTest = new QHBoxLayout();
    layoutTest->addWidget(buttonText);
    layoutTest->addWidget(buttonTest);

    layoutTest->setContentsMargins(5,0,5,0);
    //layoutTest->setMargin(0);
    //setContentsMargins(0,0,0,0);
    setLayout(layoutTest);

}

TrackControlsBox::~TrackControlsBox()
{

}

void TrackControlsBox::paintEvent(QPaintEvent *)
{
            QPainter p(this);
            p.setPen(QColor(255,255,255,25));
            //p.drawLine(this->rect().x(), rect().y(),rect().width(),rect().y() );
            p.drawRect(rect().x(), rect().y(), rect().width()-1, rect().height()-1);
            //p.drawRect(rect());
}
