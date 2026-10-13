set problem="route"
set grader_name="grader"

g++ -std=gnu++17 -Wall -O2 -pipe -static -g -o %problem% %grader_name%.cpp %problem%.cpp || (echo "g++ is probably not installed. Please install using MinGW or Cygnus. See https://gurucodes.dev/learn/introduction-to-programming/installation-gcc-compiler/")
