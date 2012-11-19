#include "CitiInz.h"
#include "CityMapFrame.h"
#include "RoadGraph.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QScrollArea>

CitiInz::CitiInz(RoadGraphPtr graph, QWidget *parent)
  : QMainWindow(parent)
{
  QFrame* mainFrame = new QFrame(this);
  setCentralWidget(mainFrame);
  QVBoxLayout* ly = new QVBoxLayout(mainFrame);
  ly->addWidget(new QLabel("Mapa warszawy", mainFrame));


  QScrollArea* scrollable = new QScrollArea(mainFrame);
  drawFrame = new CityMapFrame(scrollable, graph);
  drawFrame->setFrameStyle(QFrame::Box);
  drawFrame->setMinimumSize(5000, 5000);
  scrollable->setWidget(drawFrame);
  ly->addWidget(scrollable);
  ly->setStretch(1, 1);

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(100);
}

CitiInz::~CitiInz()
{
}
