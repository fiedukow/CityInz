#ifndef ROADGRAPH_H
#define ROADGRAPH_H

#include "Coords.h"

#include <map>
#include <vector>
#include <memory>

struct MetricCoords;
struct Edge;
class  RoadGraph;

typedef long long VertexId;
typedef std::map<VertexId, MetricCoords> VertexMap;
typedef std::vector<Edge> EdgesVector;
typedef std::shared_ptr<RoadGraph> RoadGraphPtr;

struct Edge
{
  Edge(VertexId f, VertexId s);
  const VertexId f;
  const VertexId s;
};

enum EdgeDirection { F_TO_S, S_TO_F };

class VertexManager
{
public:
  virtual void addVertex(VertexId id, GeoCoords coords) = 0;
  virtual const GeoCoords& getVertexCoords(VertexId id) const = 0;
};

class RoadGraph : public VertexManager
{
public:
  RoadGraph();
  void addVertex(VertexId id, GeoCoords coords);
  void addEdge(VertexId f, VertexId s);

  VertexMap::const_iterator vertexBegin() const;
  VertexMap::const_iterator vertexEnd() const;

  EdgesVector::const_iterator edgesBegin() const;
  EdgesVector::const_iterator edgesEnd() const;

  const GeoCoords& getVertexCoords(VertexId id) const;
  GeoCoords maxCoords() const;

  void timePassed(double secs);

  void normalize();
  void scale(double scale);

private:
  VertexMap vertexes;
  EdgesVector edges;
  CarsVector cars;
};

#endif // ROADGRAPH_H
