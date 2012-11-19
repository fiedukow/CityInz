#include "CityMapFrame.h"

#include <QPainter>
#include <iostream>
#include <ctime>

CityMapFrame::CityMapFrame(QWidget* parent, RoadGraphPtr graph)
  : QFrame(parent), graph(graph)
{
  time_t begin = time(NULL);
  graph->normalize();
  graph->scale(10000);
  //int maxLon = graph->maxLon();
  GeoCoords maxCoords = graph->maxCoords();
  int maxLat = maxCoords.lat;
  int maxLon = maxCoords.lon;
  img = QImage(maxLon, maxLat, QImage::Format_RGB32);
  QPainter painter(&img);
  //painter.setRenderHint(QPainter::Antialiasing);
  for(int i = 0; i < 100; ++i)
  {
  QPen pen(Qt::red);
  pen.setColor(QColor::fromRgb(0x7C, 0x41, 0x41));
  pen.setWidth(1);
  pen.setStyle(Qt::DashLine);
  painter.setPen(pen);
  for (int i = 0; i <= 5000; i+=100)
  {
    painter.drawLine(QPoint(0, i), QPoint(5000, i));
    painter.drawLine(QPoint(i, 0), QPoint(i, 5000));
  }

  pen.setColor(Qt::white);
  pen.setWidth(2);
  pen.setStyle(Qt::SolidLine);
  painter.setPen(pen);
  /*
  for (VertexMap::const_iterator i = graph->vertexBegin();
       i != graph->vertexEnd();
       ++i)
  {
    const GeoCoords& c = i->second;
    //std::cout << c.lon << ", " << c.lat << std::endl;
    //painter.drawRect(static_cast<int>(c.lon), static_cast<int>(c.lat), 2, 2);
  }*/

  for (EdgesVector::const_iterator i = graph->edgesBegin();
       i != graph->edgesEnd();
       ++i)
  {
    const GeoCoords& f = graph->getVertexCoords(i->f);
    const GeoCoords& s = graph->getVertexCoords(i->s);
    //std::cout << f.lon << ", " << f.lat << "; ";
    //std::cout << s.lon << ", " << s.lat << std::endl;
    painter.drawLine(QPoint(static_cast<int>(f.lon),
                            maxLat-static_cast<int>(f.lat)),
                     QPoint(static_cast<int>(s.lon),
                            maxLat-static_cast<int>(s.lat)));
  }
  }

  std::cout << "Time taken: " << time(NULL)-begin << std::endl;
}

void CityMapFrame::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QPainter imageDrawer(this);
  imageDrawer.drawImage(0, 0, img);
}
