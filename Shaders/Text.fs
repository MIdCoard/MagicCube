#version 450 core

out vec4 FragColor;

in vec2 Tex;

uniform float Alpha;

uniform sampler2D Texture;

void main(){
   FragColor = vec4(texture(Texture, Tex).xyz,Alpha);
}
