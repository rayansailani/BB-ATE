#include<GL/glut.h>
#include<iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;
GLint headx =300,heady = 100, legLeft = 0, hig = 40;
GLint footx = headx + 10;
GLint dis = 100,ldis = 80;
GLfloat fdis = 40,fhig = 30;
GLint foodx[5] = {101,240, 390 ,550 ,600};
GLint foody[5] = {700,700,700,700,700};
int score = 0;
GLint dy[2] = {800,800};
GLint dx[2] = {rand()%700,rand()%700};
GLint dd = 20;
const int font=(int)GLUT_BITMAP_9_BY_15;
string name;

void init()
{
    glClearColor(0,0,0,1);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,700,0,700);
}
void draw_head()
{
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(headx, heady);
    glVertex2f(headx,heady-hig);
    glVertex2f(headx+dis,heady-hig);
    glVertex2f(headx+dis,heady);
    glEnd();
}
void draw_down()
{
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(footx, heady-hig);
    glVertex2f(footx,0);
    glVertex2f(footx+ldis,0);
    glVertex2f(footx+ldis,heady-hig);
    glEnd();
}
void draw_danger()
{
    glColor3f(1,0.6,0.5);
    glBegin(GL_TRIANGLES);
    glVertex2f(dx[0],dy[0]);
    glVertex2f(dx[0]-dd,dy[0]-10);
    glVertex2f(dx[0]+dd,dy[0]-10);

    glColor3f(1,0,0.6);
    glVertex2f(dx[1],dy[1]);
    glVertex2f(dx[1]-dd,dy[1]-10);
    glVertex2f(dx[1]+dd,dy[1]-10);
    glEnd();
}
void draw_food()
{
        //first food particle
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2f(foodx[0],foody[0]);
        glVertex2f(foodx[0],foody[0]  - fhig);
        glVertex2f(foodx[0] + fdis,foody[0]  - fhig);
        glVertex2f(foodx[0] + fdis,foody[0]);
        glEnd();
        //second food
        glColor3f(0,1,0);
        glBegin(GL_QUADS);
        glVertex2f(foodx[1],foody[1]);
        glVertex2f(foodx[1],foody[1]  - fhig);
        glVertex2f(foodx[1] + fdis,foody[1]  - fhig);
        glVertex2f(foodx[1] + fdis,foody[1]);
        glEnd();
        glColor3f(0,0,1);
        glBegin(GL_QUADS);
        glVertex2f(foodx[2],foody[2]);
        glVertex2f(foodx[2],foody[2]  - fhig);
        glVertex2f(foodx[2] + fdis,foody[2]  - fhig);
        glVertex2f(foodx[2] + fdis,foody[2]);
        glEnd();
        glColor3f(1,0,1);
        glBegin(GL_QUADS);
        glVertex2f(foodx[3],foody[3]);
        glVertex2f(foodx[3],foody[3]  - fhig);
        glVertex2f(foodx[3] + fdis,foody[3]  - fhig);
        glVertex2f(foodx[3] + fdis,foody[3]);
        glEnd();
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        glVertex2f(foodx[4],foody[4]);
        glVertex2f(foodx[4],foody[4]  - fhig);
        glVertex2f(foodx[4] + fdis,foody[4]  - fhig);
        glVertex2f(foodx[4] + fdis,foody[4]);
        glEnd();



}
void draw_robo()
{
    draw_head();
    draw_down();
}
string int_to_string(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

//void move_food()
//{
//    glutPostRedisplay();
//}
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    //if(x_position<=8.0)
    //x_position += 0.15;
    //else
       // x_position = -10.0;

    if (foody[0] == 0 || ((foodx[0] >= headx-10 && foodx[0] <= headx + dis+10)&& foody[0] == (heady+30) ))
    {
            foody[0] = 700;
            int ran = rand();
            ran = ran%680;
            foodx[0]= ran;
            score+=5;
    }
    if (foody[1] == 0 || ((foodx[1] >= headx-10 && foodx[1] <= headx + dis +10) && foody[1] == (heady+30) ))
    {
        foody[1] = 700;
            int ran = rand();
            ran = ran%680;
            foodx[1]= ran;
            score+=3;
    }
    if (foody[2] == 0 || ((foodx[2] >= headx-10 && foodx[2] <= headx + dis +10) && foody[2] == (heady+30) ))
    {
        foody[2] = 700;
            int ran = rand();
            ran = ran%680;
            foodx[2]= ran;
            score+=2;
    }
    if (foody[3] == 0 || ((foodx[3] >= headx-10 && foodx[3] <= headx + dis +10) && foody[3] == (heady+30) ) )
    {
        foody[3] = 700;
            int ran = rand();
            ran = ran%680;
            foodx[3]= ran;
            score+=1;
    }
    if (foody[4] == 0 || ((foodx[4] >= headx-10 && foodx[4] <= headx + dis +10) && foody[4] == (heady) ) )
    {
        foody[4] = 700;
            int ran = rand();
            ran = ran%680;
            foodx[4]= ran;
            foodx[4]= ran;
            score+=4;
    }

    foody[0] -= 5;
    foody[1] -= 3;
    foody[2] -= 2;
    foody[3] -= 1;
    foody[4] -= 4;

    cout<<score<<endl;
    if (score >50)
    {
        dy[0]-=5;
        dy[1]-=5;
        if(dy[0] == 0)
        {
            dy[0] = 700;
            dx[0] = rand()%700;
        }
        if (dy[1] == 0)
        {
            dy[1] = 700;
            dx[1] = rand()%700;
        }
        if((dx[0] >= headx && dx[0] < headx+dis) && dy[0] == heady)
        {
            cout<<name<<"Your Final score is "<<score<<endl;
            string s = int_to_string(score);
            const char* ptr = s.c_str();
            MessageBox(NULL,ptr,"score",MB_OK);
            exit(0);
        }
        if((dx[1] >= headx && dx[1] < headx+dis) && dy[1] == heady)
        {
            cout<<name<<"Your Final score is "<<score<<endl;
            string s = int_to_string(score);
            const char* ptr = s.c_str();
           MessageBox(NULL,ptr,"score",MB_OK);
            exit(0);
        }
    }
}
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void display()
{
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_robo();
    draw_food();
    draw_danger();
    glColor3f(1,1,1);
    ostringstream ss;
    renderBitmapString(10,10,(void *)font,"Hey! this game was developed by Mohammed Rayan Sailani 18GAEM9050");
    renderBitmapString(320,670,(void *)font,"Always eat the blocks and dodge the triangles!");
    renderBitmapString(320,670,(void *)font,"Always eat the blocks and dodge the triangles!");
    glutSwapBuffers();
}

void key(unsigned char ch, int x ,int y)
{
    switch(ch)
    {
    case 'a':
        if (headx==0){
            headx = 650;
            footx = 660;
        }
        else{
        headx -= 10;
        footx -= 10;
        }
        break;
    case 'd':
        if (headx==650){
            headx = 0;
            footx = 10;
        }
        else{
        headx += 10;
        footx += 10;
        }
        break;
    }
    glutPostRedisplay();
}

int main(int argc,char * argv[])
{
    cout<<"Enter your name"<<endl;
    cin>>name;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,800);
    glutCreateWindow("BB-ATE");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}
