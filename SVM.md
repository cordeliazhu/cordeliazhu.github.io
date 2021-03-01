# ECE6254 Support Vector Machine
## Basic notion
w is the orthogonal to all vectors that are parallel to the hyperplane.

slack variable（$$ \zeta $$)被引入用于解决线性不可分的问题
这样子公式变为$$y_i(w^Tx_i + b) >= 1- \zeta_i$$. 对此我们引入cost parameter得到soft margin hyperplane. (w^*,b^*) = argmin_{w,b,\zeta}1/2||w|| +C/n \sum\ zeta 。 为什么会变成这样子的公式呢， 因为目标是最大化别的项对


## Operating System

## Installation(Third Party Libraries)

OpenGL: Use the third party library [glfw](https://www.glfw.org/) to create windows, contexts and surfaces, receiving input and events.

```bash
Properties:C/C++ and Linker--additional library Directories
```
Load obj File:model.h resource_manager.h [github](https://github.com/NewbiZ/sandbox/tree/master/mar_tp1)
```bash
Put obj file and mtl file in the same folder
Use XXX.load to load 
```
## Usage
3DFlappyBird(please see the video for detailed descriptions)
```C++
#include "model.h"
#include "ECE_Bitmap.h"
"""
we provide some critical code about how to load the obj file and texture; the detailed implementation of our code is shown in the video.
"""
extern BMP inBitmap;
using namespace mar;
Model birdobj;
#get the location
if (birdobj.load("D:\\test\\bird \\",
		"12214_Bird_v1max_l3.obj ",
		"12214_Bird_v1max_l3.mtl"
	))
birdobj.render();
#load texture
glGenTextures(1, texture);//holding one texture
glBindTexture(GL_TEXTURE_2D, texture[0]);
#in the render.cpp file
BMP inBitmap;
GLuint index = glGenLists(1);
```

## Contributing
We formed a five persons' group. The members are:  Yilun Liu, Haibei Zhu, Huchen Guo, Jinchun Lin, Xiaoxu Zou.\
<font color='yellow'>Yilun Liu</font>: I designed the game logic and implemented the main controlling logic of the game, including interaction, camera perspectives and other internal process. I also integrated a third party obj loader into our game code and take part in part of the rendering codes design and implementation process. \
<font color='pink'>Haibei Zhu</font>: First, I debug the flippy bird's code. Then, I loaded the professor's class example picture for it is such a beautiful town. The idea came to my mind that we could do a *FROZEN* type of flippy bird! So, I load the bird obj file with black colour and the columns with blue colour to match the scenario.  To make the scene more vividly, I tuned the columns hight.  In the end, I use the markdown to write the readme.md.
## License
[Georgia Tech](https://policylibrary.gatech.edu/student-affairs/academic-honor-code)