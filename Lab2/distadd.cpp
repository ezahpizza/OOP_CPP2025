#include <iostream>
#include <string>
using namespace std;

class Distance {
    private:
        int km;
        int m;
        int cm;
    
    public:
        void inputDistance(int kilometer, int meter, int centimeter) {
            km = kilometer;
            m = meter;
            cm = centimeter;
            normalize();
        }
    
        void display() {
            cout << km << " km, " << m << " m, " << cm << " cm" << endl;
        }
    
        Distance addDistance(Distance d) {
            Distance result;
            result.cm = cm + d.cm;
            result.m = m + d.m;
            result.km = km + d.km;
            result.normalize();
            return result;
        }
    
    private:
        void normalize() {
            m += cm / 100;
            cm %= 100;
            
            km += m / 1000;
            m %= 1000;
        }
};
    
int main() {

    int n;
    cout << "Enter the number of distance objects: ";
    cin >> n;
    
    Distance* distances = new Distance[n];
    
    for (int i = 0; i < n; i++) {
        int km, m, cm;
        cout << "\nEnter distance " << i + 1 << " (km m cm): ";
        cin >> km >> m >> cm;
        distances[i].inputDistance(km, m, cm);
    }
    
    cout << "\nAll distances:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Distance " << i + 1 << ": ";
        distances[i].display();
    }
    
    int idx1, idx2;
    cout << "\nEnter indices of two distances to add (0-" << n-1 << "): ";
    cin >> idx1 >> idx2;
    
    if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
        Distance result = distances[idx1].addDistance(distances[idx2]);
        cout << "Result of addition: ";
        result.display();
    } else {
        cout << "Invalid indices!" << endl;
    }
    
    delete[] distances;
    

    return 0;
}