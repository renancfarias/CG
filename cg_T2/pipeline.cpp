#include<iostream>
#include<glm/glm.hpp>
//#include "mygl.h"


using namespace glm;

vec4 pipeline(vec4 vert){


    vec4 vertice = vert;
    /***************************************************/
    /***** Matriz model: Esp. Obj. --> Esp. Univ.  *****/
    /***************************************************/
    mat4 Model = mat4(1,0,0,0,
                      0,1,0,0,
                      0,0,1,0,
                      0,0,0,1); //Matriz model (iniciada com 1.0 na diagonal principal)


    /*************************************/
    /***** parametros da camera **********/
    /*************************************/
    vec3 camera_pos = vec3(0,0,4); // posicao da camera no universo
    vec3 camera_lookat = vec3(0,0,0); // ponto pra onde a camera esta olhando
    vec3 camera_up = vec3(0,1,0);

    /****************************************/
    /***** sistema ortonormal da camera *****/
    /****************************************/
    vec3 camera_dir = camera_lookat - camera_pos;

    vec3 z_camera = -(normalize(camera_dir));
    vec3 x_camera = normalize(cross(camera_up, z_camera));
    vec3 y_camera = cross(z_camera, x_camera);

    /***************************************************************/
    /***** Construcao da matriz view: Esp. Univ. --> Esp. Cam. *****/
    /***************************************************************/
    mat4 Bt = mat4(x_camera[0], y_camera[0], z_camera[0], 0, // coluna 1
                   x_camera[1], y_camera[1], z_camera[1], 0, // coluna 2
                   x_camera[2], y_camera[2], z_camera[2], 0, // coluna 3
                   0,0,0,1);                                 // coluna 4

    mat4 T1 = mat4(1,0,0,0,
                  0,1,0,0,
                  0,0,1,0,
                  -camera_pos[0], -camera_pos[1], -camera_pos[2], 1);

    mat4 View = Bt * T1;

    /**********************************************************************/
    /***** Construcao da matriz de ModelView: Esp. Obj. --> Esp. Cam. *****/
    /**********************************************************************/
    mat4 ModelView = View * Model;

    /************************************************************************/
    /***** Construcao da matriz de Projecao: Esp. Cam. --> Esp. Recorte *****/
    /************************************************************************/
    int d = 2;// distancia do centro de projecao para o viewplane

    mat4 Projection = mat4(1, 0, 0, 0,          //coluna 1
                           0, 1, 0, 0,          //coluna 2
                           0, 0, 1, -(1.0/d),   //coluna 3
                           0, 0, d, 0);         //coluna 4

    /********************************************************************************/
    /***** Construcao da matriz ModelViewProjection: Esp. Obj. --> Esp. Recorte *****/
    /********************************************************************************/

    mat4 ModelViewProj = Projection * ModelView;


    /*******************************************************************************
     Aplicao da matriz ModelViewProjection: Esp. Obj. --> Esp. Recorte
    *******************************************************************************/

    vertice = ModelViewProj * vertice;

    /*******************************************************************************
    # Homogeneizacao (divisao por W).
    # Este passo leva os vertices normalmente para o espaco canonico.
    # Neste caso, como a matriz de projecao eh muito simples, o resultado
    # da homogeneizacao sao os vertices em um espaço que nao eh exatamente o
    # canonico. Porem, apesar de nao ser o espaco canonico, a distorcao perspectiva
    # estara presente.
    *******************************************************************************/

    vertice[0] = vertice[0]/vertice[3];
    vertice[1] = vertice[1]/vertice[3];
    vertice[2] = vertice[2]/vertice[3];
    vertice[3] = vertice[3]/vertice[3];

    /*******************************************************************************
    # Conversao de coordenadas do espaco canonico para o espaco de tela.
    *******************************************************************************/

    mat4 S1 = mat4(1, 0, 0, 0,
                   0, -1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1);

    mat4 T = mat4 (1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   1, 1, 0, 1);

    float w = 512;
    float h = 512;

    mat4 S2 = mat4(w/2, 0, 0, 0,
                   0, h/2, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1);


    mat4 Viewport = S2 * T * S1;

    vertice = Viewport * vertice;


return vertice;
}
