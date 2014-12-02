// This file was created by Filewrap 1.2
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: effect.pfx ********

// File data
static const char _effect_pfx[] = 
	"[HEADER]\n"
	"\tVERSION\t\t01.00.00.00\n"
	"\tDESCRIPTION OGLES2OcclusionQueries\n"
	"\tCOPYRIGHT\tImagination Technologies\n"
	"[/HEADER]\n"
	"\n"
	"[EFFECT] \n"
	"\tNAME \tRenderDiffuse\n"
	"\t\t\n"
	"\t// GLOBALS UNIFORMS\n"
	"\tUNIFORM uWorldViewProjMatrix\tWORLDVIEWPROJECTION\n"
	"\tUNIFORM uWorldViewMatrix\t\t\tWORLDVIEW\n"
	"\tUNIFORM uWorldViewIT\t\t \t\tWORLDVIEWIT\t\n"
	"\tUNIFORM uLightPosView\t\t\t\tLIGHTPOSEYE\n"
	"\tUNIFORM uColour\t\t\t\t\t\tMATERIALCOLORDIFFUSE\n"
	"\t\t\n"
	"\tUNIFORM sTexture\t\t\t\t\tTEXTURE0\n"
	"\t\n"
	"\t// ATTRIBUTES\n"
	"\tATTRIBUTE inVertex\t\tPOSITION\n"
	"\tATTRIBUTE\tinNormal\t\tNORMAL\n"
	"\tATTRIBUTE\tinTexCoord\tUV\t\t\n"
	"\t\n"
	"\t// SHADERS\n"
	"\tVERTEXSHADER   DiffuseVertexShader\n"
	"\tFRAGMENTSHADER DiffuseFragmentShader\n"
	"[/EFFECT]\n"
	"\n"
	"[VERTEXSHADER]\n"
	"\tNAME \t\tDiffuseVertexShader\n"
	"\n"
	"\t[GLSL_CODE]\n"
	"\t\tattribute highp   vec3 inVertex;\n"
	"\t\tattribute highp   vec3 inNormal;\n"
	"\t\tattribute mediump vec2 inTexCoord;\n"
	"\n"
	"\t\tuniform highp mat4 uWorldViewProjMatrix;\n"
	"\t\tuniform highp mat4 uWorldViewMatrix;\n"
	"\t\tuniform highp mat3 uWorldViewIT;\n"
	"\t\tuniform highp vec3 uLightPosView;\n"
	"\n"
	"\t\tvarying mediump vec2  vTexCoord;\n"
	"\t\tvarying highp   float vDiffuse;\n"
	"\t\t\n"
	"\t\tvoid main() \n"
	"\t\t{ \n"
	"\t\t\tgl_Position = uWorldViewProjMatrix * vec4(inVertex, 1.0);\n"
	"\t\t\tvTexCoord = inTexCoord;\n"
	"\t\t\t\n"
	"\t\t\thighp vec3 posView = (uWorldViewMatrix * vec4(inVertex, 1.0)).xyz;\n"
	"\t\t\thighp vec3 lightDirView = normalize(uLightPosView - posView);\n"
	"\t\t\thighp vec3 normalView = uWorldViewIT * inNormal;\n"
	"\t\t\tvDiffuse = max(dot(lightDirView, normalView), 0.0);\n"
	"\t\t} \n"
	"\t[/GLSL_CODE]\n"
	"[/VERTEXSHADER]\n"
	"\n"
	"    \n"
	"[FRAGMENTSHADER] \n"
	"\tNAME \t\tDiffuseFragmentShader \n"
	"\n"
	"\t[GLSL_CODE]\n"
	"\t  uniform  sampler2D  sTexture;\n"
	"\t  uniform  lowp vec4  uColour;\n"
	"\n"
	"\t  varying mediump vec2  vTexCoord;\n"
	"\t  varying highp   float vDiffuse;\n"
	"\n"
	"\t  void main()\n"
	"\t  {\n"
	"\t\t\tgl_FragColor = texture2D(sTexture, vTexCoord) * uColour * vDiffuse;\n"
	"\t  }\n"
	"\t[/GLSL_CODE]\n"
	"[/FRAGMENTSHADER]\n"
	"\n"
	"\n"
	"//\n"
	"// Renders a single constant material colour\n"
	"//\n"
	"\n"
	"[EFFECT] \n"
	"\tNAME \tRenderMaterialColour\n"
	"\t\t\n"
	"\t// GLOBALS UNIFORMS\n"
	"\tUNIFORM uWorldViewProjMatrix\tWORLDVIEWPROJECTION\n"
	"\tUNIFORM uMaterialColour\t\t\tMATERIALCOLORDIFFUSE\n"
	"\t\n"
	"\t// ATTRIBUTES\n"
	"\tATTRIBUTE inVertex\t\tPOSITION\n"
	"\n"
	"\t// SHADERS\t\n"
	"\tVERTEXSHADER   MaterialColourVertexShader\n"
	"\tFRAGMENTSHADER MaterialColourFragmentShader\n"
	"[/EFFECT]\n"
	"\n"
	"[VERTEXSHADER]\n"
	"\tNAME \t\tMaterialColourVertexShader\n"
	"\n"
	"\t[GLSL_CODE]\n"
	"\t\tattribute highp   vec3 inVertex;\n"
	"\n"
	"\t\tuniform highp mat4 uWorldViewProjMatrix;\n"
	"\n"
	"\t\tvoid main() \n"
	"\t\t{ \n"
	"\t\t\tgl_Position = uWorldViewProjMatrix * vec4(inVertex, 1.0);\n"
	"\t\t} \n"
	"\t[/GLSL_CODE]\n"
	"[/VERTEXSHADER]\n"
	"\n"
	"[FRAGMENTSHADER] \n"
	"\tNAME \t\tMaterialColourFragmentShader \n"
	"\n"
	"\t[GLSL_CODE]\n"
	"\t\tuniform  lowp vec4 uMaterialColour;\n"
	"\n"
	"\t\tvoid main()\n"
	"\t\t{\n"
	"\t\t\tgl_FragColor = uMaterialColour;\n"
	"\t\t}\n"
	"\t[/GLSL_CODE]\n"
	"[/FRAGMENTSHADER]\n";

// Register effect.pfx in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_effect_pfx("effect.pfx", _effect_pfx, 2560);

// ******** End: effect.pfx ********
