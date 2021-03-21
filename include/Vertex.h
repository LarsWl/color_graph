#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
    int number;
    int color;
    int degree;

public:
    Vertex(int c_number, int c_color, int c_degree) : number(c_number), color(c_color), degree(c_degree) {};

    int get_color() const;
    void set_color(int color);

    int get_number() const;

    int get_degree() const;
    void set_degree(int degree);
    void increment_degree();

    bool operator<(Vertex vertex);
};
