#ifndef CITIINZ_H
#define CITIINZ_H

#include <QMainWindow>

class CityMapFrame;

class CitiInz : public QMainWindow
{
  Q_OBJECT

public:
  CitiInz(QWidget *parent = 0);
  ~CitiInz();
private:
  CityMapFrame* drawFrame;
};

#endif // CITIINZ_H
