//#include <windows.h>
#include <GLUT/glut.h>


#include <stdlib.h>
#include <stdio.h>

#include <math.h>
// Tamaño inicial de la ventana
double PI=3.14159265358979;
GLsizei winWidth =600, winHeight =600;
GLint xRaster = 25, yRaster = 150; //posicion inicial de rastreo
GLubyte label[36] = { 'E', 'n', 'e', 'F','e', 'b', 'M', 'a', 'r',
    'A', 'b', 'r', 'M', 'a', 'y', 'J', 'u','n',
    'J', 'u', 'l', 'A', 'g', 's', 'S', 'e','p',
    'O', 'c', 't', 'N', 'o', 'v', 'D', 'i','c'
};
GLint dataValue[12] = {420, 342, 324,
    310, 262, 185,
    190, 196, 217, 240, 312, 438
};
void init(void)
{
    glClearColor(1.0,0.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//limpiar la matriz de proyeccción
    gluOrtho2D(-600,600, -600,600);
}
void lineGraph(void)
{
    GLint month, k;
    GLint x = 30;
    
    //*******Para desplegar nombre ********//
    //*************************************//
    char msg[200]="";
    sprintf(msg, "%s","Omar Antonio Carreon Medrano");
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.0, 1.0);//Azul tec
    
    // Dibuja nombre
    glRasterPos2i(-600,-400);
    for (k=0; msg[k] != '\0'; k++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[k]);
    }
    
    
    //********* Dibuja la grafica de lineas ***********//
    //************************************************//
    glBegin(GL_LINE_STRIP);
    for (k=0; k<12; k++)
        glVertex2i(x+k*50,dataValue[k]);
    glEnd();
    
    
    //*******Dibujar la gráfica de barras************//
    //************************************************//
    
    for (k=0; k<12; k++)
    {
        glColor3f(k%2, k%2, k%2);
        glRectd(x, 0, x+20, dataValue[k]);
        x=x+50;
    }
    
    
    
    //****************** Dibuja los * ****************//
    //************************************************//
    // se declara esta variable para que los asteriscos no desaparezcan al cambiar tamaño de pantalla
    xRaster = 25;
    glColor3f(1.0, 1.0, 0.0);
    for (k=0; k<12; k++)
    {
        glRasterPos2i(xRaster+ k*50, dataValue[k]-4);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
    }
    glColor3f(0.0, 0.0, 0.0);
    
    
    //*************Dibujar eje de coordenas x-y**********//
    //**************************************************//
    glBegin(GL_LINES);
    //eje x
    glVertex2i(-600,0);
    glVertex2i(600,0);
    // eje y
    glVertex2i(0,-600);
    glVertex2i(0,600);
    glEnd();
    
    //*************Despliega los nombres del mes***********//
    //****************************************************//
    xRaster = 5;
    yRaster = -25;
    for (month=0; month<12;month++)
    {
        glRasterPos2i(xRaster,yRaster);
        for (k=3*month;k<3*month + 3; k++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
        xRaster +=50;
    }
    glColor3f(1.0,0.0,1.0);
    
    glFlush();
}

//void winReshapeFcn(int newWidth,int newHeight)
//{
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0,(GLdouble)newWidth, 0.0, (GLdouble)newHeight);
//    glClear(GL_COLOR_BUFFER_BIT);
//}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line chart dataplot");
    init();
    glutDisplayFunc(lineGraph);
    //    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
    return 0;
}