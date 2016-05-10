//
//  main.cpp
//  Memorama
//
//
//  Ricardo Perez Perez A01035082
//  Omar Antonio Carreon Medrano A01036074
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
#include <algorithm>
#include <array>
#include <random>
#include <chrono>


int enteroGlobal = 0;
bool running = false;

int	screenWidth = 640, screenHeight = 480;

array<int,16> arrVal {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
array<bool,16> arrBool {false};
int a=-1, b=-1, turns=0;
bool finished = false;
bool start = false;

void draw3dString (void *font, char *s, float x, float y, float z)
{
    unsigned int i;
    glMatrixMode(GL_MODELVIEW);
    glLineWidth(1);
    glPushMatrix();
    glTranslatef(x, y, z);
    
    glScaled(0.005, 0.005, 1);
    
    for (i = 0; i < s[i] != '\0'; i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, s[i]);
                 
    }
    glPopMatrix();
}

void init(){
    
    // shuffle array
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (arrVal.begin(), arrVal.end(), default_random_engine(seed));
    for (int i = 0;i<16;i++){
        arrBool[i]=false;
    }
    a = -1;
    b = -1;
    finished = false;
    start = false;
}

void reshape(int ancho, int alto) {
    
    screenHeight = alto;
    screenWidth = ancho;
    
    glViewport(0.0,0.0,(GLdouble) ancho,(GLdouble)  alto);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0,16,0,16);
    
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
        cadena =to_string(minutes) + ":0" + to_string(seconds) + ":" + to_string(mili);
    } else {
        cadena = to_string(minutes) + ":" + to_string(seconds) + ":" + to_string(mili);
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
    draw3dString(GLUT_STROKE_MONO_ROMAN,displaycadena,2, 5, 0.1);

}


//********* Timer ***********//
//**************************//
void myTimer(int i) {
    if (running){
        enteroGlobal+=1;
    }
    glutPostRedisplay();
    glutTimerFunc(100,myTimer,1);
    
}

void displayNumber(int number, int pos){
    
    GLint y;
    char displaynumber[2]="";
    sprintf(displaynumber, "%d",number);
    
    // ******Dibuja numero*********//
    // ************************************************//
    glColor3i(100, 150, 100);
    glRasterPos2f(pos+0.3,11);
    for (y=0; displaynumber[y] != '\0'; y++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, displaynumber[y]);
    }
    
    
}

//******** Eventos del Mouse ********//
//**********************************//
void myMouse(int button, int state, int x, int y)
{
    if(start){
        if (!finished){
            
            float mouseX = (x*16.0)/640;
            float mouseY = (y*16.0)/480;
            
            if (state == GLUT_DOWN){
                if (mouseY < 6){
                    if (a != -1 && b!= -1){
                        if (arrVal[a] != arrVal[b]){
                            arrBool[a] = false;
                            arrBool[b] = false;
                        }
                        a = -1;
                        b = -1;
                    }
                    mouseX = floor(mouseX);
                    if (!arrBool[mouseX]){
                        arrBool[mouseX]=true;
                        if (a == -1) {
                            a = mouseX;
                        } else {
                            b = mouseX;
                        }
                        if (a!=-1 && b!=-1){
                            turns++;
                            if (arrVal[a] == arrVal[b]){
                                finished = true;
                                for (int k = 0; k<16;k++){
                                    if (!arrBool[k]){
                                        finished = false;
                                        break;
                                    }
                                }
                                if (finished) {
                                    running = false;
                                }
                            }
                        }
                        
                    }
                }
            }
        }
    }
}



//********* Eventos del teclado ***********//
//*****************************************//
void myKeyboard(unsigned char theKey, int mouseX, int mouseY){
    switch (theKey){
        case 'I':
        case 'i':
            if (!finished){
                start = true;
                running = true;
            }
            
            break;
            
        case 'P':
        case 'p':
            start = false;
            running = false;
            break;
            
        case 'R':
        case 'r':
            // reset
            running = false;
            enteroGlobal = 0;
            turns = 0;
            init();
            break;
            
        case 27:
            exit(0);
            break;
    }
}

//*******Despliega Letrero Turnos ********//
//*******************************************//
void displayTurnsMessage(void){
    char turnsmessage[200]="";
    sprintf(turnsmessage, "%s %d","Turns:",turns);
    glColor3f(0.0, 0.0, 0.0);
    draw3dString(GLUT_STROKE_MONO_ROMAN,turnsmessage,10, 5, 0.1);
}

//*****Despliega Letrero de Eventos de teclado ********//
//*******************************************************//
void displayEventsText(void){
    GLint x;
    char events1[200]="", events2[200]="", autor1[200]="", autor2[200]="";
    sprintf(events1, "%s","Autores: Ricardo Perez Perez A01035082");
    draw3dString(GLUT_STROKE_MONO_ROMAN,events1,1, 4, 0.1);
    sprintf(events1, "%s","Omar Antonio Carreon Medrano A01036074");
    draw3dString(GLUT_STROKE_MONO_ROMAN,events1,1, 3, 0.1);
    sprintf(events1, "%s","I-Iniciar, P-Pausa, R-Reiniciar");
    draw3dString(GLUT_STROKE_MONO_ROMAN,events1,1, 2, 0.1);
    sprintf(events2, "%s","Esc-Salir");
    draw3dString(GLUT_STROKE_MONO_ROMAN,events2,1, 1, 0.1);
    
}

void displayShuffleNumbers(void){
    char shuffledarray[200]="";
    for(int i=0;i<16;i++){
        sprintf(shuffledarray,"%d", arrVal[i]);
        draw3dString(GLUT_STROKE_MONO_ROMAN,shuffledarray,i+0.3, 8, 0.1);
    }
    
}
void myDisplay()
{
    glClearColor(0.12f,0.85f,0.56f, 0.0f);  //Color del background
    glClear( GL_COLOR_BUFFER_BIT );
    glPointSize(10);
    for (int i=0;i<16;i++){
        if (i%2==0){
            glColor3ub(255, 255, 0);
            
        } else {
            glColor3ub(10, 120, 120);
        }
        if (i == a || i == b){
            glColor3ub(0, 255, 0);
        }
        glRecti(i, 10, i+1, 16);
        
        if (arrBool[i]){
            displayNumber(arrVal[i],i);
        }
        if (finished){
            GLint k;
            char turnsmessage[500]="";
            sprintf(turnsmessage, "%s %d %s","Felicidades terminaste el juego en ",turns, " turnos");
            glRasterPos2f(2,8);
            for (k=0; turnsmessage[k] != '\0'; k++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, turnsmessage[k]);
            }
        }
        
    }
    displayTimer();
    displayTurnsMessage();
    displayEventsText();
    displayShuffleNumbers();
    glutSwapBuffers();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(screenWidth,screenHeight);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow("Memorama");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutReshapeFunc(reshape);
    glutTimerFunc(100,myTimer,1);
    glutMainLoop();
    
    return EXIT_SUCCESS;
}
