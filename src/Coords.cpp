#include "Coords.h"

IntCoords::IntCoords(int x, int y)
  : x(x), y(y)
{}

IntCoords::IntCoords(const MetricCoords& metricCoords, int unitsPerMeter)
  : x(metricCoords.x * unitsPerMeter), y(metricCoords.y * unitsPerMeter)
{}

IntCoords::IntCoords(const GeoCoords& geoCoords, int unitsPerMeter)
  : IntCoords(MetricCoords(geoCoords), unitsPerMeter)
{}

GeoCoords::GeoCoords()
  : lat(0), lon(0)
{}

GeoCoords::GeoCoords(double lat, double lon)
  : lat(lat), lon(lon)
{}

MetricCoords::MetricCoords(const GeoCoords& coords)
{

}

MetricCoords::MetricCoords(double x, double y)
  : x(x), y(y)
{}
