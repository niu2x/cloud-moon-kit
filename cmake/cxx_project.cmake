include(warning_as_error)

function(cxx_project_preset)
    foreach(target IN ITEMS ${ARGN})
        set_target_properties(${target} PROPERTIES 
            CXX_STANDARD 20
            C_VISIBILITY_PRESET hidden
            CXX_VISIBILITY_PRESET hidden
            VISIBILITY_INLINES_HIDDEN ON
            POSITION_INDEPENDENT_CODE ON
            CXX_STANDARD_REQUIRED ON
            CXX_EXTENSIONS OFF
        )

        if(MSVC)
            target_compile_definitions(${target} PUBLIC UNICODE _UNICODE)
            target_compile_options(${target} PUBLIC
                "$<$<C_COMPILER_ID:MSVC>:/utf-8>"
                "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>"
            )
        endif()

        # warning_as_error_enable(${target})
        
    endforeach()
endfunction()

function(cxx_components_project_preset)
    foreach(target IN ITEMS ${ARGN})
        cxx_project_preset(${target})
        target_include_directories(${target} PRIVATE
            ../../main/include
        )
    endforeach()
endfunction()
