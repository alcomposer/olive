#include "trackcontrolsbox.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

TrackControlsBox::TrackControlsBox(QString text, QWidget* parent) :
    QWidget(parent)
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
            p.setPen(QColor(255,255,255,25));
            p.drawRect(rect().x(), rect().y(), rect().width()-1, rect().height()-1);
}
