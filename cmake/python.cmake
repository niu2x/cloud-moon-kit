macro(add_python_module target)

    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

    Python3_add_library(${target} SHARED "")
    cxx_project_preset(${target})

    target_link_libraries(${target} PRIVATE
        pybind11::headers
        Python3::Python
    )

    set_target_properties(${target} PROPERTIES
        PREFIX "${PYTHON_MODULE_PREFIX}"
        DEBUG_POSTFIX "${PYTHON_MODULE_DEBUG_POSTFIX}"
        SUFFIX "${PYTHON_MODULE_EXTENSION}"
    )
endmacro()
