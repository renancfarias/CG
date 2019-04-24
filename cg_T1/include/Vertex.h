#ifndef VERTEX_H
#define VERTEX_H

class Color;


class Vertex
{
    public:
        Vertex(int x, int y);
        Vertex(int x, int y, Color *c);
        virtual ~Vertex();
        int getx();
        int gety();
        Color* getc();

    protected:

    private:
        int x;
        int y;
        Color * c;

};

#endif // VERTEX_H
