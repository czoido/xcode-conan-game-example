import os

from conan import ConanFile

class GameExample(ConanFile):
    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    generators = "XcodeDeps", "XcodeToolchain"

    def requirements(self):
        self.requires("sdl/2.0.20")
        self.requires("sdl_image/2.0.5")
        self.requires("box2d/2.4.1")
        self.requires("cli11/2.1.2")
        self.requires("fmt/8.1.1")
        self.requires("tinkerforge-bindings/2.1.32")

    def layout(self):
        self.folders.build = "build"
        self.folders.generators = "conan"
