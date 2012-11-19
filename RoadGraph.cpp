#include "RoadGraph.h"

Edge::Edge(VertexId f, VertexId s)
  : f(f), s(s)
{
}

GeoCoords::GeoCoords()
  : lat(0), lon(0)
{}

GeoCoords::GeoCoords(double lat, double lon)
  : lat(lat), lon(lon)
{}

RoadGraph::RoadGraph()
{
}

void RoadGraph::addVertex(VertexId id, GeoCoords coords)
{
  vertexes[id] = coords;
}

void RoadGraph::addEdge(VertexId f, VertexId s)
{
  edges.push_back(Edge(f, s));
}

VertexMap::const_iterator RoadGraph::vertexBegin() const
{
  return vertexes.begin();
}

VertexMap::const_iterator RoadGraph::vertexEnd() const
{
  return vertexes.end();
}

EdgesList::const_iterator RoadGraph::edgesBegin() const
{
  return edges.begin();
}

EdgesList::const_iterator RoadGraph::edgesEnd() const
{
  return edges.end();
}

const GeoCoords& RoadGraph::getVertexCoords(VertexId id) const
{
  VertexMap::const_iterator i = vertexes.find(id);
  if (i != vertexes.end())
    return i->second;

  throw std::exception(); //TODO
}

GeoCoords RoadGraph::maxCoords() const
{
  double maxlat = 0, maxlon = 0;
  for (VertexMap::const_iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    const GeoCoords& c = i->second;
    if (c.lat > maxlat) maxlat = c.lat;
    if (c.lon > maxlon) maxlon = c.lon;
  }
  return GeoCoords(maxlat, maxlon);
}


void RoadGraph::normalize()
{
  double minlat = 91, minlon = 181;
  for (VertexMap::const_iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    const GeoCoords& c = i->second;
    if (c.lat < minlat) minlat = c.lat;
    if (c.lon < minlon) minlon = c.lon;
  }

  for (VertexMap::iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    GeoCoords& c = i->second;
    c.lat -= minlat;
    c.lon -= minlon;
  }
}

void RoadGraph::scale(double scale)
{
  for (VertexMap::iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    GeoCoords& c = i->second;
    c.lat *= scale;
    c.lon *= scale;
  }
}
