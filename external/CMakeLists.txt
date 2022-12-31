FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)
set(JSON_BuildTests OFF CACHE INTERNAL "")

set(BOOST_INCLUDE_LIBRARIES thread system bind asio) #  filesystem  program_options
set(BOOST_ENABLE_CMAKE ON)

FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.81.0
)
FetchContent_MakeAvailable(Boost)
