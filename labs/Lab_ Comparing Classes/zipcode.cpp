#include <iostream>

#include "zipcode.h"

using namespace std;


enum class CompareType {
    LessZip,
    LessCityState,
    LessStateCity,
    LessLatLonState,
    LessLonLatState
};

// Complete this method by implementing the comparison logic
bool ZipCode::compare(ZipCode &rhs, ZipCode::CompareType t) {
    switch (t) {
        case CompareType::LessZip:
            return this->getZip() < rhs.getZip();

        case CompareType::LessCityState:
            if (this->getCity() == rhs.getCity()) {
                if (this->getState() == rhs.getState()) {
                    return this->getZip() < rhs.getZip();
                }
                else {
                    return this->getState() < rhs.getState();
                }
            }
            else {
                return this->getCity() < rhs.getCity();
            }

        case CompareType::LessStateCity:
            if (this->getState() == rhs.getState()) {
                if (this->getCity() == rhs.getCity()) {
                    return this->getZip() < rhs.getZip();
                }
                else {
                    return this->getCity() < rhs.getCity();
                }
            }
            else {
                return this->getState() < rhs.getState();
            }

        case CompareType::LessLatLonState:
            if (this->getState() == rhs.getState()) {
                if (this->getLat() == rhs.getLat()) {
                    if (this->getLon() == rhs.getLon()) {
                        return this->getZip() < rhs.getZip();
                    }
                    else {
                        return this->getLon() < rhs.getLon();
                    }
                }
                else {
                    return this->getLat() < rhs.getLat();
                }
            }
            else {
                return this->getState() < rhs.getState();
            }

        case CompareType::LessLonLatState:
            if (this->getState() == rhs.getState()) {
                if (this->getLon() == rhs.getLon()) {
                    if (this->getLat() == rhs.getLat()) {
                        return this->getZip() < rhs.getZip();
                    }
                    else {
                        return this->getLat() < rhs.getLat();
                    }
                }
                else {
                    return this->getLon() < rhs.getLon();
                }
            }
            else {
                return this->getState() < rhs.getState();
            }

        default:
    return false;  
}
}

// Do not edit below this line

ZipCode::ZipCode(int zip, string city, string state, int lat, int lon) {
    this->zip = zip;
    this->city = city;
    this->state = state;
    this->lat = lat;
    this->lon = lon;
}

void ZipCode::print() {
    cout << zip << "\t" << city << "\t";
    if (city.length() < 8) cout << "\t";
    cout << state << "\t" << lat << "\t"<< lon;
}

int ZipCode::getZip() {
    return zip;
}

string ZipCode::getCity() {
    return city;
}

string ZipCode::getState() {
    return state;
}

int ZipCode::getLat() {
    return lat;
}

int ZipCode::getLon() {
    return lon;
}
