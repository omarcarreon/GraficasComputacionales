//
//  main.cpp
//  Prueba
//
//  Created by Maria  Roque on 15/08/13.
//  Copyright (c) 2013 Tecnológico de Monterrey. All rights reserved.
//

//#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
// TamaÒo inicial de la ventana
GLsizei winWidth =600, winHeight =600;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0); // Color de fondo
    glColor3ub(139, 131, 120);  // Color del dibujo
    glMatrixMode(GL_PROJECTION);    // Definir el sistema de coordenadas de la proyeccion
    gluOrtho2D(-500,500, -500,500);
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    GLfloat angulo;
    int i;
    glLineWidth(1);
    glBegin(GL_LINES);
    for (i=0; i<360; i+=1)
    {
        angulo = (GLfloat)i*3.14159f/180.0f; // grados a radianes
        glColor3ub(i%255,0 , 0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(cos(angulo)*300, sin(angulo)*300, 0.0f);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-50, -50);
    glColor3ub(0, 255, 0);
    glVertex2f(50,-50);
    glColor3ub(0, 0, 255);
    glVertex2f(50, 50);
    glColor3ub(255, 255, 0);
    glVertex2f(-150, 50);
    glColor3ub(255, 255, 255);
    glVertex2f(-50, 50);
    glEnd();
    
    //CAMBIA EL TAMAÑO DEL POINTs
    glPointSize(5); //No debe ir dentro del glBegin
    
    glBegin(GL_POINTS);
    glColor3ub(255, 0, 0);
    glVertex2f(-50, -50);
    glColor3ub(0, 255, 0);
    glVertex2f(50,-50);
    glColor3ub(0, 0, 255);
    glVertex2f(50, 50);
    glColor3ub(255, 255, 0);
    glVertex2f(-50, 50);
    glEnd();
    
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(450, 450);
    glColor3ub(0, 255, 0);
    glVertex2f(475,200);
    glColor3ub(0, 0, 255);
    glVertex2f(400, 230);
    glColor3ub(255, 255, 0);
    glVertex2f(375, 475);
    glEnd();
    
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(-450, 450);
    glColor3ub(0, 255, 0);
    glVertex2f(-475,200);
    glColor3ub(0, 0, 255);
    glVertex2f(-400, 230);
    glColor3ub(255, 255, 0);
    glVertex2f(375, 475);
    glEnd();
    
    glLineWidth(5);
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(-450, -450);
    glColor3ub(0, 255, 0);
    glVertex2f(-475,-200);
    glColor3ub(0, 0, 255);
    glVertex2f(-400, -230);
    glColor3ub(255, 255, 0);
    glVertex2f(-375, -475);
    glColor3ub(255, 255, 0);
    glVertex2f(-300, -400);
    glColor3ub(255, 255, 0);
    glVertex2f(-330, -450);
    glEnd();
    
    glLineWidth(15);
    glBegin(GL_POINTS);
    glColor3ub(255, 0, 0);
    glVertex2f(110, 0);
    glColor3ub(0, 255, 0);
    glVertex2f(120,10);
    glColor3ub(0, 0, 255);
    glVertex2f(130, 20);
    glColor3ub(255, 255, 0);
    glVertex2f(135, 35);
    glEnd();
    
    glLineWidth(35);
    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 0, 0);
    glVertex2f(340, 950);
    glColor3ub(0, 255, 0);
    glVertex2f(445,800);

    
    glEnd();
    
    
    glFlush(); // si se quita, no pinta nada
}

//  El display se llama hasta que inicia el glutMainLoop
//  glutDisplayFunc puede ir antes del init, pero no después del glutMainLoop
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Primitivas");
    init();
    glutDisplayFunc(Display); // si no está la funcion display, marca error
    glutMainLoop();
    return 0;
}

