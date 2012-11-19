#ifndef CAR_H
#define CAR_H
#include "RoadGraph.h"

class Car;
enum EdgeDirection { F_TO_S, S_TO_F };

class Car
{
public:
  Car(Edge currentEdge,
      GeoCoords currentPosition,
      double currentSpeed = 20,
      EdgeDirection currentDirection = F_TO_S);
  void timePassed(double secs);

private:
  Edge currentEdge;
  EdgeDirection currentDirection;
  double currentSpeed; /* m/s */
  GeoCoords currentPosition;
  RoadGraph& parent;
};

#endif // CAR_H
