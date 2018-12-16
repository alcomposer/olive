#include "panelbase.h"
#include "paneltitle.h"

PanelBase::PanelBase(QWidget * parent):
    QDockWidget(parent)
{
    setTitleBarWidget(titleWidget = new PanelTitle(this));
}
PanelBase::~PanelBase()
{

}

void PanelBase::setTitleText(QString titleText)
{
    this->setWindowTitle(titleText);
    titleWidget->setPanelTitle(&titleText);
}

void PanelBase::setStatusText(QString statusText)
{
    titleWidget->setPanelStatus(&statusText);
}

QString PanelBase::getTitleText()
{
    return title_text;
}

QString PanelBase::getStatusText()
{
    return status_text;
}


