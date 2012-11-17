#ifndef ROADGRAPHREADER_H
#define ROADGRAPHREADER_H

#include <string>
#include "RoadGraph.h"

class RoadGraphReader
{
public:
  RoadGraphReader(const std::string& graphFilePath);
  RoadGraph readRoadGraph();

private:
  std::string graphFilePath;
};

#endif // ROADGRAPHREADER_H
