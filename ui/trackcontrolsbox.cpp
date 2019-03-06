#include "trackcontrolsbox.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

TrackControlsBox::TrackControlsBox(QString text, QWidget* parent) :
    QWidget(parent)
{
    QLabel* test = new QLabel(text);
    QPushButton* buttonTest = new QPushButton();
    QHBoxLayout * layoutTest = new QHBoxLayout();
    layoutTest->addWidget(test);
    layoutTest->addWidget(buttonTest);
    setLayout(layoutTest);

}

TrackControlsBox::~TrackControlsBox()
{

}

void TrackControlsBox::paintEvent(QPaintEvent *)
{
            QPainter p(this);
            p.setPen(QColor(255,255,255,255));
            p.drawRect(this->rect());
}
