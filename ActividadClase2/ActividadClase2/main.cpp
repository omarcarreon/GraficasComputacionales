//
//  main.cpp
//  ActividadClase2
//
//  Created by Omar Carreon on 20/01/16.
//  Copyright © 2016 OmarCarreon. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

using namespace std;

void init(void)
{
    glClearColor(0.6,1.0,0.6,1.0);
    
    // Sólo visualice las caras frontales solo visualiza sentido antihorario
    // glEnable(GL_CULL_FACE);
    
    //Indicamos que la cara frontal sera la de sentido horario reloj
    //glFrontFace(GL_CW ); //GL_CCW  cara frontal es en contra reloj
    glFrontFace(GL_CCW );
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-3,3, -3,3, 0,10);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    //glViewport(0, 0, 250, 250);
    glBegin(GL_TRIANGLES);
    //CW
    glVertex3f(0.0f, 0.0f, 0.0f); // V0
    glVertex3f(1.0f, 1.0f, 0.0f); // V1
    glVertex3f(2.0f, 0.0f, 0.0f); // V2
    //CCW
    glVertex3f(-1.0f, 0.0f, 0.0f); // V3
    glVertex3f(-3.0f, 2.0f, 0.0f); // V4
    glVertex3f(-2.0f, 0.0f, 0.0f); // V5
    glEnd();
    
    glColor3ub(255, 0, 0);
    glutWireTeapot(1);
    
    glColor3ub(128, 0, 0);
    glutWireTorus(0.5, 1, 10, 40);
    
    glColor3ub(0, 139, 139);
    glutWireSphere(1, 30, 30);
    
    glFlush();
}


int main(int argc, char *argv[])
{
    
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE |GLUT_DEPTH);
    glutCreateWindow("Frente y Tras");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
    return EXIT_SUCCESS;
}
