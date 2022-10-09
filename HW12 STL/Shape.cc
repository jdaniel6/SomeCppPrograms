#include "Shape.hh"

using namespace std;

ostream &print(ostream &os, Shape &s) {
    os << "solid " << s.name << "\n";
    for( BaseTriangle bt : s.list_of_base_triangles){
        os << "facet normal " << bt.n1 << "\t" << bt.n2 << "\t" << bt.n3 << "\n";
        os << "\t" << "outer loop" << "\n";
        os << "\t\t" << "vertex " << bt.x1 << "\t" << bt.y1 << "\t" << bt.z1 << "\n";
        os << "\t\t" << "vertex " << bt.x2 << "\t" << bt.y2 << "\t" << bt.z2 << "\n";
        os << "\t\t" << "vertex " << bt.x3 << "\t" << bt.y3 << "\t" << bt.z3 << "\n";
        os << "\t" << "endloop" << "\n";
    }
    os << "endfacet";
    return os;
}