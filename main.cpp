
#include <windows.h>      
#include <gl/glut.h>      
#include <math.h>     
#include <stdio.h>

#define GL_PI 3.1415f         

float fMoonRot = 0.0f;
float fAdamRot = 0.0f;
float fEarthRot = 0.0f;
float fMarsRot = 0.0f;
float fMarsatellite1 = 0.0f;
float fMarsatellite2 = 0.0f;
float fHesperRot = 0.0f;
float fJupiterRot = 0.0f;
float fSaturnRot = 0.0f;
float fSaturn1 = 0.0f;
float fUranusRot = 0.0f;
float fNeptuneRot = 0.0f;

GLfloat  whiteLight[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat  lightPos[] = { 0.0f,0.0f,0.0f,1.0f };

void sun()
{
    //绘制太阳    
    glColor3ub(255, 50, 0);
    glDisable(GL_LIGHTING);   //关闭光源      
    glutSolidSphere(25.0f, 200.0f, 200.0f);
    glEnable(GL_LIGHTING);    //启动光源    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}
void Adam()
{
    printf("hello, adam");
    //绘制水星  
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glRotatef(fAdamRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(30.0f, 0.0f, 0.0f);
    glutSolidSphere(2.0f, 200.0f, 200.0f);       //水星半径是地球的40% 即2  
    fAdamRot += 4.152f;                        //水星公转周期为地球24.08% ,即4.152  
    if (fAdamRot >= 365.0f)
        fAdamRot = 0.0f;
    glPopMatrix();
}


void Hesper()
{
    //绘制金星  
    glPushMatrix();
    glColor3ub(255, 215, 0);
    glRotatef(fHesperRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(40.0f, 0.0f, 0.0f);
    glutSolidSphere(4.75f, 200.0f, 200.0f);       //金星半径是地球的95% 即4.75  
    fHesperRot += 1.62f;                        //金星公转周期为地球61.56% ,即1.62  
    if (fHesperRot >= 365.0f)
        fHesperRot = 0.0f;
    glPopMatrix();
}
void Earth_Moon()
{

    //绘制地球,所有运行参数以地球为标准  
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(55.0f, 0.0f, 0.0f);           //设地球周期365  
    glutSolidSphere(5.0f, 20.0f, 20.0f);       //设地球半径5  

    //根据基于地球的坐标进行旋转，并绘制月球      
    glColor3ub(200, 200, 200);
    glRotatef(fMoonRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(5.0f, 0.0f, 0.0f);          // 不断平移
    fMoonRot += 13.3f;                     //月球的公转周期 27.3 天  365/27.3==13.3  
    if (fMoonRot >= 365.0f)                 // 月球半径是地球的3/11   即1.363     
        fMoonRot = 0.0f;
    glutSolidSphere(1.363f, 200.0f, 200.0f);
    glPopMatrix();                         //出栈后值变化，要在下一次循环中才有效   
    fEarthRot += 1.0f;
    if (fEarthRot >= 365.0f)
        fEarthRot = 0.0f;
}

void Mars()
{
    //绘制火星
    glPushMatrix();
    glColor3ub(255, 0, 0);
    glRotatef(fMarsRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(65.0f, 0.0f, 0.0f);
    glutSolidSphere(2.65f, 200.0f, 200.0f);       //火星半径是地球的53% 即2.65

    glPushMatrix();
    //根据基于火星的坐标进行旋转，并绘制火卫一   
    glColor3ub(255, 100, 100);
    glRotatef(fMarsatellite1, 0.0f, 1.0f, 0.0f);
    glTranslatef(2.0f, 0.0f, 2.0f);
    fMarsatellite1 += 13.3f;
    if (fMarsatellite1 >= 365.0f)
        fMarsatellite1 = 0.0f;
    glutSolidSphere(0.963f, 200.0f, 200.0f);
    glPopMatrix();

    glPushMatrix();
    //根据基于火星的坐标进行旋转，并绘制火卫二     
    glColor3ub(255, 200, 200);
    glRotatef(fMarsatellite2, 0.0f, 1.0f, 0.0f);
    glTranslatef(-3.0f, 0.0f, -3.0f);
    fMarsatellite2 += 13.3f;
    if (fMarsatellite2 >= 365.0f)
        fMarsatellite2 = 0.0f;
    glutSolidSphere(1.20f, 200.0f, 200.0f);
    glPopMatrix();

    fMarsRot += 0.5f;                           //火星公转周期为地球2倍
    if (fMarsRot >= 365.0f)
        fMarsRot = 0.0f;
    glPopMatrix();
}


void Jupiter()
{
    //绘制木星  
    glPushMatrix();
    glColor3ub(200, 100, 0);
    glRotatef(fJupiterRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(100.0f, 0.0f, 0.0f);
    glutSolidSphere(17.0f, 200.0f, 200.0f);       //木星半径是地球的11.21倍 即56.05  为了美观，定为17 

    glPushMatrix();
    glColor3ub(250, 180, 0);
    glRotatef(70.0f, 1.0f, 0.0f, 0.0f);             //环旋转70度 
    glutSolidTorus(1.42, 20, 10, 100);             //效果上看，第一个参数是圆环的宽度
    glPopMatrix();

    fJupiterRot += 0.15f;                     //木星公转周期为地球11.87倍 ,即0.084  为了明显，设为0.15
    if (fJupiterRot >= 365.0f)
        fJupiterRot = 0.0f;
    glPopMatrix();
}
void Saturn()
{
    //绘制土星  
    glPushMatrix();
    glColor3ub(73, 60, 32);
    glRotatef(fSaturnRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(148.0f, 0.0f, 0.0f);
    glutSolidSphere(15.0f, 200.0f, 200.0f);       //土星半径是地球的9.45倍 即47.25 为了美观，定为15  
    //绘制土卫一

    glPushMatrix();
    glColor3ub(255, 200, 200);
    glRotatef(fSaturn1, 0.0f, 1.0f, 0.0f);
    glTranslatef(-17.0f, 0.0f, -17.0f);
    fSaturn1 += 6.4f;
    if (fSaturn1 >= 365.0f)
        fSaturn1 = 0.0f;
    glutSolidSphere(1.20f, 200.0f, 200.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(200, 200, 100);
    glRotatef(70.0f, 1.0f, 0.0f, 0.0f);             //环旋转70度 
    glutSolidTorus(1.42, 25, 10, 100);             //效果上看，第一个参数是圆环的宽度
    glPopMatrix();

    fSaturnRot += 0.03f;                        //土星公转周期为地球29.47倍 ,即0.03  
    if (fSaturnRot >= 365.0f)
        fSaturnRot = 0.0f;
    glPopMatrix();
}
void UranusRot()
{
    //绘制天王星  
    glPushMatrix();
    glColor3ub(0, 180, 100);
    glRotatef(fUranusRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(202.0f, 0.0f, 0.0f);
    glutSolidSphere(15.0f, 200.0f, 200.0f);       //天王星半径是地球的倍 即4.01，即15    

    glPushMatrix();
    glColor3ub(0, 100, 0);
    glRotatef(150.0f, 1.0f, 0.0f, 0.0f);             //环旋转度 
    glutSolidTorus(1.0, 20, 10, 100);             //效果上看，第一个参数是圆环的宽度
    glPopMatrix();

    fUranusRot += 0.03f;                        //天王星公转周期为地球84.06倍 ,即0.0124  
    if (fUranusRot >= 365.0f)
        fUranusRot = 0.0f;
    glPopMatrix();
}

void Neptune()
{
    //绘制海王星  
    glPushMatrix();
    glColor3ub(0, 0, 215);
    glRotatef(fNeptuneRot, 0.0f, 1.0f, 0.0f);
    glTranslatef(240.0f, 0.0f, 0.0f);
    glutSolidSphere(19.45f, 200.0f, 200.0f);       //海王星半径是地球的倍 即3.89，即19.45    
    fNeptuneRot += 2.17f;                       //天王星公转周期为地球46%倍 ,即2.17  
    if (fUranusRot >= 365.0f)
        fNeptuneRot = 0.0f;
    glPopMatrix();
}
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -300.0f);

    sun();
    Adam();
    Hesper();
    Earth_Moon();
    Mars();
    Jupiter();
    Saturn();
    UranusRot();
    Neptune();

    glPopMatrix();
    glutSwapBuffers();
}
void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat fAspect;
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, fAspect, 1.0, 4000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupRC(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_LIGHTING);                             //启动光源      
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight); //使用whiteLght所指定的环境光      
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);         //0号光源的位置      
    glEnable(GL_LIGHT0);
}
void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Orthographic Projection");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    SetupRC();
    glutTimerFunc(250, TimerFunc, 1); //自动动画，计时器   
    glutMainLoop();
    return 0;
}
