#ifndef WINDOWTITLEWIDGET_H
#define WINDOWTITLEWIDGET_H

#include <QTabWidget>
#include <QTabBar>
#include <QDockWidget>
#include "mainwindow.h"

class WindowTitleWidget : public QTabWidget
{
    Q_OBJECT
public:
    WindowTitleWidget(QDockWidget * parent);
    ~WindowTitleWidget();
        QTabBar * tab_bar;
public slots:
    void update_me(bool hasChanged);
private:
    QString title;
    QDockWidget * parent;
};

#endif // WINDOWTITLEWIDGET_H
