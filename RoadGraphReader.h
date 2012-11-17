#ifndef ROADGRAPHREADER_H
#define ROADGRAPHREADER_H

#include "RoadGraph.h"

#include <string>

class RoadGraphReader
{
public:
  RoadGraphReader(const std::string& graphFilePath);
  RoadGraphPtr readRoadGraph();

private:
  std::string graphFilePath;
};

#endif // ROADGRAPHREADER_H
