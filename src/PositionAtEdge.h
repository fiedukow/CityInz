#ifndef POSITIONATEDGE_H
#define POSITIONATEDGE_H
#include "RoadGraph.h"

class PositionAtEdge
{
public:
  PositionAtEdge(const Edge& edge,
                 const VertexManager& manager,
                 EdgeDirection direction = F_TO_S,
                 double startingPosition = 0.0);

private:
  const VertexManager& vertexManager;
  const Edge& edge;
  const EdgeDirection direction;
  const double lenght;
  double distancePassed;
};

#endif // POSITIONATEDGE_H
