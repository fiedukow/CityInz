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

