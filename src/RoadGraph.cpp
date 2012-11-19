#include "RoadGraph.h"
#include <cstdlib>

Edge::Edge(VertexId f, VertexId s)
  : f(f), s(s)
{
}

RoadGraph::RoadGraph()
{
}

void RoadGraph::addVertex(VertexId id, MetricCoords coords)
{
  vertexes.insert(std::make_pair(id, coords));
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

EdgesVector::const_iterator RoadGraph::edgesBegin() const
{
  return edges.begin();
}

EdgesVector::const_iterator RoadGraph::edgesEnd() const
{
  return edges.end();
}

const MetricCoords& RoadGraph::getVertexCoords(VertexId id) const
{
  VertexMap::const_iterator i = vertexes.find(id);
  if (i != vertexes.end())
    return i->second;

  throw std::exception(); //TODO
}

MetricCoords RoadGraph::maxCoords() const
{
  double maxx = 0, maxy = 0;
  for (VertexMap::const_iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    const MetricCoords& c = i->second;
    if (c.y > maxy) maxy = c.y;
    if (c.x > maxx) maxx = c.x;
  }
  return MetricCoords(maxx, maxy);
}

void RoadGraph::timePassed(double secs)
{
}

void RoadGraph::normalize()
{
  double minlat = 91, minlon = 181;
  for (VertexMap::const_iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    const MetricCoords& c = i->second;
    if (c.y < minlat) minlat = c.y;
    if (c.x < minlon) minlon = c.x;
  }

  for (VertexMap::iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    MetricCoords& c = i->second;
    c.y -= minlat;
    c.x -= minlon;
  }
}

void RoadGraph::scale(double scale)
{
  for (VertexMap::iterator i = vertexes.begin(); i!= vertexes.end(); ++i)
  {
    MetricCoords& c = i->second;
    c.y *= scale;
    c.x *= scale;
  }
}
