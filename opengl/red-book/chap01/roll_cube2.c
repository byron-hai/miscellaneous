/*
 * roll_cube2.c
 * Draw a rolling cube.
 * This time we draw the cube by ourselves
 */
#include <GL/glut.h>

static GLfloat xspin = 0.0f;
static GLfloat yspin = 0.0f;
static GLfloat zspin = 0.0f;

static void init( void );
static void display( void );
static void reshape( int width, int height );
static void keyboard( unsigned char key, int x, int y );
static void specialKeys( int key, int x, int y );

int main( int argc, char **argv ) {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowSize( 256, 256 );
  glutInitWindowPosition( 128, 64 );
  glutCreateWindow( "Rolling Cube" );

  init();
  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );
  glutSpecialFunc( specialKeys );
  glutMainLoop();
  return 0;
}

static void init( void ) {
  glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
  glShadeModel( GL_FLAT );
}

static void display( void ) {
  glClear( GL_COLOR_BUFFER_BIT );
  glPushMatrix();
  glRotatef( xspin, 1.0f, 0.0f, 0.0f );
  glRotatef( yspin, 0.0f, 1.0f, 0.0f );
  glRotatef( zspin, 0.0f, 0.0f, 1.0f );

  /* draw a cube with length is 50.0f */
  GLfloat len = 50.0f;
  GLfloat x0 = -25.0f;
  GLfloat y0 = -25.0f;
  GLfloat z0 = -25.0f;
  glBegin( GL_QUADS );
    /* left face: red */
    glColor3f( 1.0f, 0.0f, 0.0f );
    glVertex3f( x0, y0, z0 + len );
    glVertex3f( x0, y0 + len, z0 + len );
    glVertex3f( x0, y0 + len, z0 );
    glVertex3f( x0, y0, z0 );
    
    /* upper face: green */
    glColor3f( 0.0f, 1.0f, 0.0f );
    glVertex3f( x0, y0 + len, z0 + len );
    glVertex3f( x0 + len, y0 + len, z0 + len );
    glVertex3f( x0 + len, y0 + len, z0 );
    glVertex3f( x0, y0 + len, z0 );

    /* right face: blue */
    glColor3f( 0.0f, 0.0f, 1.0f );
    glVertex3f( x0 + len, y0 + len, z0 + len );
    glVertex3f( x0 + len, y0, z0 + len );
    glVertex3f( x0 + len, y0, z0 );
    glVertex3f( x0 + len, y0 + len, z0 );

    /* lower face: yellow */
    glColor3f( 1.0f, 1.0f, 0.0f );
    glVertex3f( x0 + len, y0, z0 + len );
    glVertex3f( x0 + len, y0, z0 );
    glVertex3f( x0, y0, z0 );
    glVertex3f( x0, y0, z0 + len );

    /* front face: black */
    glColor3f( 1.0f, 0.0f, 0.0f );
    glVertex3f( x0 + len, y0, z0 );
    glVertex3f( x0 + len, y0 + len, z0 );
    glVertex3f( x0, y0 + len, z0 );
    glVertex3f( x0, y0, z0 );

    /* back face: white */
    glColor3f( 0.0f, 1.0f, 1.0f );
    glVertex3f( x0 + len, y0, z0 + len );
    glVertex3f( x0 + len, y0 + len, y0 + len );
    glVertex3f( x0, y0 + len, z0 + len );
    glVertex3f( x0, y0, z0 + len );
  glEnd();
  glPopMatrix();
  glutSwapBuffers();
}

static void reshape( int width, int height ) {
  GLfloat range = 100.0f;
  if ( height == 0 ) {
    height = 1;
  }
  glViewport( 0, 0, (GLsizei) width, (GLsizei) height );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  if ( width <= height ) {
    glOrtho( -range, range, -range*height/width, range*height/width, -range, range );
  } else {
    glOrtho( -range*width/height, range*width/height, -range, range, -range, range );
  }
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
}

static void keyboard( unsigned char key, int x, int y ) {
  if ( key == 'z' ) {
    zspin += 5.0f;
  } else if ( key == 'a' ) {
    zspin -= 5.0f;
  }
  glutPostRedisplay();
}

static void specialKeys( int key, int x, int y ) {
  if ( key == GLUT_KEY_UP ) {
    xspin += 5.0f;
  } else if ( key == GLUT_KEY_DOWN ) {
    xspin -= 5.0f;
  } else if ( key == GLUT_KEY_LEFT ) {
    yspin -= 5.0f;
  } else if ( key == GLUT_KEY_RIGHT ) {
    yspin += 5.0f;
  }
  glutPostRedisplay();
}