#include <iostream>
using namespace std;

class DistanceM;      // forward declaration
class DistanceMiles;  // forward declaration

// ---------------------- DistanceKM ----------------------
class DistanceKM {
private:
    double km;

public:
    DistanceKM(double k = 0) : km(k) {}

    // KM → M
    operator DistanceM() const;

    double getKM() const { return km; }
};


// ---------------------- DistanceM ----------------------
class DistanceM {
private:
    double meters;

public:
    DistanceM(double m = 0) : meters(m) {}

    // M → KM
    operator DistanceKM() const {
        return DistanceKM(meters / 1000.0);
    }

    // M → Miles
    operator DistanceMiles() const;

    double getM() const { return meters; }
};


// ---------------------- DistanceMiles ----------------------
class DistanceMiles {
private:
    double miles;

public:
    DistanceMiles(double mi = 0) : miles(mi) {}

    // Miles → M
    operator DistanceM() const {
        return DistanceM(miles * 1609.34);
    }

    double getMiles() const { return miles; }
};


// ========== Now define the missing operators ==========

// KM → M
DistanceKM::operator DistanceM() const {
    return DistanceM(km * 1000.0);
}

// M → Miles
DistanceM::operator DistanceMiles() const {
    return DistanceMiles(meters / 1609.34);
}


// ========================= MAIN =========================

int main() {

    // (i) Create DistanceKM with 10 km
    DistanceKM dk(10);

    // (ii) Convert to M, then to Miles
    DistanceM dm = dk;           // KM → M
    DistanceMiles dmi = dm;      // M → Miles

    // (iii) Miles → M → KM
    DistanceM dm2 = dmi;         // Miles → M
    DistanceKM dk2 = dm2;        // M → KM

    cout << "Original KM: " << dk.getKM() << " km\n";
    cout << "In meters: " << dm.getM() << " m\n";
    cout << "In miles: " << dmi.getMiles() << " miles\n";
    cout << "Back to meters: " << dm2.getM() << " m\n";
    cout << "Back to km: " << dk2.getKM() << " km\n";

    return 0;
}
