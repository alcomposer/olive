#ifndef PANELTITLE_H
#define PANELTITLE_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include "mainwindow.h"

class PanelTitle : public QWidget
{
    Q_OBJECT
public:
    PanelTitle(QDockWidget *parent);
    void setPanelTitle(QString *titleText);
    void setPanelStatus(QString *statusText);
private:
    QLabel * title;
    QLabel * info;
    QVBoxLayout * layout;
    QDockWidget * parent;
    QPalette * bg;
//    QString _title;
//    QString _info;

public slots:
    void draw_panel_title(bool isFloating);
};

#endif // PANELTITLE_H
