/*******************************************************
* Name & Matric No:                                    *
* NUR AINA BALQIS BINTI MOHAMAD ZAPARIN A23CS0151      *
* Section : 01                                         *
*******************************************************/
#include <windows.h>
#include <gl/glut.h>
#include <fstream>
#include "imageloader.h"

using namespace std;

float angleX = 0.0f, angleY = 0.0f;
bool rotateX = false, rotateY = false;

int width = 600;
int height = 400;
bool isPlaying = false;

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GLUT_SINGLE | GLUT_RGB);
    glLoadIdentity();
    glOrtho(0, width, 0, height, 0.0, 1.0);
}

void renderBitmap(float x, float y, void* font, char* string) {
    char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void update(int value) {
    if (rotateX) angleX += 1.0f;
    if (rotateY) angleY += 1.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
    case 'x':
        rotateX = !rotateX;
        break;
    case 'y':
        rotateY = !rotateY;
        break;
    }
}

GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGB,
        image->width, image->height,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        image->pixels);
    return textureId;
}

GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    Image* image1 = loadBMP("C:\\zmisc\\top.bmp");
    _textureId1 = loadTexture(image1);
    delete image1;

    Image* image2 = loadBMP("C:\\zmisc\\bottom.bmp");
    _textureId2 = loadTexture(image2);
    delete image2;

    Image* image3 = loadBMP("C:\\zmisc\\front.bmp");
    _textureId3 = loadTexture(image3);
    delete image3;

    Image* image4 = loadBMP("C:\\zmisc\\back.bmp");
    _textureId4 = loadTexture(image4);
    delete image4;

    Image* image5 = loadBMP("C:\\zmisc\\left.bmp");
    _textureId5 = loadTexture(image5);
    delete image5;

    Image* image6 = loadBMP("C:\\zmisc\\right.bmp");
    _textureId6 = loadTexture(image6);
    delete image6;
}

void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawTexturedQuad(GLuint textureId) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void displayTexts() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    char buf[200] = { 0 };

    int textX = width - 140;  // Position to the right of cube
    int textY = height - 20;
    int lineHeight = 13;

    glColor3f(0.68f, 0.85f, 0.90f);
    sprintf_s(buf, "TEXTURED BOX DEMO");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;
    sprintf_s(buf, "===============");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;

    glColor3f(1.0f, 0.75f, 0.8f);
    sprintf_s(buf, "Instructions:");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;
    sprintf_s(buf, "Button [x]: Rotate X-axis");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;
    sprintf_s(buf, "Button [y]: Rotate Y-axis");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;
    sprintf_s(buf, "Button [Esc]: Exit");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;

    glColor3f(0.6f, 1.0f, 0.6f);
    sprintf_s(buf, "Enjoy the animation and music!");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;

    glColor3f(1.0f, 1.0f, 0.0f);
    sprintf_s(buf, "Audio: Conan Tune");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;
    sprintf_s(buf, "Duration: 28s");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf); textY -= lineHeight;

    glColor3f(0, 1, 1);
    sprintf_s(buf, "Click Mouse: Toggle Audio");
    renderBitmap(textX, textY, GLUT_BITMAP_8_BY_13, buf);

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat directedLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat directedLightPos[] = { -10.0f, 15.0f, 20.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
    glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);

    // Front face
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    drawTexturedQuad(_textureId1);
    glPopMatrix();

    // Back face
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    drawTexturedQuad(_textureId2);
    glPopMatrix();

    // Left face
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawTexturedQuad(_textureId3);
    glPopMatrix();

    // Right face
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    drawTexturedQuad(_textureId4);
    glPopMatrix();

    // Top face
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    drawTexturedQuad(_textureId5);
    glPopMatrix();

    // Bottom face
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawTexturedQuad(_textureId6);
    glPopMatrix();

    displayTexts();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isPlaying) {
            PlaySound(NULL, 0, 0); // Stop
            isPlaying = false;
        }
        else {
            PlaySound(L"C:\\zmisc\\conan_detective.wav", NULL, SND_ASYNC);
            isPlaying = true;
        }
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(900, 660);

    glutCreateWindow("Texture Mapping");
    init();
    initRendering();

    glutDisplayFunc(drawScene);

    glutMouseFunc(mouse);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}