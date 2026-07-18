### CairoPlot - Plotting with Cairo and GTKMM4

<img src="assets/logo.png">

> [!NOTE]
> This is a fork of CairoPlot written by [AlexB67](https://github.com/AlexB67).
> We intend to only maintain the gtkmm4 version,
> if you still would like to use the gtkmm3 version please use the original [cairoplot-gtkmm3 branch](https://github.com/AlexB67/CairoPlot/tree/cairoplot-gtkmm3).

CairoPlot is a small library to make 2D static and animated Plots in gtkmm4 applications. It is used in [TCalc](https://github.com/AlexB67/TCalc). This is a small demo of what can de done with gtkmm and cairomm.

#### Static plots

<img src="assets/screenshots/cairo-multiple-graphs.png">

#### Animated plots

<img src="assets/screenshots/cairograph-demo.png">

### Requirements

For building the demo following packages are required.

```
* git
* gettext
* appstream-util
* gtkmm 4.0.2 or greater development libraries
* meson
* Nimbus Roman font family // for TeX like appearance
* ninja build system
```

Consult/search your distribution for the above packages and install them if required. in Fedora 35 it would typically involve

```
sudo dnf install gtkmm4-devel
sudo dnf appstream-util
sudo dnf gettext
```

If in doubt use dnf search to find them

```
dnf search gtkmm
dnf search appstream
dnf search nimbus
```

etc. On Ubuntu based system use apt to obtain the relevant packages.

### Building the software

```
git clone https://github.com/AlexB67/CairoPlot.git
$cd CairoPlot
$mkdir build
$meson build/
$cd build
$ninja
```

You can run the demo from the build directory with the command

```
cd to build_dir # i.e. path to your build directory
src/cairoplot
```

Installation is not required.

### Supported features

Multiple and single plots are supported in a single graph.
With a little work Wolfram Mathematica Manipulate/Animate style plots can also be produced. See the source code for details. The demo exposes most features. My TCalc respository shows additional use cases.

### Using the library in your project

#### As a github submodule

Add the repository as a submodule

```
git submodule add https://github.com/realstealthninja/carioplot subprojects/cairoplot
```

Then in your meson build file

```py
deps = [
    ...
    dependency('libcairoplot', fallback: ['libcairoplot', 'libcairoplot_dep'])
    ...
]
```

#### Using meson wrap

in subprojects/libcairoplot.wrap

```ini
[wrap-git]
url = https://github.com/realstealthninja/cairoplot.git
revision = HEAD
depth = 1
```

then in your meson.build

```py
deps = [
    ...
    dependency('libcairoplot')
    ...
]
```

Enjoy.
