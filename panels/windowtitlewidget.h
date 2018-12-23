#ifndef WINDOWTITLEWIDGET_H
#define WINDOWTITLEWIDGET_H

#include <QTabWidget>
#include <QTabBar>
#include <QDockWidget>

class WindowTitleWidget : public QTabWidget
{
    Q_OBJECT
public:
    WindowTitleWidget(QDockWidget * parent);
    ~WindowTitleWidget();
private:
    QString title;
    QTabBar * tab_bar;
};

#endif // WINDOWTITLEWIDGET_H
