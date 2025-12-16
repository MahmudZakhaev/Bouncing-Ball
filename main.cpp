#include <GL/glut.h>
#include <cmath>

// Ball position and speed
float xPos = 0.0f;
float yPos = 0.0f;
float xSpeed = 0.02f;
float ySpeed = 0.015f;

void drawBall(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 3.14159f / 180.0f;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw red ball
    glColor3f(1.0, 0.0, 0.0);
    drawBall(xPos, yPos, 0.1f);

    glutSwapBuffers();
}

void update(int value) {
    // Move ball
    xPos += xSpeed;
    yPos += ySpeed;

    // Bounce off walls
    if (xPos > 0.9f || xPos < -0.9f) xSpeed = -xSpeed;
    if (yPos > 0.9f || yPos < -0.9f) ySpeed = -ySpeed;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // roughly 60 FPS
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // 2D view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bouncing Ball (2D) - OpenGL Project");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
