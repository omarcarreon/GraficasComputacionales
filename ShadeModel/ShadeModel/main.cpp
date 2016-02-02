//
//  main.cpp
//  Actividad1
//
//  Created by Omar Carreon on 19/01/16.
//  A01036074
//  Copyright © 2016 OmarCarreon. All rights reserved.
//
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
    
    glClearColor(1.0,1.0,1.0,1.0);//COLOR de fondo
    
    glColor3ub(139, 131, 120);//color del dibujo
    
    
    glShadeModel(GL_FLAT);
    
    
    glMatrixMode(GL_PROJECTION);//sistema de coordenadas de la proyeccion
    // se comenta glorto
    //gluOrtho2D(-500,500, -500,500);
    
}
// funcion para dibujar las figuras.
// En lugar de ponerse en display() se ponen en dibuja()
void dibuja(){
    
    glLineWidth(1);
    
    //CAMBIA EL TAMAÑO DEL POINTs
    
    glPointSize(10); //No debe ir dentro del glBegin
    
    glBegin(GL_POINTS);
    
    glColor3ub(255, 0, 0);
    glVertex2f(-450, 400);
    
    glColor3ub(0, 255, 0);
    glVertex2f(-420,370);
    
    glColor3ub(0, 0, 255);
    glVertex2f(-380, 370);
    
    glColor3ub(195, 205, 0);
    glVertex2f(-350, 400);
    
    glColor3ub(195, 205, 0);
    glVertex2f(-350, 400);
    
    glColor3ub(15, 5, 0);
    
    glVertex2f(-330, 440);
    
    glEnd();
    
    
    glLineWidth(3);
    glBegin(GL_LINES);
    
    
    glColor3ub(255, 0, 0);
    glVertex2f(-180, 450);
    glColor3ub(0, 255, 0);
    glVertex2f(-280,350);
    
    glColor3ub(255, 0, 0);
    glVertex2f(-190, 400);
    glColor3ub(0, 255, 0);
    glVertex2f(-50,390);
    
    glColor3ub(255, 0, 0);
    glVertex2f(-220, 370);
    glColor3ub(0, 255, 0);
    glVertex2f(-70,340);
    
    glColor3ub(255, 0, 0);
    glVertex2f(-70, 370);
    glColor3ub(0, 255, 0);
    glVertex2f(-220,340);
    
    glEnd();
    
    
    glBegin(GL_LINE_STRIP);
    
    glColor3ub(111, 205, 0);
    glVertex2f(-20,380);
    glColor3ub(205,92,92);
    glVertex2f(-10,420);
    glColor3ub(205,92,92);
    glVertex2f(68,440);
    glColor3ub(255, 0, 0);
    glVertex2f(100, 400);
    glColor3ub(123,104, 238);
    glVertex2f(-20,450);
    
    glEnd();
    
    
    glBegin(GL_LINE_LOOP);
    glColor3ub(123,104, 238);
    glVertex2f(180,388);
    glColor3ub(70, 130, 180);
    glVertex2f(220,320);
    glColor3ub(123,104, 238);
    glVertex2f(330,320);
    glColor3ub(255, 69, 0);
    glVertex2f(300,390);
    glColor3ub(123,104, 238);
    glVertex2f(280,340);
    glColor3ub(70, 130, 180);
    glVertex2f(230,420);
    
    glEnd();
    
    glBegin(GL_TRIANGLES);
    
    glColor3ub(91, 55, 0);
    glVertex2f(-450,220);
    glColor3ub(255, 182, 193);
    glVertex2f(-450,280);
    glColor3ub(91, 55, 0);
    glVertex2f(-340,220);
    
    glColor3ub(31, 55, 0);
    glVertex2f(-300,240);
    glColor3ub(255, 182, 193);
    glVertex2f(-400,300);
    glColor3ub(11, 55, 0);
    glVertex2f(-200,300);
    
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);
    
    glColor3ub(255, 255, 100);
    glVertex2f(-100,240);
    glColor3ub(41, 255, 40);
    glVertex2f(-100,150);
    glColor3ub(71, 255, 250);
    glVertex2f(-10,240);
    glColor3ub(255, 0, 0);
    glVertex2f(20,150);
    glColor3ub(255, 0, 255);
    glVertex2f(70,240);
    glColor3ub(100, 100, 105);
    glVertex2f(90,90);
    
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    
    glColor3ub(255, 255, 100);
    glVertex2f(140,140);
    glColor3ub(41, 255, 40);
    glVertex2f(140,290);
    glColor3ub(71, 255, 250);
    glVertex2f(190,250);
    glColor3ub(71, 5, 250);
    glVertex2f(220,180);
    glColor3ub(9, 59, 9);
    glVertex2f(215,90);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
    glColor3ub(255, 255, 100);
    glVertex2f(-400,0);
    glColor3ub(41, 255, 40);
    glVertex2f(-360,60);
    glColor3ub(71, 255, 250);
    glVertex2f(-250,90);
    glColor3ub(71, 5, 100);
    glVertex2f(-220,-10);
    
    glColor3ub(255, 255, 100);
    glVertex2f(-200,-20);
    glColor3ub(41, 255, 40);
    glVertex2f(-190,80);
    glColor3ub(71, 255, 250);
    glVertex2f(-110,100);
    glColor3ub(71, 5, 100);
    glVertex2f(-160,-21);
    
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    
    glColor3ub(255, 69, 0);
    glVertex2f(-410,-200);
    
    glColor3ub(32, 178, 170);
    glVertex2f(-450,-100);
    
    glColor3ub(71, 5, 100);
    glVertex2f(-302,-210);
    
    glColor3ub(255, 182, 193);
    glVertex2f(-300,-100);
    
    glColor3ub(71, 255, 250);
    glVertex2f(-200,-190);
    
    glColor3ub(1, 55, 250);
    glVertex2f(-240,-90);
    
    glColor3ub(71, 255, 250);
    glVertex2f(-140,-189);
    
    glColor3ub(255, 20, 147);
    glVertex2f(-150,-65);
    
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glColor3ub(255, 255, 100);
    glVertex2f(-15,-10);
    
    glColor3ub(255, 160, 120);
    glVertex2f(100,10);
    
    glColor3ub(71, 5, 100);
    glVertex2f(65,-45);
    
    glColor3ub(0, 0, 128);
    glVertex2f(-25,-85);
    
    glColor3ub(0, 0, 128);
    glVertex2f(-40,-45);
    
    glEnd();
}

void dibujaTriangulo(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(7);
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.5,0.5);
    glVertex2f(0.5,0.5);
    glVertex2f(0.5,-0.5);
    glEnd();
    glColor3f(1, 0, 0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    glVertex2f(-0.5,-0.5);
    glColor3f(1, 1, 0);
    glVertex2f(-0.5,0.5);
    glColor3f(1, 0, 1);
    glVertex2f(0.5,0.5);
    glVertex2f(0.5,-0.5);
    glEnd();
    glColor3f(0, 0, 0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.5,0.5);
    glVertex2f(0.5,0.5);
    glVertex2f(0.5,-0.5);
    glEnd();
    
}

void Display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    dibujaTriangulo();
    /*
     // 1er cuadrante
     glViewport(300, 300, 300, 300);
     dibuja();
     // 2do cuadrante
     glViewport(0, 300, 200, 200);
     dibuja();
     // 3er cuadrante
     glViewport(0, 0, 50, 50);
     dibuja();
     //4to cuadrante
     // las coordenadas se refieren a la ventana
     glViewport(300, 0, 100, 100);
     dibuja();
     */
    glFlush();
    
}




int main(int argc, char** argv)

{
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(winWidth,winHeight);
    
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Primitivas");
    
    glutDisplayFunc(Display);
    
    init();
    
    glutMainLoop();
    
    return 0;
    
}