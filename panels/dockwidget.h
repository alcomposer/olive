#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>
#include "windowtitlewidget.h"

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QWidget * parent);
    ~DockWidget();

private:
    WindowTitleWidget * titleBar;
};

#endif // DOCKWIDGET_H
