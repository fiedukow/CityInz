#ifndef ROADGRAPH_H
#define ROADGRAPH_H

#include <map>
#include <list>

struct GeoCoords;
struct Edge;

typedef unsigned long long VertexId;
typedef std::map<VertexId, GeoCoords> VertexMap;
typedef std::list<Edge> EdgesList;

struct Edge
{
  Edge(VertexId f, VertexId s);
  const VertexId f;
  const VertexId s;
};

struct GeoCoords
{
  GeoCoords();
  GeoCoords(double lat, double lon);
  double lat;
  double lon;
};

class RoadGraph
{
public:
  RoadGraph();
  void addVertex(VertexId id, GeoCoords coords);
  bool addEdge(VertexId f, VertexId s);

  VertexMap::const_iterator vertexBegin() const;
  VertexMap::const_iterator vertexEnd() const;

  EdgesList::const_iterator edgesBegin() const;
  EdgesList::const_iterator edgesEnd() const;

private:
  VertexMap vertexes;
  EdgesList edges;
};

#endif // ROADGRAPH_H
