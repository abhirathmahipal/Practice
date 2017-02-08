#include <iostream>
using namespace std;

class vehicle {
    int num_wheels;
    int range;
public:
    vehicle(int w, int r)
    {
        num_wheels = w; range = r;
    }

    void showv()
    {
        cout << "Wheels: " << num_wheels << '\n';
        cout << "Range: " << range << '\n';
    }
};

class car : public vehicle {
    int passengers;
public:
    
    car(int p, int w, int r) : vehicle(w, r)
    {
        passengers = p;
    }

    void show()
    {
        showv();
        cout << "Passengers: " << passengers << '\n';
    }
};

class truck : public vehicle {
    int loadlimit;
public:

    truck(int l, int w, int r) : vehicle(w, r)
    {
        loadlimit = l;
    }

    void show()
    {
        showv();
        cout << "loadlimit: " << loadlimit << '\n';
    }
};

int main()
{
    car c(5, 4, 500);
    truck t(30000, 12, 1200);
    cout << "Car: \n";
    c.show();
    cout << "\nTruck: \n";
    t.show();

    return 0;
}
