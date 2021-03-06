The Geometry Compiler
=====================
The Geometry Compiler is used to compile the ``dist`` and ``colour`` functions
within shape values into efficient machine code for GPUs and CPUs.
Note that a Curv program is first evaluated to a shape value using the
interpreter, and then the shape value is further compiled to machine code.

* When a shape is rendered in the Viewer window,
  this is done by executing a fragment shader program on the GPU.
  The shader is written in GLSL and generated by the Geometry Compiler.
* When a shape is exported to a mesh file (eg, an STL file)
  using the ``-Ojit`` option, the shape's distance function is
  compiled into C++ code by the Geometry Compiler, which is then compiled
  into optimized machine code and run on the CPU.

Curv is a dynamically typed language, but the Geometry Compiler only accepts a
statically typed subset of Curv. If you write your own ``dist`` and ``colour``
functions from scratch, you may get error messages from the Geometry Compiler,
indicating that your code uses constructs that are outside of the supported
subset. Curv is a work in progress: the subset of Curv supported by the
Geometry Compiler will grow from release to release.

The Geometry Compiler uses bottom-up type inference to infer static types
for each expression in a ``dist`` or ``colour`` function.
The following data types are supported:

* **bool**, a boolean value (true or false).
* **number**, a 32 bit floating point number.
* **vec2**, a list of 2 numbers, eg [0,1].
* **vec3**, a list of 3 numbers, eg [0,1,2].
* **vec4**, a list of 4 numbers, eg [0,1,2,3].
* **Large arrays**, which are rectangular, multi-dimensional arrays of numbers.
  We specifically support 1-D and 2-D arrays of number,
  vec2, vec3 and vec4. This support is still experimental.
  Large arrays are compile time constants: their contents cannot depend on
  the (x,y,z,t) arguments of ``dist`` and ``colour`` functions, and also
  cannot depend on shape parameters within a parametric shape, if those
  parameters are bound to a value picker.

Recursive function calls are not supported.
