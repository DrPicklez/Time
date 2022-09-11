#version 460
#extension GL_ARB_texture_rectangle : enable
uniform sampler2DRect maskTex;
uniform sampler2DRect tex0;
uniform vec2 scalar;
in vec2 texCoordVarying;
out vec4 outputColor;
uniform float nTex;
in vec2 position;
vec4 color;

void main(){
    vec4 src = texture(tex0, texCoordVarying);
    vec4 inMask = texture(maskTex, texCoordVarying);
//    float mask = (inMask.r + inMask.g + inMask.b) / 3.;
    float mask = inMask.r ;

    float diff = 1. - clamp((abs(nTex - mask) * 10.), 0., 1.);
    src.a = diff;
    outputColor = src;
}
