#include <GL/glut.h>

float angle = 0.0f; // 주전자의 초기 회전 각도

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0); // 원근 투영 설정
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 버퍼 지우기
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f); // 카메라 이동
    glRotatef(angle, 1.0f, 1.0f, 1.0f); // 주전자 회전
    
    // 색상 설정 (파란색)
    glColor3f(0.0, 0.0, 1.0);
    
    glutWireTeapot(1.0); // 주전자 그리기
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 뷰포트 설정
}

void timer(int value) {
    angle += 1.0f; // 회전 각도 업데이트
    glutPostRedisplay(); // 디스플레이 콜백 호출
    glutTimerFunc(16, timer, 0); // 16ms마다 타이머 콜백 호출
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // 타이머 등록

    glutMainLoop();
    return 0;
}
