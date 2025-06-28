#shader vertex
#version 120
attribute vec4 position;
void main(){
	gl_Position = position;
};

#shader fragment
#version 120
varying vec2 v_texCoord;
uniform sampler2D s_texture;
void main(){
	gl_FragColor = texture2D(s_texture, v_texCoord);
};
