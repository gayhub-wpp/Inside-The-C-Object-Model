#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Point3D
{
private:
    float _x;
    float _y;
    float _z;
    
public:
    Point3D(float x = 0.0, float y = 0.0, float z = 0.0): _x(x), _y(y), _z(z){}
    float x() const{return _x;}
    float y() const{return _y;}
    float z() const{return _z;}

    void x(float val){ _x  = val;}
    void y(float val){ _y  = val;}
    void z(float val){ _z  = val;}

    ~Point3D();
};

inline ostream& operator<<(ostream &os,const Point3D &pt){
    os << "(" << pt.x() << "," << pt.y() << "," << pt.z() << ")" << endl; 
    return os;
}

template <typename type, int dim>
class Point
{
private:
    type _coords[dim];
public:
    Point(type coords[dim])
    {
        for (type i = 0; i < dim; i++)
        {
            _coords[i] = coords[i];
        }
    }

    type& operator[](int index)
    {
        assert(index < dim && index >= 0);
        return _coords[index];
    }

    type operator[](int index) const
    {
        assert(index < dim && index >= 0);
        return _coords[index];
    }

};


template<typename type, int dim>
inline ostream& operator<<(ostream &os, Point<type, dim> &pt)
{
    os << "(" ;
    for (int i = 0; i < dim-1; i++)
    {
        os << pt[i] << ",";
        os << pt[dim-1];
    }
    os << ")";
    return os;
}

int main(int argc, char const *argv[])
{
    int a[10];
    Point<int, 10> pt(a);
    cout << pt[10] << endl;

    return 0;
}

