#include <ctime>
#include <cstdlib>

#include <QApplication>

#include "CitiInz.h"
#include "RoadGraphReader.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  srand(time(NULL));
  RoadGraphReader r("warsaw.map");
  CitiInz w(r.readRoadGraph());
  w.show();

  return a.exec();
}
