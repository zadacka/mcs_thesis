#version 440
in vec3 vertex;
layout( location = 1 ) uniform mat4 modelview;
layout( location = 2 ) uniform mat4 projection;

void main()
{
    gl_Position = projection * modelview * vec4(vertex, 1);   
}
