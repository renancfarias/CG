#include "Vertex.h"
#include "Color.h"

Color branco (1.0, 1.0, 1.0, 1.0);

Vertex::Vertex(int x1, int y1)
{
    x = x1;
    y = y1;
    c = &branco;
}

Vertex::Vertex(int x1, int y1, Color *c1)
{
    x = x1;
    y = y1;
    c = c1;
}

Vertex::~Vertex()
{
    //dtor
}

int Vertex::getx()
{
    return x;
}

int Vertex::gety()
{
    return y;
}

Color* Vertex::getc()
{
    return c;
}
