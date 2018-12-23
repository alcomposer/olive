#include "windowtitlewidget.h"

#include "debug.h"

WindowTitleWidget::WindowTitleWidget(QDockWidget * parent):
    QTabWidget(parent),
    title("test"),
    tab_bar(new QTabBar(this))
{
    dout << "making window title";
    addTab(tab_bar, "this");
    setTabsClosable(true);
    //removeTab(0);
    //tab_bar->addTab(title);
}
WindowTitleWidget::~WindowTitleWidget(){

}
