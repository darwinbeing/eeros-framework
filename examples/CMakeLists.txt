include_directories(${EEROS_SOURCE_DIR}/includes ${EEROS_BINARY_DIR})

add_subdirectory(sequencer)

add_subdirectory(safety)

if(LIBCOMEDI)
#	add_subdirectory(simpleMotorController)
endif()

if(LIBFLINK)
#	add_subdirectory(flink)
endif()
