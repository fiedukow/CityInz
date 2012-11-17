#include <QApplication>
#include "CitiInz.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  CitiInz w;
  w.show();
  
  return a.exec();
}
