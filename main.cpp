#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define window_height 400
#define window_width 600
float rotation = 1;
float zoom = 1;
float trans = 1;
float mouseX = 0 , mouseY = 0;

float red = 1;
float green = 0;
float blue = 0;

void display(void);
void tela(GLsizei w, GLsizei h);
//void keyboard(unsigned char tecla, int x, int y); 
void keyboard(int key, int x, int y);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //Suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //padrao de cores

	glutInitWindowSize(window_width, window_height); //Tamanho janela
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Eduardo Rampon Meireles");

	//glutFullScreen();
	glutReshapeFunc(tela);//configurar tela
	glutDisplayFunc(display);
	glutSpecialFunc(&keyboard);//chama teclado
	glutMainLoop(); //redesenhar

	return(0);
}

void keyboard(int key, int x, int y) {
	if (key == GLUT_KEY_F1) {
		red = 1;
		green = 0;
		blue = 0;
	}

	if (key == GLUT_KEY_F2) {
		red = 0;
		green = 1;
		blue = 0;
	}

	if (key == GLUT_KEY_F3) {
		red = 0;
		green = 0;
		blue = 1;
	}
	glutPostRedisplay();
}

void keyboard1(unsigned char tecla,int x,int y)
{
	printf("\nTecla  %c\n", tecla);
	printf("Digite 1 para esquera e 2 para direita");
	if (tecla == '1')
	{
		rotation = rotation + 1.5;
		printf("Valor da rotacao %.2f\n", rotation);
	}
	if (tecla == '2')
	{
		rotation = rotation - 1.5;
		printf("Valor da rotacao %.2f\n", rotation);
	}
	if (tecla == '3')
	{
		zoom = zoom + 0.5; //Escala
		printf("\nValor do zoom e %.2f\n", zoom);
	}
	if (tecla == '4')
	{
		trans = trans + 0.5;
		printf("\nValor da translacao e %.2f\n", trans);
	}
	if (tecla == '5')
	{
		trans = trans - 0.5;
		printf("\nValor da translacao e %.2f\n", trans);
	}
	if (tecla == '6')
	{
		zoom = zoom - 0.5; //Escala
		printf("\nValor do zoom e %.2f\n", zoom);
	}
	glutPostRedisplay();
}



void desenhar()
{
	
	glBegin(GL_QUADS);
	glColor3f(red, green, blue);
	glVertex2f(mouseX-30, (400 - mouseY) -30);
	glVertex2f(mouseX -30, (400 - mouseY) +30);
	glVertex2f(mouseX +30, (400 - mouseY) +30);
	glVertex2f(mouseX +30, (400 - mouseY) -30);
	glEnd();
}

void makeDraw(int button, int state, int x, int y) {
	printf("x%i\n", x);
	printf("y%i\n", y);

	mouseX = x;
	mouseY = y;
	desenhar();
	glFlush(); //Executa o desenho
}

void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();

	glClearColor(1, 1, 1, 1); //cor de fundo
	glClear(GL_COLOR_BUFFER_BIT); //Executa limpeza

	//Especificar onde o desenho ocorre
	//glTranslatef(window_width / 2, window_height / 2, 0);

	glViewport(0, 0, window_width, window_height);
	glutMouseFunc(makeDraw);

	
}

void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//cria janela (esq,direita,em baixo,em cima)
	gluOrtho2D(0, window_width, 0, window_height);

	glMatrixMode(GL_MODELVIEW);
}

