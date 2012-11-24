#include "RoadGraphReader.h"
#include "Coords.h"
#include <fstream>
#include <exception>


#include <map>
#include <list>
#include <iostream>
#include <cassert>

typedef std::pair<double, double> Wsp;
typedef std::list<VertexId> SuperLista;
typedef std::map<Wsp, SuperLista> SuperMapa;
typedef std::pair<VertexId, VertexId> edgedef;
typedef std::list<edgedef> edgesList;

struct vertexMap
{
  void addId(Wsp wsp, VertexId id)
  {
    map[wsp].push_back(id);
  }

  void print()
  {
    for(SuperMapa::iterator i = map.begin(); i != map.end(); ++i)
    {
      std::cout << "(" << i->second.front() << ", " << i->first.first << ", " << i->first.second << ")," << std::endl;
    }
  }

  VertexId getReprezentant(VertexId id)
  {
    for(SuperMapa::iterator i = map.begin(); i != map.end(); ++i)
    {
      for(SuperLista::iterator j = i->second.begin(); j != i->second.end(); ++j)
      {
        if(*j == id)
          return i->second.front();
      }
    }
    assert(false);
  }

  SuperMapa map;
};

struct tmpMap
{

  void print()
  {
    map.print();
    std::cout << "-- ==" << std::endl;
    for(edgesList::iterator i = list.begin(); i != list.end(); ++i)
      std::cout << "(" << i->first << ", " << i->second << ")," << std::endl;
  }

  void addEdge(edgedef def)
  {
    def.first = map.getReprezentant(def.first);
    def.second = map.getReprezentant(def.second);
    list.push_front(def);
  }

  edgesList list;
  vertexMap map;
};

RoadGraphReader::RoadGraphReader(const std::string& graphFilePath)
  : graphFilePath(graphFilePath)
{
}

RoadGraphPtr RoadGraphReader::readRoadGraph()
{
  RoadGraphPtr result(new RoadGraph);
  tmpMap tmpM;
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
      tmpM.map.addId(Wsp(lat,lon), id);
      result->addVertex(id, MetricCoords(GeoCoords(lat, lon)));
    }
  }

  VertexId beg, end;
  double dist;
  int lanes, speed;
  while (inputFile.good())
  {
    inputFile >> beg >> end >> dist >> lanes >> speed;
    tmpM.addEdge(edgedef(beg, end));
    result->addEdge(beg, end);
  }

  tmpM.print();

  return result;
}
