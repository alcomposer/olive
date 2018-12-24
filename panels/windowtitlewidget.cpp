#include "windowtitlewidget.h"

#include "debug.h"

WindowTitleWidget::WindowTitleWidget(QDockWidget * parent):
    title("this is a test"),
    tab_bar(new QTabBar(this)),
    parent(parent)
{

    dout << "making window title";

 //   foreach(QDockWidget * panel_widget, mainWindow->panels){
 //   connect(parent, SIGNAL(visibilityChanged(bool)), panel_widget->findChild<WindowTitleWidget*>(), SLOT(update_me(bool)));
 //   }
 //   connect(parent, SIGNAL(visibilityChanged(bool)), this, SLOT(update_me(bool)));


    // addTab(tab_bar, title);
  // setTabsClosable(true); -------------
    //removeTab(0);
    //tab_bar->addTab(title);
}
WindowTitleWidget::~WindowTitleWidget()
{

}

void WindowTitleWidget::setTabText(QString tabTitle)
{
    title = tabTitle;
    update_me(true);
}
void WindowTitleWidget::update_me(bool hasChanged){
    dout << "doing an update";
  //  foreach(QDockWidget * temp, mainWindow->panels){
    //    dout << "   working on: " << temp;
        if (mainWindow->tabifiedDockWidgets(parent).isEmpty()){
    //        dout << "      adding tab to: " << temp->findChild<WindowTitleWidget*>();
     //       temp->findChild<WindowTitleWidget*>()->addTab(tab_bar, title);
            addTab(tab_bar, title);
        } else {
            //temp->findChild<WindowTitleWidget*>()->removeTab(0);
            removeTab(0);
            QList<QTabBar*> tabifiedDocks = mainWindow->findChildren<QTabBar*>();
            //QVector<QDockWidget*> tabifiedDocks = mainWindow->tabifiedDockWidgets(parent).toVector();
            dout << tabifiedDocks;
            foreach (QTabBar* realTab, tabifiedDocks){
               realTab->setTabsClosable(true);
            }
        }
    }
//}
