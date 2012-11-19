#include "RoadGraphReader.h"
#include <fstream>
#include <exception>

RoadGraphReader::RoadGraphReader(const std::string& graphFilePath)
  : graphFilePath(graphFilePath)
{
}

RoadGraphPtr RoadGraphReader::readRoadGraph()
{
  RoadGraphPtr result(new RoadGraph);
  std::fstream inputFile;
  try
  {
    inputFile.open(graphFilePath.c_str(), std::ios_base::in);
  }
  catch (std::exception& e)
  {
    return NULL;
  }

  VertexId id = 0;
  double lat, lon;
  while (inputFile.good() && id >= 0)
  {
    inputFile >> id;
    if (id >= 0)
    {
      inputFile >> lat >> lon;
      result->addVertex(id, GeoCoords(lat, lon));
    }
  }

  VertexId beg, end;
  double dist;
  int lanes, speed;
  while (inputFile.good())
  {
    inputFile >> beg >> end >> dist >> lanes >> speed;
    result->addEdge(beg, end);
  }

  result->addRandomCar();

  return result;
}
