#ifndef COLOR_H
#define COLOR_H

#include "Vertex.h"


class Color
{

    public:
        Color(double red, double green, double blue, double alpha);
        virtual ~Color();

        unsigned char getR ();
        unsigned char getG ();
        unsigned char getB ();
        unsigned char getA ();

        void setR (double r);
        void setG (double g);
        void setB (double b);
        void setA (double a);



    private:
        unsigned char r = 0;
        unsigned char g = 0;
        unsigned char b = 0;
        unsigned char a = 0;
};

#endif // COLOR_H
