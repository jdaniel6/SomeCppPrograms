#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class BaseTriangle{
    public:
        double n1, n2, n3;  //normal
        double x1, y1, z1;  //first vertex
        double x2, y2, z2;  //second vertex
        double x3, y3, z3;  //third vertex
    public:
        BaseTriangle(){
            x1 = x2 = x3 = y1 = y2 = y3 = z1 = z2 = z3 = 0;
        }
        BaseTriangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) : x1(x1), y1(x1), z1(z1), x2(x2), y2(x2), z2(z2), x3(x3), y3(x3), z3(z3) {
            double s1x = x1 - x2;
            double s1y = y1 - y2;
            double s1z = z1 - z2;

            double s2x = x3 - x2;
            double s2y = y3 - y2;
            double s2z = z3 - z2;

            this->n1 = s1y * s2z - s1z * s2y;
            this->n2 = s1z * s2x - s1x * s2z;
            this->n3 = s1x * s2y - s1y * s2x;
        }
        
};

class shape {
private:
    double x, y, z;                 //  position
    vector<BaseTriangle> list_of_base_triangles;
public:
    shape() : x(0), y(0), z(0) {}
    virtual void print(ostream& os) const = 0;
    void add_rectangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3){

    }
    friend class cube;
    friend class cylinder;
};

class cylinder : public shape {
private:
    double r, h;
public:
    cylinder(double rad, double height) : r(rad), h(height){}
    void print(ostream& os) const override{

    }
    friend ostream& operator << (ostream& os, const cylinder cyl){
        return os << "radius= " << cyl.r << "\t\theight= " << cyl.h << endl;
    }
};
class cube : public shape {
    private:
        double length, breadth, height;
        string name;
    public:
        cube(){
            length = breadth = height = 0;
        }
        cube(double length, double height, double breadth) : length(length), breadth(breadth), height(height), name("cuboid"){
            list_of_base_triangles.push_back(BaseTriangle(x, y+height, z+breadth, x+length, y, z+breadth, x+length, y+height, z+breadth));
            list_of_base_triangles.push_back(BaseTriangle(x+length, y, z+breadth, x, y+height, z+breadth, x, y, z+breadth));
            list_of_base_triangles.push_back(BaseTriangle(x, y, z, x+length, y+height, z, x+length, y, z));
            list_of_base_triangles.push_back(BaseTriangle(x+length, y+height, z, x, y, z, x, y+height, z));
            list_of_base_triangles.push_back(BaseTriangle(x, y, z, x+length, y, z+breadth, x, y, z+breadth));
            list_of_base_triangles.push_back(BaseTriangle(x+length, y, z+breadth, x, y, z, x+length, y, z));
            list_of_base_triangles.push_back(BaseTriangle(x+length, y, z+breadth, x+length, y+height, z, x+length, y+height, z+breadth));
            list_of_base_triangles.push_back(BaseTriangle(x+length, y+height, z, x+length, y, z+breadth, x+length, y, z));
            list_of_base_triangles.push_back(BaseTriangle(x+length, y+height, z, x, y+height, z+breadth,  x+length, y+height, z+breadth));
            list_of_base_triangles.push_back(BaseTriangle(x, y+height, z+breadth, x+length, y+height, z, x, y+height, z));
            list_of_base_triangles.push_back(BaseTriangle(x, y, z, x, y+height, z+breadth, x, y+height, z));
            list_of_base_triangles.push_back(BaseTriangle(x, y+height, z+breadth, x, y, z, x, y, z+breadth));
        }
        void print(ostream& os) const override{
            os << "solid " << name << "\n";
            for(BaseTriangle bt : list_of_base_triangles){
                os << "facet normal " << bt.n1 << "\t" << bt.n2 << "\t" << bt.n3 << "\n";
                os << "\t" << "outer loop" << "\n";
                os << "\t\t" << "vertex " << bt.x1 << "\t" << bt.y1 << "\t" << bt.z1 << "\n";
                os << "\t\t" << "vertex " << bt.x2 << "\t" << bt.y2 << "\t" << bt.z2 << "\n";
                os << "\t\t" << "vertex " << bt.x3 << "\t" << bt.y3 << "\t" << bt.z3 << "\n";
                os << "\t" << "endloop" << "\n";
                os << "endfacet" << "\n";
            }
            os << "endsolid " << name << "\n";
        }
        friend ostream &operator <<(ostream &os , const cube &c){
            return os << "<" << c.length << "," << c.breadth << "," << c.height << ">";
        }
};

class model {
private:
  vector<shape*> shapes;
  ofstream file;
public:
  model(const char filename[]) : file(filename, std::ios_base::app) {
//    file.open(filename);
    
  }
    // clean up when we're done
  ~model() {
    for (auto s : shapes)
      delete s;

  }
  void add(shape* s) {
    shapes.push_back(s);
  }
  void print() {
    for (auto s : shapes)
      s->print(file);
  }

};

int main() {
  cube c1(1,2,3);
  cout << c1;
  //cylinder c2(10, 30);
  //cout << c2;

  model m("test1.stl");
  // Don't do this: m.add(&c1);
  m.add(new cube(4,5,6));
  m.print();
  //m.add(new cylinder(10, 20));
}