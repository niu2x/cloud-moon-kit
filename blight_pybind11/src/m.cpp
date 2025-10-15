#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <boost/predef.h>

#include <yy/blight.h>

namespace py = pybind11;

PYBIND11_MODULE(blight_cxx, m) {
    m.doc() = "blight_cxx";

#if BOOST_OS_LINUX
    auto m_linux = m.def_submodule("linux", "Linux Utility");
    // 在子模块中添加方法
    m_linux.def("so_inject", [](pid_t pid, const std::string& so_path) {
        yy::blight::linux::so_inject(pid, so_path);
    });
#endif
}
