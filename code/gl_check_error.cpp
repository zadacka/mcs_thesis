void checkerror(){
    GLenum err;
    if ((err = glGetError()) != GL_NO_ERROR) {
        cerr << "OpenGL error: " << err << endl;
	
	std::string error;
	switch(err) {
	case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
	case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
	case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
	case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
	}
 
	std::cout << "GL_" << error.c_str() << std::endl;
	exit(1);
    }
    return;
}