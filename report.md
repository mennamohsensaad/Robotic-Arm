# Report 

Robotic Arm
***************

## implementations
to complete robotic arm adding missing fingers in right location 
just control translation ranges so translate each finger to be side by side and rotate at fixed point  and not forget to save current matrix and restor it  in every code finger so 

To save the current state
```
glPushMatrix();
```
To restore that state
```
glPopMatrix();
```
so as example code for finger 2
```
    //Draw finger flang 2 
	glPushMatrix(); //to save current state
	glTranslatef(1.0, 0.25, 0.0);
	glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
    //Draw finger flang 2
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();

     glPopMatrix();  //to restore state
```
and also need to control movements using  keyboard keys
```
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{ 
	
	case 'a':
		fingerBase2 = (fingerBase2 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'A':
		fingerBase2 = (fingerBase2 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'b':
		fingerUp2 = (fingerUp2 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'B':
		fingerUp2 = (fingerUp2 - 5) % 90;
		glutPostRedisplay();
		break;
		case 27:
		exit(0);
		break;
	default:
		break;
	}
}
```
Note :- angle 90 is my assumption for natural  finger's movement  
## Difficult issues faced me
make finger rotate at fixed point not around other finger but I solved it  

## contribution of other
connect with my friend and tell what understand and try to reach to understanding solution to my problem 


