# Extra Terrestial Engine

Space sim focused engine created from a merge of:
 * my [OpenGL Framework](https://github.com/Illation/GLFramework)
 * my [Planet Renderer](https://github.com/Illation/PlanetRenderer)
 
__Full feature list and backlog here: [LINK](doc/features.md)__

## Build Status

| Service | System | Compiler | Branch | Status |
| ------- | ------ | -------- | ------ | ------ |
| [AppVeyor](https://ci.appveyor.com/project/Illation/etengine)| Windows 64 | Visual Studio 2017 | master | [![AppVeyor](https://ci.appveyor.com/api/projects/status/jsr44exh2l0y5gs6/branch/master?svg=true)](https://ci.appveyor.com/project/Illation/etengine)

## How to build

For visual studio 2017:

    cd Projects/Demo
    cmake -G "Visual Studio 15 2017 Win64" -H. -Bbuild
    cmake --build build --target all --config Develop
	cmake --build build --target install
	cmake --build build --target cook-installed-resources-EtEngineDemo

For more information (including unit tests and content cooking) check [the build documentation](doc/building.md).

 
## Third Party

For a list of third party libraries and licenses check [HERE](Engine/third_party/Readme.md).

## Screenshots

#### WIP Editor
![](./screenshots/Editor.jpg)
#### Atmosphere
Atmospheric Perspective
![](./screenshots/GroundAtmosphere.jpg)
Upper Atmosphere
![](./screenshots/UpperAtmosphere.jpg)
#### Planets
From Space
![](./screenshots/FamiliarView.jpg)
Surface view
![](./screenshots/Surface.jpg)
#### Render Pipeline
PBR and IBL
![](./screenshots/PBR.jpg)
Experimental CSM and SSR
![](./screenshots/Lighting.jpg)
2500 Lights with deferred rendering and Bloom
![](./screenshots/DeferredBloom.jpg)
#### Physics
![](./screenshots/BulletPhysics.jpg)
#### Star fields
![](./screenshots/MoarStars.jpg)
![](./screenshots/Stars.jpg)
#### Moar Screenshots
![](./screenshots/Crescent.jpg)
![](./screenshots/FromSpace.jpg)
