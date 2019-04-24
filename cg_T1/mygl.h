#ifndef _MYGL_H_
#define _MYGL_H_

#include <cmath>
#include "definitions.h"
#include "Color.h"
#include "Vertex.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel (Vertex v){

    int x = v.getx();
    int y = v.gety();
    Color *c = v.getc();

    FBptr [4*x + 4*y*IMAGE_WIDTH] = c->getR();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 1] = c->getG();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 2] = c->getB();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 3] = c->getA();

};

void putPixel (int x, int y){

    Color c (1.0, 1.0, 1.0, 1.0);

    FBptr [4*x + 4*y*IMAGE_WIDTH] = c.getR();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 1] = c.getG();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 2] = c.getB();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 3] = c.getA();

};

void putPixel (int x, int y, Color * c){

    FBptr [4*x + 4*y*IMAGE_WIDTH] = c->getR();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 1] = c->getG();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 2] = c->getB();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 3] = c->getA();

};

Color  *colorInter(int x, int y, Vertex v_inicial, Vertex v_final)
{
    Color cor_inicial = *v_inicial.getc();
    Color cor_final = *v_final.getc();
    static Color cor_atual (0.0, 0.0 , 0.0, 0.0);

    int xi = v_inicial.getx();
    int yi = v_inicial.gety();

    int xf = v_final.getx();
    int yf = v_final.gety();

    double dist_total = sqrt ((xf-xi)*(xf-xi) + (yf-yi)*(yf-yi));
    double dist_parcial = sqrt ((x-xi)*(x-xi) + (y-yi)*(y-yi));

    double p = dist_parcial/dist_total;

    double red = cor_inicial.getR()*(1-p) + cor_final.getR()*p;
    double green = cor_inicial.getG()*(1-p) + cor_final.getG()*p;
    double blue = cor_inicial.getB()*(1-p) + cor_final.getB()*p;
    double alpha = cor_inicial.getA()*(1-p) + cor_final.getA()*p;

    cor_atual.setR(red/255.0);
    cor_atual.setG(green/255.0);
    cor_atual.setB(blue/255.0);
    cor_atual.setA(alpha/255.0);

    return &cor_atual;
}



void plotLineLow(Vertex v0, Vertex v1){

  int x0 = v0.getx();
  int y0 = v0.gety();

  int x1 = v1.getx();
  int y1 = v1.gety();

  Color *c;

  int dx = x1 - x0;
  int dy = y1 - y0;
  int yi = 1;
  if (dy < 0){
    yi = -1;
    dy = -dy;
  }
  int p = 2*dy - dx;
  int y = y0;

  for (int x = x0; x <= x1; x++){
    c = colorInter(x, y, v0, v1);
    putPixel(x, y, c);
    if (p > 0){
       y = y + yi;
       p = p - 2*dx;
    }
    p = p + 2*dy;
  }

}


void plotLineHigh(Vertex v0, Vertex v1){
  int x0 = v0.getx();
  int y0 = v0.gety();

  int x1 = v1.getx();
  int y1 = v1.gety();

  Color *c;

  int dx = x1 - x0;
  int dy = y1 - y0;
  int xi = 1;
  if (dx < 0){
    xi = -1;
    dx = -dx;
  }
  int p = 2*dx - dy;
  int x = x0;

  for (int y = y0; y<=y1; y++){
        c = colorInter(x, y, v0, v1);
        putPixel(x, y, c);
        if (p > 0){
           x = x + xi;
           p = p - 2*dy;
        }
        p = p + 2*dx;
  }

}

void drawLine(Vertex v0, Vertex v1) {


  if (abs(v1.gety() - v0.gety()) < abs(v1.getx() - v0.getx())){
    if (v0.getx() > v1.getx()){
      plotLineLow(v1, v0);
    }else{
      plotLineLow(v0, v1);
    }
  }
  else  {
    if (v0.gety() > v1.gety()){
      plotLineHigh(v1, v0);
    }else{
      plotLineHigh(v0, v1);
    }
  }

}

void DrawTriangle(Vertex v1, Vertex v2, Vertex v3)
{

  drawLine(v1, v2);
  drawLine(v2, v3);
  drawLine(v3, v1);

}


#endif // _MYGL_H_

