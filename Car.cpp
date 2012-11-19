#include "Car.h"

Car::Car(const RoadGraph& graph,
         Edge currentEdge,
         GeoCoords currentPosition,
         double currentSpeed = 20,
         EdgeDirection currentDirection = F_TO_S)
  : currentEdge(currentEdge),
    currentPosition(currentPosition),
    currentSpeed(currentSpeed),
    currentDirection(currentDirection),
    parent(graph)
{
}

void Car::timePassed(double secs)
{
  double distPassed = secs * currentSpeed;
  parent.getVertexCoords(currentEdge);
}
