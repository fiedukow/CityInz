#ifndef ROADGRAPH_H
#define ROADGRAPH_H

#include "Car.h"

#include <map>
#include <vector>
#include <memory>

struct GeoCoords;
struct Edge;
class  RoadGraph;

typedef long long VertexId;
typedef std::map<VertexId, GeoCoords> VertexMap;
typedef std::vector<Edge> EdgesVector;
typedef std::shared_ptr<RoadGraph> RoadGraphPtr;
typedef std::map<unsigned, Car> CarMap;

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
  void addEdge(VertexId f, VertexId s);
  void addRandomCar();

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
