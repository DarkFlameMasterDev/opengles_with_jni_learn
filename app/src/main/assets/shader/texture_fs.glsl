#version 300 es
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D t;

void main(){
    FragColor = texture(t, TexCoord);
}