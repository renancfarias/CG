#include "main.h"


//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

    Color branco (1.0, 1.0, 1.0, 1.0);
    Color vermelho (1.0, 0.0, 0.0 , 1.0);
    Color verde (0.0, 1.0, 0.0 , 1.0);
    Color azul (0.0, 0.0, 1.0 , 1.0);
    Color amarelo (1.0, 1.0, 0.0, 1.0);
    Color ciano (0.0, 1.0, 1.0, 1.0);
    Color magenta (1.0, 0.0, 1.0, 1.0);

    Vertex p (255, 255, &branco);
    Vertex q (127, 255, &branco);
    Vertex r (255, 127, &branco);

    //Vertex ul (0,0, &vermelho); //upper-left corner
    //Vertex ur (IMAGE_WIDTH-1, 0, &azul);
    //Vertex lf (0, IMAGE_HEIGHT-1, &amarelo);
    //Vertex lr (IMAGE_WIDTH-1, IMAGE_HEIGHT-1, &verde); //lower-right coner

    //Vertex mu (IMAGE_WIDTH/2 -1,0, &amarelo);
    //Vertex mlu (IMAGE_WIDTH*0.25 -1,0, &amarelo);
    //Vertex mru (IMAGE_WIDTH*0.75 -1,0, &amarelo);

   // Vertex md (IMAGE_WIDTH/2-1, IMAGE_HEIGHT-1, &azul);
    //Vertex mld (IMAGE_WIDTH*0.25 -1, IMAGE_HEIGHT-1, &azul);
    //Vertex mrd (IMAGE_WIDTH*0.75 -1, IMAGE_HEIGHT-1, &azul);

   // Vertex mr (IMAGE_WIDTH-1, IMAGE_HEIGHT/2-1, &verde);
   // Vertex mlr (IMAGE_WIDTH-1, IMAGE_HEIGHT*0.25-1, &verde);
   // Vertex mrr (IMAGE_WIDTH-1, IMAGE_HEIGHT*0.75-1, &verde);

   // Vertex ml (0, IMAGE_HEIGHT/2-1, &ciano);
   // Vertex mll (0, IMAGE_HEIGHT*0.75, &ciano);
   // Vertex mrl (0, IMAGE_HEIGHT*0.25, &ciano);


    //putPixel(255, 255, branco);
    //plotLineLow(0, 0, 300, 200, branco);
    //plotLineHigh(300, 400 , 10, 10, branco);

    putPixel(p);
    putPixel(q);
    putPixel(r);

   // drawLine(ul, lr);
   // drawLine(lf, ur);
   // drawLine(mu, md);
   // drawLine(ml, mr);

   // drawLine(mlu, mrd);
   // drawLine(mru, mld);
   // drawLine(mlr, mll);
   // drawLine(mrr, mrl);

   // Vertex v1 (80, 255, &azul);
   // Vertex v2 (384, 127, &vermelho);
   // Vertex v3 (255, 384, &verde);

   // Vertex v4 (127, 127, &verde);
   // Vertex v5 (420, 200, &azul);
   // Vertex v6 (300, 430, &vermelho);



  //  DrawTriangle(v1, v2, v3);

  //  DrawTriangle(v4, v5, v6);






}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();


	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;


	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

