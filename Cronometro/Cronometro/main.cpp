//
//  main.cpp
//  Cronometro
//
//  Created by Omar Carreon on 02/02/16.
//  Copyright © 2016 OmarCarreon. All rights reserved.
//

//
//  main.cpp
//  TimerAD15
//
//  Created by Ma. Guadalupe Roque on 8/25/15.
//  Copyright (c) 2015 ITESM. All rights reserved.
//
//
using namespace std;
#include <string>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

#include <iostream>


float t=-1.0;
float delta=0.1;
int enteroGlobal = 0;
bool running = false;

int	screenWidth = 640, screenHeight = 480;

void reshape(int ancho, int alto) {
    
    screenHeight = alto;
    screenWidth = ancho;
    
    glViewport(0.0,0.0,(GLdouble) ancho,(GLdouble)  alto);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    // hace la conversion a openGL
    gluOrtho2D( 0.0,(GLdouble) ancho, 0.0,(GLdouble)  alto);
    
    
}
// ****Genera el formato del timer ****//
// ************************************//
string formato(int i){
    int seconds, minutes ,mili;
    string cadena;
    
    mili = i%10;
    minutes = floor((i/10)/60);
    seconds = (i/10) - minutes * 60;
    if (seconds <10){
        cadena =to_string(minutes) + ":0" + to_string(seconds) + "." + to_string(mili);
    } else {
        cadena = to_string(minutes) + ":" + to_string(seconds) + "." + to_string(mili);
    }
    return cadena;
}

// ****** Dibuja timer ********//
// ****************************//
void displayTimer(){
    
    GLint x;
    char displaycadena[200]="";
    string cadena = "";
    cadena = formato(enteroGlobal);
    
    sprintf(displaycadena, "%s",cadena.c_str());
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(100,300);
    for (x=0; displaycadena[x] != '\0'; x++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, displaycadena[x]);
    }
}


//********* Timer ***********//
//**************************//
void myTimer(int i) {
    if (running){
        enteroGlobal+=1;
    }
    delta = 0.1;
    t += delta;
    glutPostRedisplay();
    glutTimerFunc(100,myTimer,1);
    
}


//********* Eventos del teclado ***********//
//*****************************************//
void myKeyboard(unsigned char theKey, int mouseX, int mouseY){
    switch (theKey){
        case 'I':
        case 'i':
            // iniciar
            running = true;
            break;
            
        case 'S':
        case 's':
            //stop;
            running = false;
            break;
            
        case 'R':
        case 'r':
            // reset
            running = false;
            enteroGlobal = 0;
            break;
            
        case 27:
            exit(0);
            break;
    }
}
//*******Despliega Eventos de teclado ********//
//*******************************************//
void displayEventsText(void){
    //*******Para desplegar eventos de teclado en pantalla ********//
    //******************************************************//
    GLint x;
    char events1[200]="", events2[200]="";
    sprintf(events1, "%s","I-Inicio, S-Stop, R-Reset");
    sprintf(events2, "%s","Esc-Salir");
    
    
    // ******Dibuja evento Iniciar, detener y reset*********//
    // ************************************************//
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(50,200);
    for (x=0; events1[x] != '\0'; x++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, events1[x]);
    }
    
    // ********Dibuja evento Salir*****************//
    // *******************************************//
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(400,50);
    for (x=0; events2[x] != '\0'; x++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, events2[x]);
    }
}

void myDisplay()
{
    glClearColor(0.12f,0.85f,0.56f, 0.0f);  //Color del background
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0f, 0.0f, 0.0f ); //Color para pintar
    displayEventsText();
    displayTimer();
    glutSwapBuffers();
    
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(screenWidth,screenHeight);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
    glutCreateWindow("Animacion");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(100,myTimer,1);
    glutMainLoop();
    return EXIT_SUCCESS;
}



