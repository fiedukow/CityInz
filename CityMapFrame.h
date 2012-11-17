#ifndef CITYMAPFRAME_H
#define CITYMAPFRAME_H
#include <QFrame>
#include <QImage>
#include "RoadGraph.h"

class QPaintEvent;

class CityMapFrame : public QFrame
{
  Q_OBJECT
public:
  CityMapFrame(QWidget* parent, RoadGraphPtr graph);
protected:
  virtual void paintEvent(QPaintEvent *event);
private:
  RoadGraphPtr graph;
  QImage img;
};
#endif // CITYMAPFRAME_H
