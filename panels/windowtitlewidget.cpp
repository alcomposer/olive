#include "windowtitlewidget.h"

#include "debug.h"

WindowTitleWidget::WindowTitleWidget(QDockWidget * parent):
    tab_bar(new QTabBar(this)),
    title(""),
    parent(parent)
{

}
WindowTitleWidget::~WindowTitleWidget()
{

}

void WindowTitleWidget::setTabText(QString tabTitle)
{
    title = tabTitle;
    update_me(false);
}
void WindowTitleWidget::update_me(bool hasChanged){
    if (mainWindow->tabifiedDockWidgets(parent).isEmpty()){
        addTab(tab_bar, title);
    } else {
        removeTab(0);
        QList<QTabBar*> tabifiedDocks = mainWindow->findChildren<QTabBar*>();

        //add a close button to all real tabs, this shouldn't be here.
        foreach (QTabBar* realTab, tabifiedDocks){
            realTab->setTabsClosable(true);
        }
    }
}
