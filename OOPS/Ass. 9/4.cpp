#include <iostream>
using namespace std;

class DistanceM;     
class DistanceMiles;  

class DistanceKM {
private:
    double km;

public:
    DistanceKM(double k = 0) : km(k) {}

    operator DistanceM() const;

    double getKM() const { return km; }
};


class DistanceM {
private:
    double meters;

public:
    DistanceM(double m = 0) : meters(m) {}

    operator DistanceKM() const {
        return DistanceKM(meters / 1000.0);
    }

    operator DistanceMiles() const;

    double getM() const { return meters; }
};


class DistanceMiles {
private:
    double miles;

public:
    DistanceMiles(double mi = 0) : miles(mi) {}

    operator DistanceM() const {
        return DistanceM(miles * 1609.34);
    }

    double getMiles() const { return miles; }
};



DistanceKM::operator DistanceM() const {
    return DistanceM(km * 1000.0);
}

DistanceM::operator DistanceMiles() const {
    return DistanceMiles(meters / 1609.34);
}


int main() {

    DistanceKM dk(10);

    DistanceM dm = dk;           
    DistanceMiles dmi = dm;      

    DistanceM dm2 = dmi;         
    DistanceKM dk2 = dm2;        

    cout << "Original KM: " << dk.getKM() << " km\n";
    cout << "In meters: " << dm.getM() << " m\n";
    cout << "In miles: " << dmi.getMiles() << " miles\n";
    cout << "Back to meters: " << dm2.getM() << " m\n";
    cout << "Back to km: " << dk2.getKM() << " km\n";

    return 0;
}
