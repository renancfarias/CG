#include "Color.h"
#include "Vertex.h"
    // o valor da intensidade das  cores deve ser de 0.0 ate 1.0
Color::Color(double red, double green, double blue, double alpha){

    r = (unsigned char)red*255;
    g = (unsigned char)green*255;
    b = (unsigned char)blue*255;
    a = (unsigned char)alpha*255;

};

unsigned char Color::getR ()
{
    return r;
}

unsigned char Color::getG()
{
    return g;
}

unsigned char Color::getB ()
{
    return b;
}

unsigned char Color::getA ()
{
    return a;
}

void Color::setR (double red)
{
   if(red > 1.0)
       return;
   else
       r = red*255;
    return;
}

void Color::setG (double green)
{
   if(green > 1.0)
       return;
   else
       g = green*255;
    return;
}

void Color::setB (double blue)
{
   if(blue > 1.0)
       return;
   else
       b = blue*255;
    return;
}

void Color::setA (double alpha)
{
   if(alpha > 1.0)
       return;
   else
       a = alpha*255;
    return;
}


Color::~Color()
{
    //dtor
}
