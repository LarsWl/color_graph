#include "Vertex.h"

int Vertex::get_color() const 
{
    return color;
}

void Vertex::set_color(int color) 
{
    this->color = color;
}


int Vertex::get_number() const
{
    return number;
}

int Vertex::get_degree() const
{
    return degree;
}

void Vertex::set_degree(int degree)
{
    this->degree = degree;
}

void Vertex::increment_degree()
{
    degree++;
}

bool Vertex::operator<(Vertex & vertex)
{
    return degree >= vertex.degree;
}

bool Vertex::operator>(Vertex & vertex)
{
    return degree > vertex.degree;
}

bool Vertex::operator==(Vertex & vertex)
{
    return number == vertex.number;
}
