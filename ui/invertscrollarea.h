#ifndef INVERTSCROLLAREA_H
#define INVERTSCROLLAREA_H

#include <QObject>

class InvertScrollArea : public QObject
{
    Q_OBJECT
public:
    InvertScrollArea(QObject* parent);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // INVERTSCROLLAREA_H
