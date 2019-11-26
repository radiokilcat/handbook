add_executable( ${PROJECT_NAME} main.cpp book.cpp book.hpp )

TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${Boost_LIBRARIES} )

