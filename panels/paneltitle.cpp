#include "paneltitle.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QColor>
#include <QFrame>
#include <QGradient>

#include <debug.h>

PanelTitle::PanelTitle(QDockWidget *parent):
//    _title(""),
//    _info(""),
    QWidget(parent),
    title(new QLabel),
    info(new QLabel),
    layout(new QVBoxLayout),
    parent(parent),
    bg(new QPalette)
{
    bg->setColor(QPalette::Background, QColor(40,40,40));
    QFrame * line = new QFrame();
    QGradient * grad = new QGradient();
    line->setFrameShape(QFrame::HLine);
    //line->setFrameShadow(QFrame::Sunken);

    info->setText("Media Info >");
    title->setText("test");
    title->setAlignment(Qt::AlignHCenter);
    layout->addWidget(title);

    layout->addWidget(info);
    //layout->addWidget(grad);
    setLayout(layout);
    setAutoFillBackground(true);
    //setPalette(*bg);

    show();
    connect(parentWidget(), SIGNAL(visibilityChanged(bool)), this, SLOT(draw_panel_title(bool)));
}

void PanelTitle::setPanelTitle(QString *titleText)
{
//    _title = *titleText;
    title->setText(*titleText);
    draw_panel_title(true);
}
void PanelTitle::setPanelStatus(QString *statusText)
{
//    _info = *statusText;
    info->setText(*statusText);
    draw_panel_title(true);
}
void PanelTitle::draw_panel_title(bool isTopLevel)
{
//    title->setText(_title);
//    info->setText(_info);
        if (mainWindow->tabifiedDockWidgets(parent).isEmpty())
        {
            title->show();
        } else {
            title->hide();
        }
        show();

}

