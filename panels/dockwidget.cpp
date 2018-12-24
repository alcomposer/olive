#include "dockwidget.h"

#include "debug.h"

DockWidget::DockWidget(QWidget * parent) :
    QDockWidget (parent),
    title_bar(new WindowTitleWidget(this))
{
    mainWindow->panels.push_back(this);
    setTitleBarWidget(title_bar);
    //connect(parent, SIGNAL(tabCloseRequested(int)), this, SLOT(slotCloseTab(int)));

}

DockWidget::~DockWidget()
{

}
void DockWidget::setTitle(QString text){
    if (text.length() > 30){
        text.resize(30);
        text += "...";
    }
    title_bar->setTabText(text);
    setWindowTitle(text);
}

void DockWidget::slotCloseTab(int)
{
   // dout << "wanting to close tab";
}
