#ifndef POSITION_H
#define POSITION_H

#include <QString>

/**
 * @brief The Position class
 *
 * This class is used to define the drivers position (on a map).
 *
 * Public methods:
 *  QString getPositionAsString() const;
 *  int getLongitude() const;
 *  int getLatitude() const;
 */

class Position {
public:
    Position(): longitude(0), latitude(0) {}
    Position(const int longitude, const int latitude): longitude(longitude), latitude(latitude) {}
    ~Position() {}
    QString getPositionAsString() const;
    int getLongitude() const;
    int getLatitude() const;
private:
    int longitude;
    int latitude;
};

#endif // POSITION_H

