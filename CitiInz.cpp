#include "CitiInz.h"
#include "CityMapFrame.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

CitiInz::CitiInz(QWidget *parent)
  : QMainWindow(parent)
{
  QFrame* mainFrame = new QFrame(this);
  setCentralWidget(mainFrame);
  QVBoxLayout* ly = new QVBoxLayout(mainFrame);
  ly->addWidget(new QLabel("Mapa warszawy", mainFrame));

  drawFrame = new CityMapFrame(mainFrame);
  drawFrame->setFrameStyle(QFrame::Box);
  ly->addWidget(drawFrame);
  ly->setStretch(1, 1);

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(100);
}

CitiInz::~CitiInz()
{
}
