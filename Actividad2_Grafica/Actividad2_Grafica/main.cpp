//
//  main.cpp
//  Actividad2_Grafica
//
//  Created by Omar Carreon on 23/01/16.
//  A01036074
//  Copyright © 2016 OmarCarreon. All rights reserved.
//
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double PI=3.14159265358979;
GLsizei winWidth =600, winHeight =600;

void init(void)
{
    glClearColor(1.0,0.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//limpiar la matriz de proyeccción
    gluOrtho2D(-6.5,6.5, -10,10);
}
void displayName(void){
    //*******Para desplegar nombre ********//
    //*************************************//
    GLint x;
    char msg[200]="", msgMat[200]="";
    sprintf(msg, "%s","Omar Antonio Carreon Medrano");
    sprintf(msgMat, "%s","A01036074");
    
    glBegin(GL_QUADS);
    glColor3ub(228,177,123);
    glVertex2f(-2.0, 0.50);
    glColor3ub(228,177,123);
    glVertex2f(2.0, 0.50);
    glColor3ub(228,177,123);
    glVertex2f(2.0, -0.50);
    glColor3ub(228,177,123);
    glVertex2f(-2.0, -0.50);
    glEnd();
    
    // *************Dibuja nombre*****************//
    // *******************************************//
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-1.95,0.1);
    for (x=0; msg[x] != '\0'; x++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msg[x]);
    }
    
    // *************Dibuja matricula*****************//
    // *******************************************//
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.7,-0.3);
    for (x=0; msgMat[x] != '\0'; x++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msgMat[x]);
    }
    
}
void functionGraph(void)
{
    GLfloat k;
    
    //*************** Dibuja los puntos****************//
    //************************************************//
    // se declara esta variable para que los asteriscos no desaparezcan al cambiar tamaño de pantalla
    glPointSize(5);
    glBegin(GL_POINTS);
    for (k=-6.5; k<=6.5;)
    {
        glColor3ub(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
        glVertex2f(k, (exp(fabs(-k)) *cos(2*PI*k)));
        k+=0.005;
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    
    
    //*************Dibujar eje de coordenas x-y**********//
    //**************************************************//
    glLineWidth(2);
    glColor3ub(159,123,86);
    glBegin(GL_LINES);
    //eje x
    glVertex2i(-600,0);
    glVertex2i(600,0);
    // eje y
    glVertex2i(0,-600);
    glVertex2i(0,600);
    glEnd();
    
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_QUADS);
    // Color primer cuadrante
    glColor3ub(147,198,193);
    glVertex2f(0, 10);
    glColor3ub(147,198,193);
    glVertex2f(6.5, 10);
    glColor3ub(147,198,193);
    glVertex2f(6.5, 0);
    glColor3ub(147,198,193);
    glVertex2f(0, 0);
    
    // Color segundo cuadrante
    glColor3ub(225,242,234);
    glVertex2f(-6.5, 10);
    glColor3ub(225,242,234);
    glVertex2f(0, 10);
    glColor3ub(225,242,234);
    glVertex2f(0, 0);
    glColor3ub(225,242,234);
    glVertex2f(-6.5, 0);
    
    // Color tercer cuadrante
    glColor3ub(237,201,189);
    glVertex2f(-6.5, 0);
    glColor3ub(237,201,189);
    glVertex2f(0, 0);
    glColor3ub(237,201,189);
    glVertex2f(0, -10);
    glColor3ub(237,201,189);
    glVertex2f(-6.5, -10);
    
    // Color cuarto cuadrante
    glColor3ub(228,124,123);
    glVertex2f(0, 0);
    glColor3ub(228,124,123);
    glVertex2f(6.5, 0);
    glColor3ub(228,124,123);
    glVertex2f(6.5, -10);
    glColor3ub(228,124,123);
    glVertex2f(0, -10);
    
    glEnd();
    
    // 1er cuadrante
    glViewport(300, 300, 300, 300);
    functionGraph();
    // 2do cuadrante
    glViewport(0, 300, 300, 300);
    functionGraph();
    // 3er cuadrante
    glViewport(0, 0, 300, 300);
    functionGraph();
    //4to cuadrante
    // las coordenadas se refieren a la ventana
    glViewport(300, 0, 300, 300);
    functionGraph();
    
    // Viewport pantalla completa para desplegar nombre
    glViewport(0, 0, 600, 600);
    displayName();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Omar Antonio Carreón Medrano A01036074");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}