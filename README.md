Simple Example for C++ project with Conan using SDL and Box2d in Xcode
----------------------------------------------------------------------

Install [Conan](https://github.com/conan-io/conan) in a virtual environment and:

```bash
conan install . -s build_type=Release --build=missing
conan install . -s build_type=Debug --build=missing
```

Add xcconfig files generated in conan folder to the Xcode project. Check instructions [here](https://blog.conan.io/2022/03/17/New-conan-release-1-46.html).

Select `conan_config.xcconfig` as config for both configurations.

Build the project in Xcode