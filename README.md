![Explodable](http://i.imgur.com/2F0w1IU.png)
==========

A C++ engine that uses SFML. Made for use in LD29. Logo created by [JordanFitz](http://jordanfitz.com).

Requirements
==========

Explodable uses SFML 2.1, which you can get [here](http://www.sfml-dev.org/download.php "SFML 2.1 downloads."). It also includes a Visual Studio 2012 project file, but you do not need to have that in order to work on the engine.

In order to use, you must include the following DLL's where the executable of your game using Explodable and SFML is. These DLL's are included with SFML, so get them from the download site.

```
  libsndfile-1.dll
  openal32.dll
  sfml-audio-2.dll
  sfml-audio-d-2.dll
  sfml-graphics-2.dll
  sfml-graphics-d-2.dll
  sfml-system-2.dll
  sfml-system-d-2.dll
  sfml-window-2.dll
  sfml-window-d-2.dll
```

Only include the DLL's with -d if you are using the debug libs from SFML.

Use
==========

Explodable was written in Visual Studio, therefore, I've included the Visual Studio project files. Meaning you should be able to just open the sln file to get started. (I haven't tested this so it may not work). You might also have to use VS Express 2012, but I have no clue if that is true.
