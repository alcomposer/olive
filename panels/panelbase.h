#ifndef PANELBASE_H
#define PANELBASE_H

#include <QDockWidget>
#include <QString>



class EffectControls;
class Project;
class Viewer;
class Timeline;

class PanelTitle;

class PanelBase : public QDockWidget
{
    Q_OBJECT
public:
    PanelBase(QWidget *parent,QString title, QString status);
    ~PanelBase();
    void setTitleText(QString titleText);
    void setStatusText(QString statusText);
    QString getTitleText();
    QString getStatusText();
private:
    QString title_text;
    QString status_text;
    PanelTitle * titleWidget;
};

#endif // PANELBASE_H
