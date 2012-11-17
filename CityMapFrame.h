#ifndef CITYMAPFRAME_H
#define CITYMAPFRAME_H
#include <QFrame>

class QPaintEvent;

class CityMapFrame : public QFrame
{
  Q_OBJECT
public:
  CityMapFrame(QWidget* parent);
protected:
  virtual void paintEvent(QPaintEvent *event);
};
#endif // CITYMAPFRAME_H
