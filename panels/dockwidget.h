#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>
#include "windowtitlewidget.h"
#include "mainwindow.h"

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QWidget * parent);
    ~DockWidget();

    void setTitle(QString);
private:
    WindowTitleWidget * title_bar;
};

#endif // DOCKWIDGET_H
