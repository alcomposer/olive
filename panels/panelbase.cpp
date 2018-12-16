#include "panelbase.h"
#include "paneltitle.h"



PanelBase::PanelBase(QWidget * parent):
    QDockWidget(parent)
{
    parentWidget()->setWindowTitle(title_text);
    setTitleBarWidget(titleWidget = new PanelTitle(this));
}
PanelBase::~PanelBase()
{

}

void PanelBase::setTitleText(QString titleText)
{
    title_text=titleText;
    setWindowTitle(title_text);
    titleWidget->setPanelTitle(&titleText);
}

void PanelBase::setStatusText(QString statusText)
{
    status_text = statusText;
    titleWidget->setPanelStatus(&status_text);
}

QString PanelBase::getTitleText()
{
    return title_text;
}

QString PanelBase::getStatusText()
{
    return status_text;
}


