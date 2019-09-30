set(BlackboxExampleName_Intro ${BlackboxProjectName}_example_intro)
project(${BlackboxExampleName_Intro})
add_executable(${BlackboxExampleName_Intro}
	intro.cpp
)
target_link_libraries(${BlackboxExampleName_Intro} ${BlackboxLibraryName})