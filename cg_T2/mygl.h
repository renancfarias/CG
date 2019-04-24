#ifndef _MYGL_H_
#define _MYGL_H_
#include <cmath>
#include <glm/glm.hpp>
#include "definitions.h"
#include "Color.h"
#include "Vertex.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************


/*
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

*/

void putPixel (int x, int y, Color * c){

    FBptr [4*x + 4*y*IMAGE_WIDTH] = c->getR();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 1] = c->getG();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 2] = c->getB();
    FBptr [4*x + 4*y*IMAGE_WIDTH + 3] = c->getA();

};

/*
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
*/



void plotLineLow(glm::vec4 v0, glm::vec4 v1, Color *c){

  int x0 = v0[0];
  int y0 = v0[1];

  int x1 = v1[0];
  int y1 = v1[1];

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
    putPixel(x, y, c);
    if (p > 0){
       y = y + yi;
       p = p - 2*dx;
    }
    p = p + 2*dy;
  }

}


void plotLineHigh(glm::vec4 v0, glm::vec4 v1, Color * c){
  int x0 = v0[0];
  int y0 = v0[1];

  int x1 = v1[0];
  int y1 = v1[1];

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
        putPixel(x, y, c);
        if (p > 0){
           x = x + xi;
           p = p - 2*dy;
        }
        p = p + 2*dx;
  }

}

void drawLine(glm::vec4 v0, glm::vec4 v1, Color * c) {


  if (abs(v1[1] - v0[1]) < abs(v1[0] - v0[0])){
    if (v0[0] > v1[0]){
      plotLineLow(v1, v0, c);
    }else{
      plotLineLow(v0, v1, c);
    }
  }
  else  {
    if (v0[1] > v1[1]){
      plotLineHigh(v1, v0, c);
    }else{
      plotLineHigh(v0, v1, c);
    }
  }

}

/*
void DrawTriangle(glm::vec4 v1, glm::vec4 v2, glm::vec4 v3)
{

  drawLine(v1, v2);
  drawLine(v2, v3);
  drawLine(v3, v1);

}
*/


#endif // _MYGL_H_

