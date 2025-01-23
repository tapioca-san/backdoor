cmake_minimum_required(VERSION 3.16)

set(CMAKE_SYSTEM_NAME Windows)

# Indica o prefixo para o compilador do MinGW
set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)

project(VIRUS LANGUAGES CXX)

# Incluir diretórios das dependências
include_directories(${CMAKE_SOURCE_DIR}/dep/DPP/include)
include_directories(${CMAKE_SOURCE_DIR}/dep/curl/include)

# Incluir diretórios específicos do MinGW
include_directories(/usr/i686-w64-mingw32/include)

link_directories(${CMAKE_SOURCE_DIR}/dep/DPP/lib)
link_directories(${CMAKE_SOURCE_DIR}/dep/curl/lib)

# Adicionar o executável principal
add_executable(${PROJECT_NAME} main.cpp network.cpp)

# Vincular as bibliotecas necessárias
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES} dpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
