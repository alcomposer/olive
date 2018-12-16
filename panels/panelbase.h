#ifndef PANELBASE_H
#define PANELBASE_H

#include <QDockWidget>
#include <QString>

class PanelTitle;

class PanelBase : public QDockWidget
{
    Q_OBJECT
public:
    PanelBase(QWidget *parent);
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
