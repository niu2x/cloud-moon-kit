UNAME_S := $(shell uname -s)
# 根据平台获取 CPU 核心数
ifeq ($(UNAME_S),Darwin)
	NUM_CORES := $(shell sysctl -n hw.ncpu)
else
	NUM_CORES := $(shell nproc)
endif

core_jobs := $(shell expr $(NUM_CORES) - 1)
# core_jobs := ""


release:
	cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release
	cmake --build build --config Release -j $(core_jobs)

debug:
	cmake -S. -Bbuild/debug -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/debug --config Debug -j $(core_jobs)