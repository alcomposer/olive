#include "dockwidget.h"

DockWidget::DockWidget(QWidget * parent) :
    QDockWidget (parent),
    title_bar(new WindowTitleWidget(this))
{
    mainWindow->panels.push_back(this);
    setTitleBarWidget(title_bar);

}

DockWidget::~DockWidget()
{

}
