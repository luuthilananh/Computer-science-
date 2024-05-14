#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polyline {
private:
    vector<pair<double, double>> points;

public:
    // Добавить очередную точку в ломаную
    void addPoint(double x, double y) {
        points.push_back(make_pair(x, y));
        cout << "Adding point #" << points.size() - 1 << ": (" << x << "; " << y << ")\n";
    }

    // Получить количество точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const {
        return points.size();
    }

    // Получить длину ломаной в данный момент
    double getLength() const {
        double length = 0.0;
        for (size_t i = 1; i < points.size(); ++i) {
            double dx = points[i].first - points[i - 1].first;
            double dy = points[i].second - points[i - 1].second;
            length += sqrt(dx * dx + dy * dy);
        }
        return length;
    }

    // Получить x-координату i-ой точки ломаной
    double getX(unsigned int i) const {
        return points[i].first;
    }

    // Получить y-координату i-ой точки ломаной
    double getY(unsigned int i) const {
        return points[i].second;
    }
};

int main()
{
 Polyline p;
 p.addPoint(0.0, 0.0);
 p.addPoint(1.0, 0.0);
 p.addPoint(1.0, 1.0);
 cout << "Length: " << p.getLength() << endl;
 cout << "Points:" << endl;
 for(unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
 cout << p.getX(i) << " " << p.getY(i) << endl;
 }
 return 0;
}

/*int main() {
    Polyline p;
    double x, y;
    int n;
    
    cin >> n; 

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        p.addPoint(x, y);
    }

    cout << "Polyline reports these points:\n";
    for (unsigned int i = 0; i < p.getNumberOfPoints(); ++i) {
       cout << p.getX(i) << " " << p.getY(i) << endl;
    }

    cout << "Polyline length: " << p.getLength() << endl;

    return 0;
}*/

