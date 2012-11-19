#ifndef COORDS_H
#define COORDS_H

struct IntCoords
{
  IntCoords(int x, int y);
  IntCoords(const MetricCoords& metricCoords, int unitsPerMeter);
  IntCoords(const GeoCoords& geoCoords, int unitsPerMeter);

  int x;
  int y;
};

struct GeoCoords
{
  GeoCoords();
  GeoCoords(double lat, double lon);

  double lat;
  double lon;
};

struct MetricCoords
{
  MetricCoords(const GeoCoords& coords);
  MetricCoords(double x, double y);

  double x;
  double y;
};


#endif // COORDS_H
