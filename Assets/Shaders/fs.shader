//Version we are using
#version 330 core

//in Variables
in vec4 fragmentColor;
in vec2 fragmentUV;

//out variables
out vec4 color;

//Uniform variables
uniform sampler2D tSampler;


void main() {
	//Where we are going to assign values to variables
	vec4 imageTexture = texture(tSampler, fragmentUV);
	color = imageTexture * fragmentColor;
}