# Install script for directory: C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects" TYPE FILE FILES
    "UAV.cpp.obj"
    "UAV_data.cpp.obj"
    FILES_FROM_DIR "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/CMakeFiles/UAV_objects.dir/./")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/UAV.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export" TYPE FILE FILES "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/UAV.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets.cmake"
         "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/CMakeFiles/Export/b4ade2d1b88064d160a7a3998ad23128/UAVTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export" TYPE FILE FILES "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/CMakeFiles/Export/b4ade2d1b88064d160a7a3998ad23128/UAVTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export" TYPE FILE FILES "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/CMakeFiles/Export/b4ade2d1b88064d160a7a3998ad23128/UAVTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/soure/Desktop/Uni Sachen/CT-Verification/Possible Controller/Implementation/UAV/UAV_grt_rtw/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
