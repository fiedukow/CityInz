#ifndef CITIINZ_H
#define CITIINZ_H

#include "RoadGraph.h"
#include <QMainWindow>

class CityMapFrame;

class CitiInz : public QMainWindow
{
  Q_OBJECT

public:
  CitiInz(RoadGraphPtr graph, QWidget *parent = 0);
  ~CitiInz();
private:
  CityMapFrame* drawFrame;
};

#endif // CITIINZ_H
