cmake_minimum_required(VERSION 3.13)
project(cos214)

set(CMAKE_CXX_STANDARD 17)

add_executable(cos214 src/Aerodynamics.cpp
        src/AeroFactory.cpp
        src/AeroPart.cpp
        src/Builder.cpp
        src/Chassis.cpp
        src/ChassisFactory.cpp
        src/ChassisPart.cpp
        src/Electronics.cpp
        src/ElectronicsFactory.cpp
        src/ElectronicsPart.cpp
        src/Engine.cpp
        src/Engineering.cpp
        src/EngineFactory.cpp
        src/EnginePart.cpp
        src/F1Builder.cpp
        src/F1Car.cpp
        src/Part.cpp
        src/PartsFactory.cpp
        src/RaceBuilderDir.cpp
        src/ResearchAndDevelopmentDepartment.cpp
        src/TestBuilderDir.cpp
        src/Director.cpp
        include/Aerodynamics.h
        include/AeroFactory.h
        include/AeroPart.h
        include/Builder.h
        include/Chassis.h
        include/ChassisFactory.h
        include/ChassisPart.h
        include/Electronics.h
        include/ElectronicsFactory.h
        include/ElectronicsPart.h
        include/Engine.h
        include/Engineering.h
        include/EngineFactory.h
        include/EnginePart.h
        include/F1Builder.h
        include/F1Car.h
        include/Part.h
        include/PartsFactory.h
        include/RaceBuilderDir.h
        include/ResearchAndDevelopmentDepartment.h
        include/TestBuilderDir.h
        include/Director.h)