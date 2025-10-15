import sys
import subprocess
import pathlib
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

class CMakeBuildExt(build_ext):
    def build_extension(self, ext):
        extdir = pathlib.Path(self.get_ext_fullpath(ext.name)).parent.absolute()
        build_temp = pathlib.Path(self.build_temp)
        build_temp.mkdir(parents=True, exist_ok=True)

        subprocess.check_call([
            "cmake",
            "-S", "..",
            "-B", str(build_temp),
            f"-DPython3_EXECUTABLE={sys.executable}",
            f"-DCMAKE_BUILD_TYPE=Release",
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE={extdir}",
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}",
            f"-DCMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE={extdir}",
            f"-DCMAKE_RUNTIME_OUTPUT_DIRECTORY={extdir}",
        ])
        subprocess.check_call([
            "cmake", "--build", str(build_temp), 
            '--target', 'blight_cxx',
            '--config', 'Release',
        ])

setup(
    packages = ["blight"],
    package_dir = {"": "src"},
    ext_modules=[Extension("blight_cxx", sources=[])],
    cmdclass={"build_ext": CMakeBuildExt},
)