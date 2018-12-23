#include "dockwidget.h"

DockWidget::DockWidget(QWidget * parent) :
    QDockWidget (parent),
    titleBar(new WindowTitleWidget(this))
{
    setTitleBarWidget(titleBar);
}

DockWidget::~DockWidget()
{

}
