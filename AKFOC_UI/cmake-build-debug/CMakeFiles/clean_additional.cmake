# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AKFOC_UI_autogen"
  "CMakeFiles\\AKFOC_UI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AKFOC_UI_autogen.dir\\ParseCache.txt"
  )
endif()
